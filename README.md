# CAE

*"CAE" is not a reference to a company name or engineering term.*

I made this repository to practice in several domains:

- C++ standard library and some newer C++ functionality
- Cross-platform GUI, specifically SDL2
- Reverse engineering
- Unit testing
- Debugging
- CMake

Currently, I build this using CMake on Fedora 36 with a few libsdl-org package (SDL2, TTF, Mixer, Image) as well as zlib and libpng. If there are other dependencies, those will either be in the CMakeLists.txt file or can be installed with a package manager or compiled from source.

With significant manual configuration, this will build on Windows 10 using Visual Studio.

Once this project is 70 to 90 percent feature-complete, I would add documentation and binaries for all major platforms. Until then, you're mostly on your own building everything. Let me know if you need instructions. I'm not a cruel person, I'm simply putting this off for now because it takes time from source development, and I am not going to benefit from writing build instructions for myself.

If I am able to make progress --- and, let's face it... I quit a lot of hobbies or projects once I'm halfway through --- this will eventually be an engine copy of a reasonably obscure DOS game from an extremely popular and successful game studio. (The title is in the source already, but I don't want to publicize which game because there's already a ton of vaporware in the Linux community.) Time permitting, I will try to independently develop compatible art to support those who do not have the original data files. This is particularly challenging, as there are case files, password lists, a face generator, and animated graphics in a proprietary format. Also, it would probably take quite a bit of reverse engineering to figure out where each resource is located in the original files, such as font face, graphics coordinates for the map display, linkages between partially hidden events, and more. I would also hope to have a method of parsing all of the original data files.

I also have some stretch goals, but these are not active until the project is fully on track to be complete:

- localization: French, German, Italian, Portuguese, Spanish
- creating a legal .ogg/.mp3 of the theme music using the original Roland MT-32 sounds (or a very convincing Soundfont with the original MIDI)
- converting low-res sprites to vector representations or high-res, high-frame-rate sprites or model-generated objects
- 3d display of airport scene
- 3d replay of the 2d minigame (it would probably be cool to do realtime 3d, but this might not be playable because of visibility differences between 2d and 3d, and developing a renderer and models for 3d would be extremely time consuming.)
- improve the engine's state machine and case generators to be a more readable, script-driven format
- fix bugs in the original program
- localization (non-Latin): Arabic, Chinese, Hebrew, Japanese, Korean, Russian

## Doxygen for inheritance diagrams

```sh
doxygen dox.cfg
```
