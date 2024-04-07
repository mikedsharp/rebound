#ifndef RANDOMREBOUND_GAMESTATE_H
#define RANDOMREBOUND_GAMESTATE_H

#include <vector>

#include <GameState.h>
#include <Game/Ball.h>
#include <Game/Paddle.h>
#include <Game/Crate.h>
#include "Util/SoundPlayer.h"

enum themes
{
    THEME_TEMPLE,
    THEME_RETRO,
    THEME_STADIUM
};

class RandomRebound_GameState : public GameState
{
public:
    RandomRebound_GameState();
    virtual ~RandomRebound_GameState();

    // State Interface Methods
    virtual void CheckEvent();
    virtual void UpdateLogic();
    virtual void Paint() const;
    virtual void InitState();
    virtual void EndState();
    virtual void StartState();
    virtual void ExitState();
    virtual void PauseState();
    virtual void ResumeState();

    // game specific methods
    void CheckOpponentBounds();
    void PerformMove();
    void PlanMove();
    void RegenerateCrates();
    void UpdateScoreBoards();
    void ChangeTheme(int theme);

    // value  passing methods
    virtual void SetInt(const std::string &key, int value);
    virtual void SetFloat(const std::string &key, float value);
    virtual void SetString(const std::string &key, const std::string &value);
    virtual void SetObject(const std::string &key, void *value);

protected:
private:
    Ball *m_gameBall;
    Paddle *m_opponent;
    Paddle *m_player;
    GameSprite *m_backdrop;
    std::vector<Crate *> m_crates;
    int m_maxPaddleX, m_minPaddleX;
    int m_currentTheme;
    bool m_playerIsServer;
    float m_opponentsTarget;
    bool m_leftKeyState;
    bool m_rightKeyState;
    bool m_mouseButtonPressedState;

    RotatedRectangle *m_cursorBounds;

    GameSprite *m_playerScoreText;
    GameSprite *m_opponentScoreText;

    // sounds
    Mix_Chunk *m_paddleBash;
    Mix_Chunk *m_goalCheer;
};
// factor for working out where ball 'rebounds'
const float REBOUND_SCALE_FACTOR = 0.2083333333333333;

#endif // RANDOMREBOUND_GAMESTATE_H
