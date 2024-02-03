#ifndef GAMEOVERSTATE_H
#define GAMEOVERSTATE_H

#include <GameState.h>
#include <string>
#include "Rendering/GameSprite.h"
#include "Util/Rect.h"
#include "Util/Point.h"

class GameOverState : public GameState
{
public:
    GameOverState();
    virtual ~GameOverState();

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

    // value  passing methods
    virtual void SetInt(const std::string &key, int value);
    virtual void SetFloat(const std::string &key, float value);
    virtual void SetString(const std::string &key, const std::string &value);
    virtual void SetObject(const std::string &key, void *value);

protected:
private:
    int m_playerScore;
    int m_victory;

    GameSprite *m_backdrop;
};

#endif // GAMEOVERSTATE_H
