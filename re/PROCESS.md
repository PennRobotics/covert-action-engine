# Invasive Debugging

## COVERT.EXE

* Enable **dosbox-x** debugger (by starting in a console with the debugger enabled in the menu)
* Set speed to 1 cycle/ms
* Run `COVERT.EXE` and immediately press the debugger hotkey.
* Step until the entry is found. It can be recognized from its disassembly as it begins with `mov ah,30` and `int 21`, which are the instructions to get the DOS version, and are shortly followed by `int 20`, which exits if the DOS version is too low.
* With breakpoint placed, set speed back to default.

```text
EAX=00000000  ESI=000001F4  DS=0813   ES=0813   FS=0000   GS=0000   SS=0CD8 Real
EBX=00000000  EDI=00000800  CS=0823   EIP=000001F4   C0 Z0 S0 O0 A0 P0 D0 I1 T0
ECX=000000FF  EBP=0000091C                                     NOPG  IOPL3  CPL0
EDX=00000813  ESP=00000800                                   100193314
```

I then step to the next `int 21`, which has **AH = 0x4A** (indicating a _memory resize_ operation), **BX = 0x118A** (new size in paragraphs), and **ES = 0x0813** (block segment to resize). This succeeds, we step a bit more---one or two dozen operations---until `repe stosb`, which seems to be `memset(*(void*)0x4B2,0,0x33B0);`, or setting much of **segment 0x099d** to zero (This same segment starts with `\0\0\0\0\0\0\0\0MS Run-Time Library - Copyright (c) 1988, Microsoft Corp<0x11>\0game.exe\0tac.exe\0code.exe`...)

`call 0x2a6` leads to the next interrupts, `int 21` with **AH = 0x30** again (dos version) which is then stored in memory, followed by `int 21` with **AX = 3500** (get interrupt vector) which returns **ES = 0xF000** and **BX = 0xCA60**. The data segment is changed, `int 21` (**AX 0x2500**, **DX 0x0288**: set interrupt 0h to 0823:0288). Then it seems there's a bit of heap activity that probably occurred after `call 00000602`, but I frankly have no idea and started to really accelerate while stepping through.

Running `call 00000474` is evidently `strcmp` implemented using the command `repne scasb`. This is reading the environmental variables, since 07ca:0000 (ES:EDI) begins with `COMSPEC=Z:\COMMAND.COM\0PATH=Z:\;Z:\SYSTEM`...) and seems to stop with a pointer to `C:\COVERT\COVERT.EXE`, which looks like it could be the first argument into **argv**. I kinda skipped along again until what felt like the next major change, 0823:0273:

```asm
xor bp,bp
push word [0x033A]
push word [0x0338]
push word [0x0336]
call 0x00000010
push ax
call 0x0000036A
```

(It turned out not to be significant at all, yet.)

This pushed 3BAE, 3B94, 1 and called 0x10, which then loaded 04C0 and 099D into 0000:04F0 and 0000:04F2. Lots more pushing: 0, 0, E3, E4, 0; then, a `call 00000F0E` which eventually did more environmental variable work.

Pushing ahead to a `call 000008D2` (or `call 000008F4` (or `call 914` (or `call 982`)))... I then decided to hold F11 until something significant occurred. There was a lot more environmental variable processing (sound blaster values, etc.) and then a `(F000:D10B) loop 0000D10B` which lasted a few hundred cycles, and a few instructions later, `int 21` (**AH 4B**: ... _exec_)

Cool. At this point, there were still no changes on the MS-DOS window. DS:DX shows `intro.exe` and ES:BX:

```text
0D61 099D3ADC 09A10356 09A10366
```

... which is the segment of environment to copy for the child process, pointer to command tail (copied into PSP), pointer to first FCB (into PSP), and second FCB pointer (into PSP).

After running the `callback 0038  (DOS Int 21)` line, the register view showed most of the contents had changed:

