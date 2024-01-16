#include "Util/SoundPlayer.h"

void SoundPlayer::Play(Mix_Chunk *soundToPlay, bool loop)
{
    Mix_PlayChannel(-1, soundToPlay, 0);
}