#ifndef GAMESTATEFACTORY_H
#define GAMESTATEFACTORY_H

#include <iostream>

// sub class forward declarations
class GameState;

enum GAME_STATES {STATE_MAINMENU, STATE_GAMEPLAYAREA_GAMELEVEL , STATE_GAMEOVER};

class GameStateFactory
{
public:
    static GameState* BuildState(int stateType);
    ~GameStateFactory();
protected:
private:
    GameStateFactory();

};




#endif // GAMESTATEFACTORY_H
