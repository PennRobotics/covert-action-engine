Covert Action Engine
====================

This is a clone of the engine for the MPS Labs game, _Covert Action_.

The plan is to develop tools for extracting package data from the original game folder for conversion to an open format. The majority of string data are stored in the executable while picture and animation data are found in self-contained files. There are discussions on the internet about the exact nature of some of the data files. For all else, the DOSBox-X debugger and a good disassembler/decompiler would provide insight into the game's inner workings (random number engine, animation method, combat accuracy calculation, etc.)

Bases for the development of the engine are the source codes for Freeciv, Master of Orion, C-Dogs SDL, SDLPop (Prince of Persia), cc94 and FreeCol (Colonization), Crown and Cutlass (Pirates!), GE211 by Jesse A. Tov, flat by Linus Probert, Cataclysm-DDA, SuperTux, and devilutionX. These other projects provide guidance in the form of folder/header/object structure, memory management, build technique, data manipulation, object interaction, and ideal layout of SDL calls.

### BEST IDENTIFIED BLOCKER-BREAKER

  -- Create the entire state machine that advances to the next default on any keypress --

### SECOND PRIORITY

  -- Create input parsers for most of the data files --

### THIRD PRIORITY

  -- Allow up-down menu selection: enter/escape returns correct index --

### FOURTH PRIORITY

  -- Preprocessor macro PLACEHOLDERS should replace all graphics calls --


## TODO

### Overview

- [ ] Remove redundancies in/between the TODO sub-lists
- [x] Change name of project but also all references e.g. BUILD.md URL
- [ ] Documentation
- [ ] Font
  - [x] Imported
  - [ ] Inline
- [ ] Sound
  - [x] Proof-of-concept
  - [ ] Background music
  - [ ] Sound Effects
- [ ] Complete the state machine
- [ ] Menu system
  - [x] Proof-of-concept
  - [ ] Generic up-down
  - [ ] Skill left-right
  - [ ] Face selection
  - [ ] Entry kit selection
- [ ] Case Data
  - [ ] Clues
  - [ ] Evidence
  - [ ] Mentions
- [ ] Settings file
  - [ ] Granular randomization (allow easy adjustments to each random assignment until original engine can be reversed)
  - [ ] "Into Hiding" criteria
  - [ ] Scan info revealed (Hotel, Local, International)
  - [ ] Accuracies
  - [ ] Combat AI settings
- [ ] Campaign
  - [ ] Masterminds captured
  - [ ] Current rank and skillset
  - [ ] Score
- [ ] Time Tracker
- [ ] Define connections between each screen
- [ ] Hotel
- [ ] Intelligence HQ
- [ ] Cryptography minigame
- [ ] Electronics minigame
- [ ] Building exterior
- [ ] Car chase minigame
- [ ] Combat minigame
  - [ ] Terminal password list
- [ ] Name and face generator
- [ ] Room generator
  - Are the rooms/layouts truly random or in any way predictable?
- [ ] Determine when each participant goes into hiding
- [ ] (not for public release) Strip MIDI/Roland and record with HD soundfont
- [ ] (not for public release) Get sprite/picture data from executables, if any exist here
- [ ] (stretch goal) Localization
- [ ] Graphics
  - [x] Placeholder proof-of-concept
  - [ ] Placeholder intercepts calls to each draw function
  - [ ] Implement draw function for _.png_
  - [ ] Implement draw function for _.pic_
  - [ ] Implement draw function for _.pan_
  - [ ] (stretch goal) Ensure best use of memory and support for GPU/software rendering
  - [ ] (stretch goal) Replace raster graphics with vector graphics
- [ ] Create various combat AIs

### Implementation

- [x] remove duplicated (and old) files from directory structure
- [x] `#pragma once` rather than include guards
- [ ] single random generator
- [ ] only `#include` what is needed, and use a better order: own header, project header, third-party, system
- [ ] nearly completely separate out the various subsystems so they can be selectively replaced e.g. GUI with console interaction
- [ ] `const` wherever possible
- [ ] `volatile` where needed
- [ ] fix access and scope (`static`, `public:`, `private:`, `protected:`)
- [ ] think about `default`, `delete`, `override`/`virtual`
- [ ] singletons? A good struct only called once?
  - Need one and only one main character
  - Need one and only one game state
  - Need one and only one renderer/window
  - Need one and only one keymap
