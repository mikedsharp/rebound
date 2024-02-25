#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#ifdef _WIN32
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL_mixer.h>
#endif

class MusicPlayer
{
public:
    MusicPlayer();
    ~MusicPlayer();
    static void Play(Mix_Music *musicToPlay, bool loop);

protected:
private:
};

#endif // MUSICPLAYER_H