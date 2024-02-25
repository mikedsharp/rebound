#ifndef SOUNDPLAYERLAYER_H
#define SOUNDPLAYERLAYER_H

#ifdef _WIN32
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL_mixer.h>
#endif

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