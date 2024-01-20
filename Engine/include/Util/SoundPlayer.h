#ifndef SOUNDPLAYERLAYER_H
#define SOUNDPLAYERLAYER_H

#include <SDL_mixer.h>

class SoundPlayer
{
public:
    SoundPlayer();
    ~SoundPlayer();
    static void Play(Mix_Chunk *soundToPlay, bool loop);

protected:
private:
};

#endif // SOUNDPLAYERLAYER_H