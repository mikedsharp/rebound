#ifndef GAMESTATE_H
#define GAMESTATE_H
// includes
#include <GameEngine.h>
#include "Rendering/RenderManager.h"
#include <string>
class GameEngine;

class GameState
{
public:
    GameState(GameEngine *ge, int stateType);
    // State Interface Methods
    virtual void CheckEvent() = 0;
    virtual void UpdateLogic() = 0;
    virtual void Paint() const = 0;
    virtual void InitState() = 0;
    virtual void EndState() = 0;
    virtual void StartState() = 0;
    virtual void ExitState() = 0;
    virtual void PauseState() = 0;
    virtual void ResumeState() = 0;

    // foreign value setters
    virtual void SetInt(const std::string &key, int value) = 0;
    virtual void SetFloat(const std::string &key, float value) = 0;
    virtual void SetString(const std::string &key, const std::string &value) = 0;
    virtual void SetObject(const std::string &key, void *value) = 0;

    // check properties of state
    bool Paused() const
    {
        return m_paused;
    }
    void Paused(bool paused)
    {
        this->m_paused = paused;
    }
    int StateType() const
    {
        return m_stateType;
    }
    void EngineInstance(GameEngine *ge)
    {
        this->m_engineInstance = ge;
    }
    bool Initiated() const
    {
        return m_initiated;
    }
    void Initiated(bool init)
    {
        m_initiated = init;
    }
    virtual ~GameState();

protected:
    bool m_paused;
    GameEngine *m_engineInstance;
    int m_stateType;
    bool m_initiated;
    RenderManager m_renderManager;

private:
};

#endif // GAMESTATE_H
