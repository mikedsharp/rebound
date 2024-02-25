#ifndef AUDIORESOURCEMANAGER_H
#define AUDIORESOURCEMANAGER_H

#include <map>
#include <string>
#ifdef _WIN32
    #include <SDL_mixer.h>
#elif __APPLE__
    #include <SDL_mixer.h>
#else
    #include <SDL2/SDL_mixer.h>
#endif
class AudioResourceManager
{
public:
    virtual ~AudioResourceManager();
    static Mix_Chunk *LoadSoundResource(std::string key, std::string fileName) throw();
    static Mix_Chunk *GetSoundResource(std::string key);
    static void RemoveSoundResource(std::string key);
    static Mix_Music *LoadMusicResource(std::string key, std::string fileName);
    static Mix_Music *GetMusicResource(std::string key);
    static void RemoveMusicResource(std::string key);

protected:
private:
    AudioResourceManager();
    static std::map<std::string, Mix_Chunk *> m_soundResources;
    static std::map<std::string, Mix_Music *> m_musicResources;
};

#endif // AUDIORESOURCEMANAGER_H
