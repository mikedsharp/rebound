#include "Util/AudioResourceManager.h"
#include <iostream>

std::map<std::string, Mix_Chunk *> AudioResourceManager::m_soundResources;
std::map<std::string, Mix_Music *> AudioResourceManager::m_musicResources;

AudioResourceManager::AudioResourceManager()
{
    // ctor
}

AudioResourceManager::~AudioResourceManager()
{
    // dtor
}

Mix_Music *AudioResourceManager::LoadMusicResource(std::string key, std::string fileName)
{
    Mix_Music *soundToLoad = NULL;
    soundToLoad = Mix_LoadMUS(fileName.c_str());
    if (soundToLoad == NULL)
    {
        printf("Failed to load %s music! SDL_mixer Error: %s\n", key.c_str(), Mix_GetError());
    }
    if (m_musicResources.count(key.c_str()) == 0)
    {
        m_musicResources[key.c_str()] = soundToLoad;
    }
    return m_musicResources[key.c_str()];
}

Mix_Music *AudioResourceManager::GetMusicResource(std::string key)
{
    return m_musicResources[key.c_str()];
}

void AudioResourceManager::RemoveMusicResource(std::string key)
{
    // check if there is an ImageResource to delete, warn user if image doesnt exist
    if (m_musicResources.count(key.c_str()) > 0)
    {
        Mix_FreeMusic(m_musicResources[key.c_str()]);
        m_musicResources[key.c_str()] = NULL;
        m_musicResources.erase(key.c_str());
    }
    else
    {
        std::cout << "Error: Sound Resource doesn't exist, can't delete." << std::endl;
    }
}

Mix_Chunk *AudioResourceManager::LoadSoundResource(std::string key, std::string fileName) throw()
{
    // if load was successful
    if (m_soundResources.count(key.c_str()) == 0)
    {
        m_soundResources[key.c_str()] = Mix_LoadWAV(fileName.c_str());
    }
    else
    {
        std::cout << "Error: Object with this key already exists, returning original" << std::endl;
    }
    return m_soundResources[key.c_str()];
}
Mix_Chunk *AudioResourceManager::GetSoundResource(std::string key)
{
    // if the resource exists, return it, otherwise warn user and return NULL
    if (m_soundResources.count(key.c_str()) > 0)
    {
        return m_soundResources[key.c_str()];
    }
    std::cout << "Error: ImageResource with specified key does not exist." << std::endl;
    exit(EXIT_FAILURE);
}
void AudioResourceManager::RemoveSoundResource(std::string key)
{
    // check if there is an ImageResource to delete, warn user if image doesnt exist
    if (m_soundResources.count(key.c_str()) > 0)
    {
        delete m_soundResources[key.c_str()];
        m_soundResources[key.c_str()] = NULL;
        m_soundResources.erase(key.c_str());
    }
    else
    {
        std::cout << "Error: Sound Resource doesn't exist, can't delete." << std::endl;
    }
}
