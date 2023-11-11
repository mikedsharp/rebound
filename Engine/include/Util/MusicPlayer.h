#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <SDL_mixer.h>

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