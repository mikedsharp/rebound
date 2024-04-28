#include "Util/MusicPlayer.h"

bool MusicPlayer::m_musicPlaying = true;

void MusicPlayer::Play(Mix_Music *musicToPlay, bool loop)
{
    Mix_PlayMusic(musicToPlay, loop ? -1 : 1);
}
void MusicPlayer::Mute()
{
    Mix_VolumeMusic(0);
    MusicPlayer::MusicPlaying(false);
}
void MusicPlayer::Unmute()
{
    Mix_VolumeMusic(MIX_MAX_VOLUME);
    MusicPlayer::MusicPlaying(true);
}
void MusicPlayer::ToggleMusic()
{
    if (!MusicPlayer::MusicPlaying())
    {
        Mix_VolumeMusic(MIX_MAX_VOLUME);
        MusicPlayer::MusicPlaying(true);
    }
    else
    {
        Mix_VolumeMusic(0);
        MusicPlayer::MusicPlaying(false);
    }
}