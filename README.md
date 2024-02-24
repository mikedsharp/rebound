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
3. run `make -f windows.Makefile` and the game will build into the `bin` folder, you will need to keep an `assets` folder within the `bin` folder containing all of the assets (i.e. the graphics and sound) and you will need all of the SDL2 DLLs in the `bin` folder, too (these are `SDL2.dll`, `SDL2_image.dll` and `SDL2_mixer.dll`)

## Building for web

1. Please follow the tutorial for installing the emscripten SDK locally for your operating system, docs can be found at: https://emscripten.org/docs/getting_started/downloads.html
2. with the emscripten SDK (emsdk) enabled, run `make -f web.Makefile` and the game should build in the `web` folder, you should be able to host this folder like any other website and play the game
