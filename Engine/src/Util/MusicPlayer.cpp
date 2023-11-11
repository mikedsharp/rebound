#include "Util/MusicPlayer.h"

void MusicPlayer::Play(Mix_Music *musicToPlay, bool loop)
{
    Mix_PlayMusic(musicToPlay, loop ? -1 : 1);
}