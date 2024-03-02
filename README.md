# rebound

A Game I made back in 2012 or 2013, for a competition in C++

**UPDATE 03/02/2024**: The game is buildable again! I upgraded it to use SDL 2 and i've provided executables for Windows and Linux, I will shortly have a build Mac (hopefully)

This game was made for the Moosader Forum Competition 8: Procedural/Random Generated Game.

The game takes the tried and tested mechanics of pong and modernises them by adding 'crates' to the playing field,
when the pong ball hits a randomly placed crate, the state of the ball, playing field or the player changes, either
providing an advantage or disadvantage to the player that last hit the ball.

In the game, there are the following crates:

- Point up: Player gets an extra point
- Point Down: Player loses a point
- Take Point: Player takes point from other player if they have any
- Change Theme: Level will flip to different theme
- Randomise Crates again
- Ball Speed up
- Ball Speed down
- Mystery Crate (does any of the above, but you don't know what until you hit it)

After each time player hits ball, ball speeds up slightly until a point is scored or a 'ball speed down' crate is hit.

Player plays against AI

## Just want to play the game in web browser? I have it hosted!

https://rebound.michaeldsharp.com/

_game doesn't currently support mouse or touch screen input, only keyboard control for now. My plan is to add some form of mobile-friendly input soon_

## Building the game

### Windows

1. I would recommend installing MinGW to get the C++ compiler and Make, you might need to do a bit of googling to figure out exactly how to do that
   - To get started, try looking at https://winlibs.com , reading the preamble and then grabbing one of the GCC Zip archives on the same page. You will need to download, extract and then add the location you've extracted to your PATH via control panel/windows settings, the ZIP file contains a bin folder that you should add to your PATH, and then you'll be able to run g++ (the C++ compiler) and make (the build system that this project uses to compile the desktop version of the game)
   - Alternatively, there's a package manager for MinGW that works well to, it's hosted at https://sourceforge.net/projects/mingw/files/Installer/ and this allows you to install parts of MinGW (such as the g++ compiler and make)
2. Download and Install the SDL developer libraries and add the location where you've installed the libraries to the `windows.Makefile` file, it's probably easiest just to place it in the same location i've placed it, as referenced in the Makefile.
   Links to builds of SDL and supporting libraries:
   - SDL 2 - https://github.com/libsdl-org/SDL/releases/tag/release-2.30.0
   - SDL_Mixer: https://github.com/libsdl-org/SDL_mixer/releases/tag/release-2.8.0
   - SDL_Image: https://github.com/libsdl-org/SDL_image/releases/tag/release-2.8.2
3. run `make -f build-scripts/windows/desktop.Makefile` and the game will build into the `bin/windows` folder
4. The DLLs and assets required to run the game will also be pulled into the `bin/windows` directory, so if you run `rebound.exe`, the game should start up and play correctly

### Linux

1. You can obtain the SDL development libraries from your package manager, run the following commands:

   `sudo apt-get install libsdl2-dev`

   `sudo apt-get install libsdl2-image-dev`

   `sudo apt-get install libsdl2-mixer-dev`

2. once you have these libraries installed, you should be able to run `make -f ./build-scripts/linux/desktop.Makefile` and the game should build and bundle in the required assets
3. you will now be able to run `rebound` from `bin/linux` and all of the required assets and dependencies should be installed

### Mac

1. MacOS frameworks are a complete mess and break after each OS version, so I would recommend installing `SDL2`, `SDL2_mixer`, and `SDL2_image` using `brew`. I've configured the Makefiles for building on Mac expecting those libraries to be in the directory where hombrew stores all of its packages
   _if you do not already have homebrew installed, follow the instructions to install homebrew on your Mac, from https://brew.sh/_
2. run the following commands to install the required SDL libraries:

`brew install SDL2`

`brew install SDL2_image`

`brew install SDL2_mixer`

3. run `make -f ./build-scripts/mac/desktop.Makefile` to build the desktop app to the `bin/mac` folder
4. you will now be able to run `rebound` from `bin/mac` and all of the required assets and dependencies should be installed

## Building for web

1. Please follow the tutorial for installing the emscripten SDK locally for your operating system, docs can be found at: https://emscripten.org/docs/getting_started/downloads.html

   ### **Each OS has its own Makefile for building for the web, so please ensure you run the correct one for your operating system (windows, mac or linux)**

2. with the emscripten SDK (emsdk) enabled, run `make -f build-scripts/web.Makefile` and the game should build in the `web` folder, you should be able to host this folder like any other website and play the game

## Debugging the project in VSCode

### Windows

1. Build the project (see `Building the game for Windows`)

2. Place your breakpoints wherever you want them

3. From the list of `Run and debug` tasks, select `Debug (with breakpoints in Windows)` and then press the green play button.

4. You should be able to debug the project

### Linux

1. Build the project (see `Building the game for Linux`)

2. Place your breakpoints wherever you want them

3. From the list of `Run and debug` tasks, select `Debug (with breakpoints in Linux)` and then press the green play button.

4. You should be able to debug the project

### MacOS

The MacOS launch config for debugging uses the LLDB debugger, as GDB doesn't support Apple Silicon yet.

You will need to install an extension called `CodeLLDB` before attempting to run the debugging task for MacOS.

1. Build the project (see `Building the game for Mac`)

2. Place your breakpoints wherever you want them

3. From the list of `Run and debug` tasks, select `Debug (with breakpoints in MacOS)` and then press the green play button.

4. You should be able to debug the project
