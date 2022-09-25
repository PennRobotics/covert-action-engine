Covert Action Engine
====================

This is a clone of the engine for the MPS Labs game, _Covert Action_.

The plan is to develop tools for extracting package data from the original game folder for conversion to an open format. The majority of string data are stored in the executable while picture and animation data are found in self-contained files. There are discussions on the internet about the exact nature of some of the data files. For all else, the DOSBox-X debugger and a good disassembler/decompiler would provide insight into the game's inner workings (random number engine, animation method, combat accuracy calculation, etc.)

Bases for the development of the engine are the source codes for Freeciv, Master of Orion, C-Dogs SDL, SDLPop (Prince of Persia), cc94 and FreeCol (Colonization), Crown and Cutlass (Pirates!), GE211 by Jesse A. Tov, flat by Linus Probert, Cataclysm-DDA, SuperTux, and devilutionX. These other projects provide guidance in the form of folder/header/object structure, memory management, build technique, data manipulation, object interaction, and ideal layout of SDL calls.

# BEST IDENTIFIED BLOCKER-BREAKER

  -- Create the entire state machine that advances to the next default on any keypress --

# SECOND-BEST BLOCKER-BREAKER

  -- Display an up-down menu, allow selection, enter/escape returns correct index --

# THIRD PRIORITY

  -- Preprocessor macro PLACEHOLDERS should replace all graphics calls --

# TODO

- [x] Change name of project but also all references e.g. BUILD.md URL
- [ ] Documentation
- [ ] Font
- [ ] Sound
- [ ] Menu system
- [ ] Case Data
  - [ ] Clues
  - [ ] Evidence
  - [ ] Mentions
- [ ] Settings file
  - [ ] Granular randomization
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
- [ ] Strip MIDI and record with HD soundfont
- [ ] Strip sprites where necessary
- [ ] Localization
- [ ] Vector graphics
- [ ] Create various combat AIs

## Implementation

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

## Porting

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

## Specific Code

- [ ] comingFrom (try to make this automatically defined)
- [ ] nextscreen is probably not needed. directly assign the next screen based on provided condition argument
- [ ] generate *n* double agents
- [ ] add remaining original font glyphs
- [ ] remove debug-related inheritance (used for testing Singleton instantiation and access)
  - [ ] **covert.cpp** should not include **combat.h**
  - [ ] **cryptography.cpp** should not include **combat.h**
- [ ] Building1, Building2, etc. should just be Building with building type passed as an enum (simplifies menu creation and screen back-reference)

## Still Missing

- [ ] load existing file (This should dictate much of the variable/class structure!)
- [ ] keyboard mapper / configuration file
- [ ] folder display showing org/city activity (okay if it is a very flawed algorithm at the beginning)
- [ ] font (if error during load, use an internal array; possibly switch to _only_ internal going forward)
  - It might be wise to see how other SDL2 projects accomplish this.

## Ideas

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