- [ ] does it make the most sense for the state machine and GUI generator to have a few functions with named arguments?
- [ ] figure out why test sometimes throws a segmentation fault (custom types being cast? actual memory allocation/call order problems?)
- [ ] does every function have a reasonable return type? reference vs move vs copy?
- [ ] `static_cast`, `const_cast`, `reinterpret_cast`... you get the drill
- [ ] should there be separate event loops for minigame and main game?
- [ ] what is the best SDL_Mixer practice?
- [ ] how should **CMake**, **configure**, **Makefile**, **meson**/**ninja**, or any other build tool be best implemented?

### Porting

- [ ] figure out all of the different types of GUI elements and keyboard entry modes: free text, up/down menu, pic selection, "any key", etc.
- [ ] implement PIC and PANO decoders
- [ ] map original memory transfer regions (between EXEs)
- [ ] NPC movement algorithms during minigames
- [ ] what is randomizable in the face/body generator?
- [ ] Main character statistics
  - [ ] Global Difficulty, Skill Modifiers
  - [ ] Character Level
- [ ] Room Generation (Combat)
  - [ ] Bug details
  - [ ] Password chart
  - [ ] Modification for ambush, break-out, etc.
- [ ] HQ
  - [ ] Intelligence Menu
  - [ ] Surveillance
  - [ ] Clues
  - [ ] Activity reports
  - [ ] Agent states
- [ ] Populate all possible messages (or generative phrases)
- [ ] Hotel
  - [ ] Gossip
- [ ] Building Exteriors
- [ ] Clock
- [ ] Airport
  - [ ] World map
- [ ] Mission
  - [ ] Participant organizational chart
  - [ ] Debrief
  - [ ] Scoring
  - [ ] Loading from data files
  - [ ] Save / Load functionality?
- [ ] User Interface
  - [ ] Menus, easily implemented
  - [ ] Graphics / Picture display / Fonts / # colors
  - [ ] Sound
  - [ ] Input devices
- [ ] Error Handling
- [ ] Cross-Platform

### Specific Code

- [ ] comingFrom (try to make this automatically defined)
- [ ] nextscreen is probably not needed. directly assign the next screen based on provided condition argument
- [ ] generate *n* double agents
- [ ] add remaining original font glyphs
- [ ] remove debug-related inheritance (used for testing Singleton instantiation and access)
  - [ ] **covert.cpp** should not include **combat.h**
  - [ ] **cryptography.cpp** should not include **combat.h**
- [ ] Building1, Building2, etc. should just be Building with building type passed as an enum (simplifies menu creation and screen back-reference)

### Still Missing

- [ ] load existing file (This should dictate much of the variable/class structure!)
- [ ] keyboard mapper / configuration file
- [ ] folder display showing org/city activity (okay if it is a very flawed algorithm at the beginning)
- [ ] font (if error during load, use an internal array; possibly switch to _only_ internal going forward)
  - It might be wise to see how other SDL2 projects accomplish this.

### Ideas

*These are some stretch goals, but these are not active until the project is fully on track to be complete*

- [ ] localization: French, German, Italian, Portuguese, Spanish
- [ ] add ENHANCEMENTS and FIX_ORIGINAL macros early, so these can be selectively (and independently) activated during build
- [ ] creating a legal .ogg/.mp3 of the theme music using the original Roland MT-32 sounds (or a very convincing Soundfont with the original MIDI)
- [ ] converting low-res sprites to vector representations or high-res, high-frame-rate sprites or model-generated objects
- [ ] 3d display of airport scene
- [ ] 3d replay of the 2d minigame (it would probably be cool to do realtime 3d, but this might not be playable because of visibility differences between 2d and 3d, and developing a renderer and models for 3d would be extremely time consuming.)
- [ ] improve the engine's state machine and case generators to be a more readable, script-driven format
- [ ] fix bugs in the original program
- [ ] localization (non-Latin): Arabic, Chinese, Hebrew, Japanese, Korean, Russian
- [ ] (F. Bouthillier) Enable mouse/touch on electronics game
- [ ] (F. Bouthillier) Add random NPC traffic to driving game
- [ ] (F. Bouthillier) Allow driving as an interceptor as part of the __Tailed Victim__ role
- [ ] (F. Bouthillier) NPCs have more than one health
- [ ] (F. Bouthillier) Agents move inside house, possibly with bodyguard
- [ ] (F. Bouthillier) Accurate mission movement of character e.g. agent gets up to leave for meeting, can be followed, meets with other agent, etc.
- [ ] (F. Bouthillier) Better furniture layouts
- [ ] (F. Bouthillier) Safecracking mini-minigame
- [ ] (F. Bouthillier) Surveillance cameras inside buildings (interacts with Electronics skill)
- [ ] (F. Bouthillier) Main character starts outside building and enters at own convenience


## Build Warnings and Messages 

### Clang Error

```
./src/sound/music.cpp:16:31: warning: format specifies type 'long long' but the argument has type 'uint64_t' (aka 'unsigned long') [-Wformat]
  fprintf(stdout, "AB%lld\n", (uint64_t) wave[0]);
                     ~~~~     ^~~~~~~~~~~~~~~~~~
                     %lu
1 warning generated.
./src/gui/gui.cpp:100:20: error: no matching constructor for initialization of 'SDL_Point'
  drawText(c, txt, SDL_Point((SCREEN_WIDTH - w) >> 1, y));
                   ^         ~~~~~~~~~~~~~~~~~~~~~~~~~~
/usr/include/SDL2/SDL_rect.h:48:16: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 2 were provided
typedef struct SDL_Point
               ^
/usr/include/SDL2/SDL_rect.h:48:16: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 2 were provided
/usr/include/SDL2/SDL_rect.h:48:16: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 2 were provided
./src/gui/gui.cpp:139:7: error: use of undeclared identifier '_imagePlaceholder'
      _imagePlaceholder(15, 5, 20, 15);
      ^
./src/gui/gui.cpp:141:31: error: no matching constructor for initialization of 'SDL_Rect'
      drawBox(CAColor::WHITE, SDL_Rect(97, 76, 125, 46));
                              ^        ~~~~~~~~~~~~~~~
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 4 were provided
typedef struct SDL_Rect
               ^
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 4 were provided
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 4 were provided
./src/gui/gui.cpp:142:53: error: no matching constructor for initialization of 'SDL_Point'
      drawText(CAColor::WHITE, "Do you want to...", SDL_Point(102, 80));
                                                    ^         ~~~~~~~
/usr/include/SDL2/SDL_rect.h:48:16: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 2 were provided
typedef struct SDL_Point
               ^
/usr/include/SDL2/SDL_rect.h:48:16: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 2 were provided
/usr/include/SDL2/SDL_rect.h:48:16: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 2 were provided
./src/gui/gui.cpp:146:34: error: no matching constructor for initialization of 'SDL_Rect'
      updateGUIMenu(currentMenu, SDL_Rect(102, 88, 115, 1));
                                 ^        ~~~~~~~~~~~~~~~
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 4 were provided
typedef struct SDL_Rect
               ^
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 4 were provided
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 4 were provided
./src/gui/gui.cpp:215:32: error: no matching constructor for initialization of 'SDL_Rect'
      fillBox(CAColor::YELLOW, SDL_Rect(pt.x, pt.y, r0.w, 8));
                               ^        ~~~~~~~~~~~~~~~~~~~
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 4 were provided
typedef struct SDL_Rect
               ^
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 4 were provided
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 4 were provided
./src/gui/gui.cpp:229:32: error: no matching constructor for initialization of 'SDL_Rect'
      fillBox(CAColor::YELLOW, SDL_Rect(pt.x, pt.y, r0.w, 8));
                               ^        ~~~~~~~~~~~~~~~~~~~
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 4 were provided
typedef struct SDL_Rect
               ^
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 4 were provided
/usr/include/SDL2/SDL_rect.h:78:16: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 4 were provided
7 errors generated.
make: *** [Makefile:94: all] Error 2
```

### Visual Studio Errors

| Severity | Code | Description | File | Line |
| -------- | ---- | ----------- | ---- | ---- |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C4100 | 'argv': unreferenced formal parameter | src\main.cpp | 7 |
| Warning | C4100 | 'argc': unreferenced formal parameter | src\main.cpp | 7 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C4464 | relative include path contains '..' | src\gameplay\gamestate.h | 5 |
| Warning | C4820 | 'SDL_AssertData': '4' bytes padding added after data member 'SDL_AssertData::linenum' | SDL2-2.24.0\include\SDL_assert.h | 124 |
| Warning | C4820 | 'SDL_RWops::<unnamed-tag>': '4' bytes padding added after data member 'SDL_RWops::<unnamed-tag>::append' | SDL2-2.24.0\include\SDL_rwops.h | 105 |
| Warning | C4820 | 'SDL_RWops': '4' bytes padding added after data member 'SDL_RWops::type' | SDL2-2.24.0\include\SDL_rwops.h | 133 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::len_mult' | SDL2-2.24.0\include\SDL_audio.h | 241 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::filter_index' | SDL2-2.24.0\include\SDL_audio.h | 244 |
| Warning | C4820 | 'SDL_Palette': '4' bytes padding added after data member 'SDL_Palette::ncolors' | SDL2-2.24.0\include\SDL_pixels.h | 321 |
| Warning | C4820 | 'SDL_PixelFormat': '4' bytes padding added after data member 'SDL_PixelFormat::format' | SDL2-2.24.0\include\SDL_pixels.h | 332 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::flags' | SDL2-2.24.0\include\SDL_surface.h | 75 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::pitch' | SDL2-2.24.0\include\SDL_surface.h | 78 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::locked' | SDL2-2.24.0\include\SDL_surface.h | 87 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::refcount' | SDL2-2.24.0\include\SDL_surface.h | 97 |
| Warning | C4820 | 'SDL_Keysym': '2' bytes padding added after data member 'SDL_Keysym::mod' | SDL2-2.24.0\include\SDL_keyboard.h | 52 |
| Warning | C4820 | 'SDL_Finger': '4' bytes padding added after data member 'SDL_Finger::pressure' | SDL2-2.24.0\include\SDL_touch.h | 58 |
| Warning | C4820 | 'SDL_TextEditingExtEvent': '4' bytes padding added after data member 'SDL_TextEditingExtEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 257 |
| Warning | C4820 | 'SDL_MultiGestureEvent': '4' bytes padding added after data member 'SDL_MultiGestureEvent::padding' | SDL2-2.24.0\include\SDL_events.h | 526 |
| Warning | C4820 | 'SDL_DropEvent': '4' bytes padding added after data member 'SDL_DropEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 556 |
| Warning | C4820 | 'SDL_HapticDirection': '3' bytes padding added after data member 'SDL_HapticDirection::type' | SDL2-2.24.0\include\SDL_haptic.h | 462 |
| Warning | C4820 | 'SDL_HapticConstant': '2' bytes padding added after data member 'SDL_HapticConstant::type' | SDL2-2.24.0\include\SDL_haptic.h | 481 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::type' | SDL2-2.24.0\include\SDL_haptic.h | 564 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 585 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::type' | SDL2-2.24.0\include\SDL_haptic.h | 616 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::center' | SDL2-2.24.0\include\SDL_haptic.h | 633 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::type' | SDL2-2.24.0\include\SDL_haptic.h | 652 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 671 |
| Warning | C4820 | 'SDL_HapticLeftRight': '2' bytes padding added after data member 'SDL_HapticLeftRight::type' | SDL2-2.24.0\include\SDL_haptic.h | 691 |
| Warning | C4820 | 'SDL_HapticCustom': '2' bytes padding added after data member 'SDL_HapticCustom::type' | SDL2-2.24.0\include\SDL_haptic.h | 717 |
| Warning | C4820 | 'SDL_HapticCustom': '1' bytes padding added after data member 'SDL_HapticCustom::channels' | SDL2-2.24.0\include\SDL_haptic.h | 729 |
| Warning | C4820 | 'SDL_HapticCustom': '4' bytes padding added after data member 'SDL_HapticCustom::samples' | SDL2-2.24.0\include\SDL_haptic.h | 731 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::product_id' | SDL2-2.24.0\include\SDL_hidapi.h | 92 |
| Warning | C4820 | 'SDL_hid_device_info': '6' bytes padding added after data member 'SDL_hid_device_info::release_number' | SDL2-2.24.0\include\SDL_hidapi.h | 97 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::interface_protocol' | SDL2-2.24.0\include\SDL_hidapi.h | 121 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::flags' | SDL2-2.24.0\include\SDL_messagebox.h | 97 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::numbuttons' | SDL2-2.24.0\include\SDL_messagebox.h | 102 |
| Warning | C4464 | relative include path contains '..' | src\gui\gui.h | 14 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::count' | SDL2_image-2.6.2\include\SDL_image.h | 2048 |
| Warning | C4464 | relative include path contains '..' | src\gui\gui.h | 16 |
| Warning | C4820 | 'MenuChoice': '3' bytes padding added after data member 'MenuChoice::selected' | src\gui\menu.h | 11 |
| Warning | C4820 | 'GameState': '2' bytes padding added after data member 'GameState::isTwelve' | src\gameplay\gamestate.h | 25 |
| Warning | C4820 | 'MainChar': '4' bytes padding added after data member 'MainChar::apt_elec' | src\gameplay\mainchar.h | 41 |
| Warning | C4458 | declaration of 'rank' hides class member | src\gameplay\mainchar.h | 19 |
| Message |  | see declaration of 'MainChar::rank' | src\gameplay\mainchar.h | 36 |
| Warning | C4065 | switch statement contains 'default' but no 'case' labels | src\covert.cpp | 86 |
| Warning | C4514 | 'SDL_memset4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 529 |
| Warning | C4514 | 'SDL_memcpy4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 757 |
| Warning | C4514 | 'SDL_size_mul_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 768 |
| Warning | C4514 | 'SDL_size_add_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 798 |
| Warning | C4514 | 'SDL_SwapFloat': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_endian.h | 297 |
| Warning | C4514 | 'SDL_PointInRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 110 |
| Warning | C4514 | 'SDL_RectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 119 |
| Warning | C4514 | 'SDL_RectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 127 |
| Warning | C4514 | 'SDL_PointInFRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 233 |
| Warning | C4514 | 'SDL_FRectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 242 |
| Warning | C4514 | 'SDL_FRectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 267 |
| Warning | C4514 | 'MainChar::MainChar': unreferenced inline function has been removed | src\gameplay\mainchar.h | 6 |
| Warning | C4514 | 'MainChar::setCallsign': unreferenced inline function has been removed | src\gameplay\mainchar.h | 18 |
| Warning | C4514 | 'MainChar::setRank': unreferenced inline function has been removed | src\gameplay\mainchar.h | 19 |
| Warning | C4514 | 'MainChar::setSkillLevels': unreferenced inline function has been removed | src\gameplay\mainchar.h | 20 |
| Warning | C4514 | 'MainChar::getCallsign': unreferenced inline function has been removed | src\gameplay\mainchar.h | 27 |
| Warning | C4514 | 'MainChar::getRank': unreferenced inline function has been removed | src\gameplay\mainchar.h | 28 |
| Warning | C4514 | 'MainChar::getCombatAptitude': unreferenced inline function has been removed | src\gameplay\mainchar.h | 29 |
| Warning | C4514 | 'MainChar::getDrivingAptitude': unreferenced inline function has been removed | src\gameplay\mainchar.h | 30 |
| Warning | C4514 | 'MainChar::getCryptoAptitude': unreferenced inline function has been removed | src\gameplay\mainchar.h | 31 |
| Warning | C4514 | 'MainChar::getElecAptitude': unreferenced inline function has been removed | src\gameplay\mainchar.h | 32 |
| Warning | C4820 | 'Organization': '7' bytes padding added after data member 'Organization::id_char' | src\gameplay\casegenerator.h | 16 |
| Warning | C5246 | 'std::array<Organization,3>::_Elems': the initialization of a subobject should be wrapped in braces | src\gameplay\casegenerator.h | 21 |
| Warning | C5246 | 'std::array<Organization,26>::_Elems': the initialization of a subobject should be wrapped in braces | src\gameplay\casegenerator.h | 32 |
| Warning | C4820 | 'Participant': '1' bytes padding added after data member 'Participant::agentletter' | src\gameplay\casegenerator.h | 107 |
| Warning | C4820 | 'Participant': '3' bytes padding added after data member 'Participant::city' | src\gameplay\casegenerator.h | 109 |
| Warning | C4820 | 'Participant': '7' bytes padding added after data member 'Participant::recruitcity' | src\gameplay\casegenerator.h | 111 |
| Warning | C4820 | 'Participant': '3' bytes padding added after data member 'Participant::visibility' | src\gameplay\casegenerator.h | 115 |
| Warning | C4514 | 'Participant::getName': unreferenced inline function has been removed | src\gameplay\casegenerator.h | 99 |
| Warning | C4514 | 'Participant::getAgentLetter': unreferenced inline function has been removed | src\gameplay\casegenerator.h | 100 |
| Warning | C4514 | 'Participant::getRankPoints': unreferenced inline function has been removed | src\gameplay\casegenerator.h | 101 |
| Warning | C4514 | 'Participant::getRole': unreferenced inline function has been removed | src\gameplay\casegenerator.h | 102 |
| Warning | C4514 | 'MissionSet::MissionSet': unreferenced inline function has been removed | src\gameplay\casegenerator.h | 146 |
| Warning | C4464 | relative include path contains '..' | src\minigame\minigame.h | 3 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C5204 | 'MiniGame': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly | src\minigame\minigame.h | 12 |
| Warning | C4820 | 'Inventory': '3' bytes padding added after data member 'Inventory::mags' | src\minigame\combat.h | 62 |
| Warning | C4820 | 'MiniGameCombat': '3' bytes padding added after data member 'MiniGameCombat::max_guards' | src\minigame\combat.h | 103 |
| Warning | C4265 | 'MiniGameCombat': class has virtual functions, but its non-trivial destructor is not virtual; instances of this class may not be destructed correctly | src\minigame\combat.h | 104 |
| Warning | C4100 | 'level': unreferenced formal parameter | src\minigame\combat.cpp | 15 |
| Warning | C4514 | 'MiniGameCombat::operator delete': unreferenced inline function has been removed | src\minigame\combat.h | 98 |
| Warning | C4464 | relative include path contains '..' | src\minigame\minigame.h | 3 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C5204 | 'MiniGame': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly | src\minigame\minigame.h | 12 |
| Warning | C4820 | 'Car': '1' bytes padding added after data member 'Car::suspicion' | src\minigame\driving.h | 20 |
| Warning | C4820 | 'MiniGameDriving': '3' bytes padding added after data member 'MiniGameDriving::unseen_timer' | src\minigame\driving.h | 46 |
| Warning | C5204 | 'MiniGameDriving': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly | src\minigame\driving.h | 46 |
| Warning | C4100 | 'level': unreferenced formal parameter | src\minigame\driving.cpp | 14 |
| Warning | C4464 | relative include path contains '..' | src\minigame\minigame.h | 3 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C5204 | 'MiniGame': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly | src\minigame\minigame.h | 12 |
| Warning | C4820 | 'MiniGameCryptography': '2' bytes padding added after data member 'MiniGameCryptography::user_decipher' | src\minigame\cryptography.h | 27 |
| Warning | C4365 | 'argument': conversion from 'int' to 'std::array<char,26>::size_type', signed/unsigned mismatch | src\minigame\cryptography.cpp | 36 |
| Warning | C4244 | '=': conversion from 'int' to '_Ty', possible loss of data | src\minigame\cryptography.cpp | 36 |
| Warning | C4100 | 'level': unreferenced formal parameter | src\minigame\cryptography.cpp | 13 |
| Warning | C4100 | 'key': unreferenced formal parameter | src\minigame\cryptography.cpp | 51 |
| Message |  | see reference to function template instantiation 'void MiniGameCryptography::test_convert_message<std::array<char,26>>(const _T0 &)' being compiled | src\minigame\cryptography.cpp | 40 |
| Warning | C4464 | relative include path contains '..' | src\minigame\minigame.h | 3 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C5204 | 'MiniGame': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly | src\minigame\minigame.h | 12 |
| Warning | C4820 | 'Junc': '2' bytes padding added after data member 'Junc::locked' | src\minigame\electronics.h | 34 |
| Warning | C4820 | 'MiniGameElectronics': '2' bytes padding added after data member 'MiniGameElectronics::sy' | src\minigame\electronics.h | 47 |
| Warning | C4820 | 'MiniGameElectronics': '4' bytes padding added after data member 'MiniGameElectronics::holding' | src\minigame\electronics.h | 50 |
| Warning | C5204 | 'MiniGameElectronics': class has virtual functions, but its trivial destructor is not virtual; instances of objects derived from this class may not be destructed correctly | src\minigame\electronics.h | 40 |
| Warning | C4101 | 'num_locked': unreferenced local variable | src\minigame\electronics.cpp | 14 |
| Warning | C4101 | 'num_swaps': unreferenced local variable | src\minigame\electronics.cpp | 18 |
| Warning | C4101 | 'num_jumps': unreferenced local variable | src\minigame\electronics.cpp | 17 |
| Warning | C4101 | 'num_hidden': unreferenced local variable | src\minigame\electronics.cpp | 15 |
| Warning | C4101 | 'num_alarms': unreferenced local variable | src\minigame\electronics.cpp | 16 |
| Warning | C4820 | 'SDL_AssertData': '4' bytes padding added after data member 'SDL_AssertData::linenum' | SDL2-2.24.0\include\SDL_assert.h | 124 |
| Warning | C4820 | 'SDL_RWops::<unnamed-tag>': '4' bytes padding added after data member 'SDL_RWops::<unnamed-tag>::append' | SDL2-2.24.0\include\SDL_rwops.h | 105 |
| Warning | C4820 | 'SDL_RWops': '4' bytes padding added after data member 'SDL_RWops::type' | SDL2-2.24.0\include\SDL_rwops.h | 133 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::len_mult' | SDL2-2.24.0\include\SDL_audio.h | 241 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::filter_index' | SDL2-2.24.0\include\SDL_audio.h | 244 |
| Warning | C4820 | 'SDL_Palette': '4' bytes padding added after data member 'SDL_Palette::ncolors' | SDL2-2.24.0\include\SDL_pixels.h | 321 |
| Warning | C4820 | 'SDL_PixelFormat': '4' bytes padding added after data member 'SDL_PixelFormat::format' | SDL2-2.24.0\include\SDL_pixels.h | 332 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::flags' | SDL2-2.24.0\include\SDL_surface.h | 75 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::pitch' | SDL2-2.24.0\include\SDL_surface.h | 78 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::locked' | SDL2-2.24.0\include\SDL_surface.h | 87 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::refcount' | SDL2-2.24.0\include\SDL_surface.h | 97 |
| Warning | C4820 | 'SDL_Keysym': '2' bytes padding added after data member 'SDL_Keysym::mod' | SDL2-2.24.0\include\SDL_keyboard.h | 52 |
| Warning | C4820 | 'SDL_Finger': '4' bytes padding added after data member 'SDL_Finger::pressure' | SDL2-2.24.0\include\SDL_touch.h | 58 |
| Warning | C4820 | 'SDL_TextEditingExtEvent': '4' bytes padding added after data member 'SDL_TextEditingExtEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 257 |
| Warning | C4820 | 'SDL_MultiGestureEvent': '4' bytes padding added after data member 'SDL_MultiGestureEvent::padding' | SDL2-2.24.0\include\SDL_events.h | 526 |
| Warning | C4820 | 'SDL_DropEvent': '4' bytes padding added after data member 'SDL_DropEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 556 |
| Warning | C4820 | 'SDL_HapticDirection': '3' bytes padding added after data member 'SDL_HapticDirection::type' | SDL2-2.24.0\include\SDL_haptic.h | 462 |
| Warning | C4820 | 'SDL_HapticConstant': '2' bytes padding added after data member 'SDL_HapticConstant::type' | SDL2-2.24.0\include\SDL_haptic.h | 481 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::type' | SDL2-2.24.0\include\SDL_haptic.h | 564 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 585 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::type' | SDL2-2.24.0\include\SDL_haptic.h | 616 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::center' | SDL2-2.24.0\include\SDL_haptic.h | 633 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::type' | SDL2-2.24.0\include\SDL_haptic.h | 652 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 671 |
| Warning | C4820 | 'SDL_HapticLeftRight': '2' bytes padding added after data member 'SDL_HapticLeftRight::type' | SDL2-2.24.0\include\SDL_haptic.h | 691 |
| Warning | C4820 | 'SDL_HapticCustom': '2' bytes padding added after data member 'SDL_HapticCustom::type' | SDL2-2.24.0\include\SDL_haptic.h | 717 |
| Warning | C4820 | 'SDL_HapticCustom': '1' bytes padding added after data member 'SDL_HapticCustom::channels' | SDL2-2.24.0\include\SDL_haptic.h | 729 |
| Warning | C4820 | 'SDL_HapticCustom': '4' bytes padding added after data member 'SDL_HapticCustom::samples' | SDL2-2.24.0\include\SDL_haptic.h | 731 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::product_id' | SDL2-2.24.0\include\SDL_hidapi.h | 92 |
| Warning | C4820 | 'SDL_hid_device_info': '6' bytes padding added after data member 'SDL_hid_device_info::release_number' | SDL2-2.24.0\include\SDL_hidapi.h | 97 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::interface_protocol' | SDL2-2.24.0\include\SDL_hidapi.h | 121 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::flags' | SDL2-2.24.0\include\SDL_messagebox.h | 97 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::numbuttons' | SDL2-2.24.0\include\SDL_messagebox.h | 102 |
| Warning | C4514 | 'SDL_memset4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 529 |
| Warning | C4514 | 'SDL_memcpy4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 757 |
| Warning | C4514 | 'SDL_size_mul_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 768 |
| Warning | C4514 | 'SDL_size_add_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 798 |
| Warning | C4514 | 'SDL_SwapFloat': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_endian.h | 297 |
| Warning | C4514 | 'SDL_PointInRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 110 |
| Warning | C4514 | 'SDL_RectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 119 |
| Warning | C4514 | 'SDL_RectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 127 |
| Warning | C4514 | 'SDL_PointInFRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 233 |
| Warning | C4514 | 'SDL_FRectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 242 |
| Warning | C4514 | 'SDL_FRectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 267 |
| Warning | C4820 | 'SDL_RWops::<unnamed-tag>': '4' bytes padding added after data member 'SDL_RWops::<unnamed-tag>::append' | SDL2-2.24.0\include\SDL_rwops.h | 105 |
| Warning | C4820 | 'SDL_RWops': '4' bytes padding added after data member 'SDL_RWops::type' | SDL2-2.24.0\include\SDL_rwops.h | 133 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::len_mult' | SDL2-2.24.0\include\SDL_audio.h | 241 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::filter_index' | SDL2-2.24.0\include\SDL_audio.h | 244 |
| Warning | C4820 | 'Mix_Chunk': '4' bytes padding added after data member 'Mix_Chunk::allocated' | SDL2_mixer-2.6.2\include\SDL_mixer.h | 230 |
| Warning | C4820 | 'Mix_Chunk': '3' bytes padding added after data member 'Mix_Chunk::volume' | SDL2_mixer-2.6.2\include\SDL_mixer.h | 233 |
| Warning | C4464 | relative include path contains '..' | src\sound\music.h | 4 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C4100 | 'midi': unreferenced formal parameter | src\sound\music.cpp | 10 |
| Warning | C4514 | 'SDL_memset4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 529 |
| Warning | C4514 | 'SDL_memcpy4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 757 |
| Warning | C4514 | 'SDL_size_mul_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 768 |
| Warning | C4514 | 'SDL_size_add_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 798 |
| Warning | C4514 | 'SDL_SwapFloat': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_endian.h | 297 |
| Warning | C4820 | 'SDL_AssertData': '4' bytes padding added after data member 'SDL_AssertData::linenum' | SDL2-2.24.0\include\SDL_assert.h | 124 |
| Warning | C4820 | 'SDL_RWops::<unnamed-tag>': '4' bytes padding added after data member 'SDL_RWops::<unnamed-tag>::append' | SDL2-2.24.0\include\SDL_rwops.h | 105 |
| Warning | C4820 | 'SDL_RWops': '4' bytes padding added after data member 'SDL_RWops::type' | SDL2-2.24.0\include\SDL_rwops.h | 133 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::len_mult' | SDL2-2.24.0\include\SDL_audio.h | 241 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::filter_index' | SDL2-2.24.0\include\SDL_audio.h | 244 |
| Warning | C4820 | 'SDL_Palette': '4' bytes padding added after data member 'SDL_Palette::ncolors' | SDL2-2.24.0\include\SDL_pixels.h | 321 |
| Warning | C4820 | 'SDL_PixelFormat': '4' bytes padding added after data member 'SDL_PixelFormat::format' | SDL2-2.24.0\include\SDL_pixels.h | 332 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::flags' | SDL2-2.24.0\include\SDL_surface.h | 75 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::pitch' | SDL2-2.24.0\include\SDL_surface.h | 78 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::locked' | SDL2-2.24.0\include\SDL_surface.h | 87 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::refcount' | SDL2-2.24.0\include\SDL_surface.h | 97 |
| Warning | C4820 | 'SDL_Keysym': '2' bytes padding added after data member 'SDL_Keysym::mod' | SDL2-2.24.0\include\SDL_keyboard.h | 52 |
| Warning | C4820 | 'SDL_Finger': '4' bytes padding added after data member 'SDL_Finger::pressure' | SDL2-2.24.0\include\SDL_touch.h | 58 |
| Warning | C4820 | 'SDL_TextEditingExtEvent': '4' bytes padding added after data member 'SDL_TextEditingExtEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 257 |
| Warning | C4820 | 'SDL_MultiGestureEvent': '4' bytes padding added after data member 'SDL_MultiGestureEvent::padding' | SDL2-2.24.0\include\SDL_events.h | 526 |
| Warning | C4820 | 'SDL_DropEvent': '4' bytes padding added after data member 'SDL_DropEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 556 |
| Warning | C4820 | 'SDL_HapticDirection': '3' bytes padding added after data member 'SDL_HapticDirection::type' | SDL2-2.24.0\include\SDL_haptic.h | 462 |
| Warning | C4820 | 'SDL_HapticConstant': '2' bytes padding added after data member 'SDL_HapticConstant::type' | SDL2-2.24.0\include\SDL_haptic.h | 481 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::type' | SDL2-2.24.0\include\SDL_haptic.h | 564 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 585 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::type' | SDL2-2.24.0\include\SDL_haptic.h | 616 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::center' | SDL2-2.24.0\include\SDL_haptic.h | 633 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::type' | SDL2-2.24.0\include\SDL_haptic.h | 652 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 671 |
| Warning | C4820 | 'SDL_HapticLeftRight': '2' bytes padding added after data member 'SDL_HapticLeftRight::type' | SDL2-2.24.0\include\SDL_haptic.h | 691 |
| Warning | C4820 | 'SDL_HapticCustom': '2' bytes padding added after data member 'SDL_HapticCustom::type' | SDL2-2.24.0\include\SDL_haptic.h | 717 |
| Warning | C4820 | 'SDL_HapticCustom': '1' bytes padding added after data member 'SDL_HapticCustom::channels' | SDL2-2.24.0\include\SDL_haptic.h | 729 |
| Warning | C4820 | 'SDL_HapticCustom': '4' bytes padding added after data member 'SDL_HapticCustom::samples' | SDL2-2.24.0\include\SDL_haptic.h | 731 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::product_id' | SDL2-2.24.0\include\SDL_hidapi.h | 92 |
| Warning | C4820 | 'SDL_hid_device_info': '6' bytes padding added after data member 'SDL_hid_device_info::release_number' | SDL2-2.24.0\include\SDL_hidapi.h | 97 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::interface_protocol' | SDL2-2.24.0\include\SDL_hidapi.h | 121 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::flags' | SDL2-2.24.0\include\SDL_messagebox.h | 97 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::numbuttons' | SDL2-2.24.0\include\SDL_messagebox.h | 102 |
| Warning | C4464 | relative include path contains '..' | src\gui\gui.h | 14 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::count' | SDL2_image-2.6.2\include\SDL_image.h | 2048 |
| Warning | C4464 | relative include path contains '..' | src\gui\gui.h | 16 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C4820 | 'MenuChoice': '3' bytes padding added after data member 'MenuChoice::selected' | src\gui\menu.h | 11 |
| Warning | C4061 | enumerator 'GameScreen::CIABanned' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::ReviewWiretaps' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::CodedMessages' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::CrimeChronology' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::Airport' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::MiniGameCombatStart' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::MiniGameDrivingStart' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::DrivingCarSelect' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::MiniGameCryptoStart' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::MiniGameElecStart' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4061 | enumerator 'GameScreen::UNKNOWN' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gui\gui.cpp | 205 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4514 | 'SDL_memset4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 529 |
| Warning | C4514 | 'SDL_memcpy4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 757 |
| Warning | C4514 | 'SDL_size_mul_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 768 |
| Warning | C4514 | 'SDL_size_add_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 798 |
| Warning | C4514 | 'SDL_SwapFloat': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_endian.h | 297 |
| Warning | C4514 | 'SDL_PointInRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 110 |
| Warning | C4514 | 'SDL_RectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 119 |
| Warning | C4514 | 'SDL_RectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 127 |
| Warning | C4514 | 'SDL_PointInFRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 233 |
| Warning | C4514 | 'SDL_FRectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 242 |
| Warning | C4514 | 'SDL_FRectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 267 |
| Warning | C4820 | 'SDL_Palette': '4' bytes padding added after data member 'SDL_Palette::ncolors' | SDL2-2.24.0\include\SDL_pixels.h | 321 |
| Warning | C4820 | 'SDL_PixelFormat': '4' bytes padding added after data member 'SDL_PixelFormat::format' | SDL2-2.24.0\include\SDL_pixels.h | 332 |
| Warning | C4820 | 'SDL_RWops::<unnamed-tag>': '4' bytes padding added after data member 'SDL_RWops::<unnamed-tag>::append' | SDL2-2.24.0\include\SDL_rwops.h | 105 |
| Warning | C4820 | 'SDL_RWops': '4' bytes padding added after data member 'SDL_RWops::type' | SDL2-2.24.0\include\SDL_rwops.h | 133 |
| Warning | C4514 | 'SDL_memset4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 529 |
| Warning | C4514 | 'SDL_memcpy4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 757 |
| Warning | C4514 | 'SDL_size_mul_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 768 |
| Warning | C4514 | 'SDL_size_add_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 798 |
| Warning | C4514 | 'SDL_SwapFloat': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_endian.h | 297 |
| Warning | C4514 | 'SDL_PointInRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 110 |
| Warning | C4514 | 'SDL_RectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 119 |
| Warning | C4514 | 'SDL_RectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 127 |
| Warning | C4514 | 'SDL_PointInFRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 233 |
| Warning | C4514 | 'SDL_FRectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 242 |
| Warning | C4514 | 'SDL_FRectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 267 |
| Warning | C4514 | 'Point::Point': unreferenced inline function has been removed | src\gui\point.h | 8 |
| Warning | C4514 | 'Point::operator ++': unreferenced inline function has been removed | src\gui\point.h | 11 |
| Warning | C4514 | 'Point::getX': unreferenced inline function has been removed | src\gui\point.h | 13 |
| Warning | C4514 | 'Point::getY': unreferenced inline function has been removed | src\gui\point.h | 14 |
| Warning | C4464 | relative include path contains '..' | src\gameplay\gamestate.h | 5 |
| Warning | C4820 | 'SDL_AssertData': '4' bytes padding added after data member 'SDL_AssertData::linenum' | SDL2-2.24.0\include\SDL_assert.h | 124 |
| Warning | C4820 | 'SDL_RWops::<unnamed-tag>': '4' bytes padding added after data member 'SDL_RWops::<unnamed-tag>::append' | SDL2-2.24.0\include\SDL_rwops.h | 105 |
| Warning | C4820 | 'SDL_RWops': '4' bytes padding added after data member 'SDL_RWops::type' | SDL2-2.24.0\include\SDL_rwops.h | 133 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::len_mult' | SDL2-2.24.0\include\SDL_audio.h | 241 |
| Warning | C4820 | 'SDL_AudioCVT': '4' bytes padding added after data member 'SDL_AudioCVT::filter_index' | SDL2-2.24.0\include\SDL_audio.h | 244 |
| Warning | C4820 | 'SDL_Palette': '4' bytes padding added after data member 'SDL_Palette::ncolors' | SDL2-2.24.0\include\SDL_pixels.h | 321 |
| Warning | C4820 | 'SDL_PixelFormat': '4' bytes padding added after data member 'SDL_PixelFormat::format' | SDL2-2.24.0\include\SDL_pixels.h | 332 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::flags' | SDL2-2.24.0\include\SDL_surface.h | 75 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::pitch' | SDL2-2.24.0\include\SDL_surface.h | 78 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::locked' | SDL2-2.24.0\include\SDL_surface.h | 87 |
| Warning | C4820 | 'SDL_Surface': '4' bytes padding added after data member 'SDL_Surface::refcount' | SDL2-2.24.0\include\SDL_surface.h | 97 |
| Warning | C4820 | 'SDL_Keysym': '2' bytes padding added after data member 'SDL_Keysym::mod' | SDL2-2.24.0\include\SDL_keyboard.h | 52 |
| Warning | C4820 | 'SDL_Finger': '4' bytes padding added after data member 'SDL_Finger::pressure' | SDL2-2.24.0\include\SDL_touch.h | 58 |
| Warning | C4820 | 'SDL_TextEditingExtEvent': '4' bytes padding added after data member 'SDL_TextEditingExtEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 257 |
| Warning | C4820 | 'SDL_MultiGestureEvent': '4' bytes padding added after data member 'SDL_MultiGestureEvent::padding' | SDL2-2.24.0\include\SDL_events.h | 526 |
| Warning | C4820 | 'SDL_DropEvent': '4' bytes padding added after data member 'SDL_DropEvent::windowID' | SDL2-2.24.0\include\SDL_events.h | 556 |
| Warning | C4820 | 'SDL_HapticDirection': '3' bytes padding added after data member 'SDL_HapticDirection::type' | SDL2-2.24.0\include\SDL_haptic.h | 462 |
| Warning | C4820 | 'SDL_HapticConstant': '2' bytes padding added after data member 'SDL_HapticConstant::type' | SDL2-2.24.0\include\SDL_haptic.h | 481 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::type' | SDL2-2.24.0\include\SDL_haptic.h | 564 |
| Warning | C4820 | 'SDL_HapticPeriodic': '2' bytes padding added after data member 'SDL_HapticPeriodic::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 585 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::type' | SDL2-2.24.0\include\SDL_haptic.h | 616 |
| Warning | C4820 | 'SDL_HapticCondition': '2' bytes padding added after data member 'SDL_HapticCondition::center' | SDL2-2.24.0\include\SDL_haptic.h | 633 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::type' | SDL2-2.24.0\include\SDL_haptic.h | 652 |
| Warning | C4820 | 'SDL_HapticRamp': '2' bytes padding added after data member 'SDL_HapticRamp::fade_level' | SDL2-2.24.0\include\SDL_haptic.h | 671 |
| Warning | C4820 | 'SDL_HapticLeftRight': '2' bytes padding added after data member 'SDL_HapticLeftRight::type' | SDL2-2.24.0\include\SDL_haptic.h | 691 |
| Warning | C4820 | 'SDL_HapticCustom': '2' bytes padding added after data member 'SDL_HapticCustom::type' | SDL2-2.24.0\include\SDL_haptic.h | 717 |
| Warning | C4820 | 'SDL_HapticCustom': '1' bytes padding added after data member 'SDL_HapticCustom::channels' | SDL2-2.24.0\include\SDL_haptic.h | 729 |
| Warning | C4820 | 'SDL_HapticCustom': '4' bytes padding added after data member 'SDL_HapticCustom::samples' | SDL2-2.24.0\include\SDL_haptic.h | 731 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::product_id' | SDL2-2.24.0\include\SDL_hidapi.h | 92 |
| Warning | C4820 | 'SDL_hid_device_info': '6' bytes padding added after data member 'SDL_hid_device_info::release_number' | SDL2-2.24.0\include\SDL_hidapi.h | 97 |
| Warning | C4820 | 'SDL_hid_device_info': '4' bytes padding added after data member 'SDL_hid_device_info::interface_protocol' | SDL2-2.24.0\include\SDL_hidapi.h | 121 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::flags' | SDL2-2.24.0\include\SDL_messagebox.h | 97 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::numbuttons' | SDL2-2.24.0\include\SDL_messagebox.h | 102 |
| Warning | C4464 | relative include path contains '..' | src\gui\gui.h | 14 |
| Warning | C4820 | '<unnamed-tag>': '4' bytes padding added after data member '<unnamed-tag>::count' | SDL2_image-2.6.2\include\SDL_image.h | 2048 |
| Warning | C4464 | relative include path contains '..' | src\gui\gui.h | 16 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C4820 | 'MenuChoice': '3' bytes padding added after data member 'MenuChoice::selected' | src\gui\menu.h | 11 |
| Warning | C4820 | 'GameState': '2' bytes padding added after data member 'GameState::isTwelve' | src\gameplay\gamestate.h | 25 |
| Warning | C4061 | enumerator 'GameScreen::DrivingCarSelect' in switch of enum 'GameScreen' is not explicitly handled by a case label | src\gameplay\gamestate.cpp | 291 |
| Message |  | see declaration of 'GameScreen' | src\types.h | 48 |
| Warning | C4100 | 'miniGame': unreferenced formal parameter | src\gameplay\gamestate.cpp | 295 |
| Warning | C4514 | 'SDL_memset4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 529 |
| Warning | C4514 | 'SDL_memcpy4': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 757 |
| Warning | C4514 | 'SDL_size_mul_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 768 |
| Warning | C4514 | 'SDL_size_add_overflow': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_stdinc.h | 798 |
| Warning | C4514 | 'SDL_SwapFloat': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_endian.h | 297 |
| Warning | C4514 | 'SDL_PointInRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 110 |
| Warning | C4514 | 'SDL_RectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 119 |
| Warning | C4514 | 'SDL_RectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 127 |
| Warning | C4514 | 'SDL_PointInFRect': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 233 |
| Warning | C4514 | 'SDL_FRectEmpty': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 242 |
| Warning | C4514 | 'SDL_FRectEquals': unreferenced inline function has been removed | SDL2-2.24.0\include\SDL_rect.h | 267 |
| Warning | C4464 | relative include path contains '..' | src\gameplay\agentgenerator.h | 3 |
| Warning | C4820 | 'City': '4' bytes padding added after data member 'City::align' | src\types.h | 128 |
| Warning | C4820 | 'Agent': '2' bytes padding added after data member 'Agent::Photo' | src\types.h | 165 |
| Warning | C4820 | 'MenuChoice': '3' bytes padding added after data member 'MenuChoice::selected' | src\gui\menu.h | 11 |
| Warning | C4365 | 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch | src\gui\menu.cpp | 19 |
| Warning | C4365 | 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch | src\gui\menu.cpp | 19 |
| Warning | C4365 | 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch | src\gui\menu.cpp | 22 |
| Warning | C4365 | 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch | src\gui\menu.cpp | 22 |
| Warning | C4365 | 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch | src\gui\menu.cpp | 24 |
| Warning | C4365 | 'argument': conversion from 'int' to 'const unsigned __int64', signed/unsigned mismatch | src\gui\menu.cpp | 24 |
| Warning | C4700 | uninitialized local variable 'd' used | src\minigame\electronics.cpp | 73 |
