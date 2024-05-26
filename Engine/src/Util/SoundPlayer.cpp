#include "Util/SoundPlayer.h"

void SoundPlayer::Play(Mix_Chunk *soundToPlay, bool loop)
{
    Mix_PlayChannel(-1, soundToPlay, 0);
}
void SoundPlayer::Mute()
{
    Mix_Volume(-1, 0);
}
void SoundPlayer::Unmute()
{
    Mix_Volume(-1, MIX_MAX_VOLUME);
}