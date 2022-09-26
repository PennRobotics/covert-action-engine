Building from Source
====================

## Linux

```sh
git clone https://github.com/PennRobotics/covert-action-engine
cd covert-action-engine
mkdir build && cd build
cmake ..
make
./covert-action-engine
```

## Windows (Visual Studio)

1. Clone repository
0. Fix the library paths in __CMakeLists.txt__ if SDL/zlib/etc are not installed system-wide
0. Make a build directory and run `cmake ..` from this directory
0. `cmake ..` should create some __.sln__ and __.vcxproj__ files. Open the solution in Visual Studio
0. Go to *Project -> Properties -> Configuration Properties -> Linker -> Input -> Additional Dependencies* and fix the path names.
    * This might look like: ```"SDL2-2.24.0\lib\x64\SDL2.lib";"SDL2_image-2.6.2\lib\x64\SDL2_image.lib";"SDL2_mixer-2.6.2\lib\x64\SDL2_mixer.lib";"SDL2_ttf-2.20.1\lib\x64\SDL2_ttf.lib";```
0. You also might need to change *Configuration Properties -> VC++ Directories -> Library Directories* to the base folder where all SDL2 libraries are found.
0. Change `const char* fname = ...` in __gui.cpp__ to point to a valid font file
0. Copy the __.dll__ files from each SDL2 library into the executable directory, which might be __build\Release__
0. Right-click the __covert-action-engine__ project in the Solution Explorer, and select *Debug -> Start New Instance*

*Please submit a pull request if you know any method of improving the build process in Visual Studio!*
