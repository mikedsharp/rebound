#ifndef MAINMENUSTATE_H
#define MAINMENUSTATE_H

// #include<SFML/Audio.hpp>
#include <SDL_mixer.h>
#include "Util/MusicPlayer.h"
#include <GameState.h>
#include "Game/Tile.h"

class MainMenuState : public GameState
{
public:
    MainMenuState();
    virtual ~MainMenuState();

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
    std::string m_titleText;
    // sf::Font m_titleFont;
    GameSprite *m_titlescreen;
    Mix_Music *m_theme;
};

#endif // MAINMENUSTATE_H
