TODO
====

## Implementation

- [ ] remove duplicated (and old) files from directory structure
- [x] `#pragma once` rather than include guards
- [ ] single random generator
- [ ] only `#include` what is needed, and use a better order: own header, project header, third-party, system
- [ ] nearly completely separate out the various subsystems so they can be selectively replaced e.g. GUI with console interaction
- [ ] `const` wherever possible
- [ ] `volatile` where needed
- [ ] fix access and scope (`static`, `public:`, `private:`, `protected:`)
- [ ] think about `default`, `delete`, `override`/`virtual`
- [ ] singletons? A good struct only called once?
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
  - [ ] - Global Difficulty, Skill Modifiers
  - [ ] - Character Level
- [ ] Room Generation (Combat)
  - [ ] - Bug details
  - [ ] - Password chart
  - [ ] - Modification for ambush, break-out, etc.
- [ ] HQ
  - [ ] - Intelligence Menu
  - [ ] - Surveillance
  - [ ] - Clues
  - [ ] - Activity reports
  - [ ] - Agent states
- [ ] Populate all possible messages (or generative phrases)
- [ ] Hotel
  - [ ] - Gossip
- [ ] Building Exteriors
- [ ] Clock
- [ ] Airport
  - [ ] - World map
- [ ] Mission
  - [ ] - Participant organizational chart
  - [ ] - Debrief
  - [ ] - Scoring
  - [ ] - Loading from data files
  - [ ] - Save / Load functionality?
- [ ] User Interface
  - [ ] - Menus, easily implemented
  - [ ] - Graphics / Picture display / Fonts / # colors
  - [ ] - Sound
  - [ ] - Input devices
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

## Still Missing

- [ ] load existing file (This should dictate much of the variable/class structure!)
- [ ] keyboard mapper / configuration file
- [ ] folder display showing org/city activity (okay if it is a very flawed algorithm at the beginning)
- [ ] font (if error during load, use an internal array; possibly switch to _only_ internal going forward)
  - It might be wise to see how other SDL2 projects accomplish this.

## Ideas

- [ ] add ENHANCEMENTS and FIX_ORIGINAL macros early, so these can be selectively (and independently) activated during build
