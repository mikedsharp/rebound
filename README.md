# rebound
A Game I made back in 2012 or 2013, for a competition in C++

**UPDATE**: The game is buildable again! I upgraded it to use SFML 2.6.0 and i've provided executables for Windows, I will shortly have builds for Linux and Mac (hopefully)

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
