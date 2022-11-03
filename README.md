Covert Action Engine
====================

I made this repository to practice in several domains:

- C++ standard library and some newer C++ functionality
- Cross-platform GUI, specifically SDL2
- Reverse engineering
- Unit testing
- Debugging
- CMake

Currently, I build this using CMake on Fedora 36 with a few libsdl-org package (SDL2, TTF, Mixer, Image) as well as zlib and libpng. If there are other dependencies, those will either be in the CMakeLists.txt file or can be installed with a package manager or compiled from source.

With significant manual configuration, this will [build on Windows 10 using Visual Studio](BUILD.md).

Once this project is 70 to 90 percent feature-complete, I would add documentation and binaries for all major platforms. Until then, you're mostly on your own building everything. Let me know if you need instructions. I'm not a cruel person, I'm simply putting this off for now because it takes time from source development, and I am not going to benefit from writing build instructions for myself.

If I am able to make progress --- and, let's face it... I quit a lot of hobbies or projects once I'm halfway through --- this will eventually be an engine copy of a reasonably obscure DOS game from an extremely popular and successful game studio. (The title is in the source already, but I don't want to publicize which game because there's already a ton of vaporware in the Linux community.) Time permitting, I will try to independently develop compatible art to support those who do not have the original data files. This is particularly challenging, as there are case files, password lists, a face generator, and animated graphics in a proprietary format. Also, it would probably take quite a bit of reverse engineering to figure out where each resource is located in the original files, such as font face, graphics coordinates for the map display, linkages between partially hidden events, and more. I would also hope to have a method of parsing all of the original data files.

## Doxygen for inheritance diagrams

```sh
doxygen dox.cfg
```

## More Info

[Wiki](https://github.com/PennRobotics/covert-action-engine/wiki) -
describes build flags and file organization

[BUILD.md](BUILD.md) - contains commands for compiling from source  
[RANDOM.md](RANDOM.md) - assorted thoughts on content creation to avoid copyright/license violation  
[REFERENCES.md](REFERENCES.md) - links to resources useful during programming  
[TODO.md](TODO.md) - checklist of identified improvement areas  
[TESTTODO.md](./test/TESTTODO.md) - checklist of changes needed in the test suite  
[content/](./content/) - directory with summaries of each data storage method  


<div id="badges">
  <a href="https://www.linkedin.com/in/pennrobotics/"><img src="https://img.shields.io/badge/LinkedIn-steelblue?style=flat&logo=linkedin&logoColor=white" alt="LinkedIn Badge"/></a>
  <a href="https://github.com/PennRobotics/"><img src="https://img.shields.io/badge/Github-darkslategrey?style=flat&logo=github&logoColor=white" alt="GitHub Badge"/></a>
  <a href="https://news.ycombinator.com/user?id=PennRobotics"><img src="https://img.shields.io/badge/HackerNews-orange?style=flat&logo=ycombinator&logoColor=white" alt="Hacker News Badge"/></a>
  <a href="https://stackoverflow.com/users/10641561"><img src="https://img.shields.io/badge/StackOverflow-darkorange?style=flat&logo=stackoverflow&logoColor=white" alt="Stack Overflow Badge"/></a>
</div>