```text
EAX=00000000  ESI=000007BE  DS=19E9   ES=19E9   FS=0000   GS=0000   SS=1BA9 Real
EBX=00000000  EDI=00000800  CS=F000   EIP=0000D106   C0 Z0 S0 O0 A0 P0 D0 I1 T0
ECX=000000FF  EBP=0000091C                                     NOPG  IOPL3  CPL0
EDX=000019E9  ESP=000007FC                                   100209055
```

(**ESP** became 800 and **CS** 19F9 after the interrupt returned.)


## INTRO.EXE

Now, at 19F9:07BE, again is `int 21` (**AH 30**) and a resize memory block and another `repe stosb`. So, I hold down F11 until something happens... And at 19F9:0C16, I take a look at ES:SI, and there are the strings that are going to be copied to the screen: VGA, MCGA, "Shhh! No sounds please." I skip along until `int 10` (**AX 0920**: _write character_ to page "0" with attribute 4Fh). With a couple of breakpoints at 19F9:07A0 and 19F9:07A3, we finally witness the I/O selection menu!!

(Phew! That was exhausting and still just the tip of the iceberg!!)

-----

As the graphics is undoubtedly going to be a pain---the animations seem to be compressed, indexed, and probably containing P- or B-frames---I selected _continue_ until the first selection menu. At this point, the program is waiting for the user to select from a menu. The memory segments being used are:

| Segment | Guess |
| ------- | ----- |
|  1CBE   | check for keystroke |
|  214C   | function redirects |
|  224C   | main loop? |
|  F000   | keyboard handler |

These are being cycled through _while nothing is happening_ (animations, user input).

```asm
int  0x16
je   0x00000055 ($+3)
sub  ax,ax
retf
sub  ax,ax
not  ax
retf
```

The top `retf` executes when a key is pressed. The other executes when no key is pressed. It seems each keystroke will cause a stop at the breakpoint twice.

| Segment | Guess |
| ------- | ----- |
|  199E   | Drawing |

There's a lot of `stosb` after reaching 199E that copies non-text data. Maybe that's a graphics-related segment? In any case, it takes a few _continue_ commands to update a screen after setting a breakpoint at 199E:015B. Setting at 199E:0180? That seems to be the exit point for the draw sequence. (The machine code at this point is `EF 07 1F 5F 5E 5D CB`.)

-----

I skipped ahead to the chief. The first time through, I should have looked closer for the transition between new character and chief, since that should contain all the logic for building the case and all agent details. At 224C:C0AC, the value stored at ss:[BB22] is decremented. When it finally reaches zero, a few instructions later there is `call FFFFC42A`. Not long after, there's a nop loop at F000:0000CA45. Eventually, pushed onto the stack are 5, 0xC8, 0x140, 0, 0, 0x4B46... notably 0xC8 and 0x140 are 200 and 320, which is the screen resolution for this program. At 224C:074F, there is a call to 214C:0602. A few lines later... `mov  word [AC1C],0000`. Dumping that address (ds:AC1C, or 3224:AC1C) we see: `\0\0\0\0Blueprints\0\0\0\0\0\0\0\0Alarm Bypass\0\0\0`... **_CLUE DATA!!!_**

During the chief animation, by placing a breakpoint at 224C:C09E and data dump at A000:0FD0, you can see the mapping between pixel data.

### Faces

The face generator can be caught in action by breaking at 199E:0180. Here, each face appears half-populated before being completed at the next halt. It might be a bald head with only a pair of lips or a head with masked facial hair and no other hair or even half a head.

## BUG.EXE

| Segment | Guess |
| ------- | ----- |
|  2234   |   ?   |

By placing a breakpoint at 2234:6F1E, one `go`--`break` cycle will update the animation by one frame. There is a lot contained in this segment.


## Others

The crypto game happens in segment 2200. Driving is at 222B. Combat at 2234 (same as BUG.EXE). Clue uses at least segment 2243 (and the key handler and redirect segments). Save/load dialog happens in F000.


# Mapping DOS Addresses to Decompiled Functions

     !!! TODO !!!

_This is the biggest obstacle to a more efficient workflow!_
Refer to https://wiki.scummvm.org/index.php/HOWTO-Reverse_Engineering#From_IDA_to_the_Debugger


# Decompiler Analysis

     !!! TODO !!!
