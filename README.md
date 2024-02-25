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

## Building the game for Windows

1. I would recommend installing MinGW to get the C++ compiler and Make, you might need to do a bit of googling to figure out exactly how to do that
2. Install the SDL developer libraries and add the location where you've installed the libraries to the `windows.Makefile` file, it's probably easiest just to place it in the same location i've placed it, as referenced in the Makefile.
3. run `make -f build-scripts/windows/desktop.Makefile` and the game will build into the `bin/windows` folder
4. The DLLs and assets required to run the game will also be pulled into the `bin/windows` directory, so if you run `rebound.exe`, the game should start up and play correctly

## Building the game for Linux

1. You can obtain the SDL development libraries from your package manager, run the following commands:
   `sudo apt-get install libsdl2-dev`
   `sudo apt-get install libsdl2-image-dev`
   `sudo apt-get install libsdl2-mixer-dev`

2. once you have these libraries installed, you should be able to run `make -f ./build-scripts/linux/desktop.Makefile` and the game should build and bundle in the required assets
3. you will now be able to run `rebound` from `bin/linux` and all of the required assets and dependencies should be installed

## Building the game for Mac

1. MacOS frameworks are a complete mess and break after each OS version, so I would recommend installing `SDL2`, `SDL2_mixer`, and `SDL2_image` using `brew`. I've configured the Makefiles for building on Mac expecting those libraries to be in the directory where hombrew stores all of its packages
2. if you do not already have homebrew installed, follow the instructions to install homebrew on your Mac, from https://brew.sh/
3. run the following commands to install the required SDL libraries:

`brew install SDL2`

`brew install SDL2_image`

`brew install SDL2_mixer`

2. run `make -f ./build-scripts/mac/desktop.Makefile` to build the desktop app to the `bin/mac` folder
3. you will now be able to run `rebound` from `bin/mac` and all of the required assets and dependencies should be installed

## Building for web

1. Please follow the tutorial for installing the emscripten SDK locally for your operating system, docs can be found at: https://emscripten.org/docs/getting_started/downloads.html

   ### **Each OS has its own Makefile for building for the web, so please ensure you run the correct one for your operating system (windows, mac or linux)**

2. with the emscripten SDK (emsdk) enabled, run `make -f build-scripts/<YOUR_OS, i.e windows, linux or mac>/web.Makefile` and the game should build in the `web` folder, you should be able to host this folder like any other website and play the game
