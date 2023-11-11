#ifndef AUDIORESOURCEMANAGER_H
#define AUDIORESOURCEMANAGER_H

#include <map>
#include <string>
#include <SDL_mixer.h>
class AudioResourceManager
{
public:
    virtual ~AudioResourceManager();
    static const int LoadSoundResource(std::string key, std::string fileName) throw();
    static const int GetSoundResource(std::string key);
    static void RemoveSoundResource(std::string key);
    static Mix_Music *LoadMusicResource(std::string key, std::string fileName);
    static Mix_Music *GetMusicResource(std::string key);
    static void RemoveMusicResource(std::string key);

protected:
private:
    AudioResourceManager();
    static std::map<std::string, std::string> m_soundResources;
    static std::map<std::string, Mix_Music *> m_musicResources;
};

#endif // AUDIORESOURCEMANAGER_H
