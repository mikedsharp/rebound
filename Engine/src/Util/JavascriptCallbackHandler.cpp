#include "Util/JavascriptCallbackHandler.h"
#include "Util/MusicPlayer.h"
#include "Util/SoundPlayer.h"
#ifdef __EMSCRIPTEN__
void JavascriptCallbackHandler::ToggleMusic(emscripten::val cb)
{
    MusicPlayer::ToggleMusic();
    cb(MusicPlayer::MusicPlaying());
}
void JavascriptCallbackHandler::MuteMasterVolume(emscripten::val cb)
{
    MusicPlayer::Mute();
    SoundPlayer::Mute();
    cb(true);
}
void JavascriptCallbackHandler::UnmuteMasterVolume(emscripten::val cb)
{
    MusicPlayer::Unmute();
    SoundPlayer::Unmute();
    cb(true);
}
#endif
