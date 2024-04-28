#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#ifdef _WIN32
#include <SDL_mixer.h>
#elif __APPLE__
#include <SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

class MusicPlayer
{
    static bool m_musicPlaying;

public:
    MusicPlayer();
    ~MusicPlayer();
    static void Play(Mix_Music *musicToPlay, bool loop);
    static bool MusicPlaying() { return m_musicPlaying; };
    static void MusicPlaying(bool value) { m_musicPlaying = value; };
    static void ToggleMusic();
    static void Mute();
    static void Unmute();

protected:
private:
};

#endif // MUSICPLAYER_H