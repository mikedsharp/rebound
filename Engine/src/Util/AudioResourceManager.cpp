#include "Util/AudioResourceManager.h"
#include <iostream>

std::map<std::string, std::string> AudioResourceManager::m_soundResources;

AudioResourceManager::AudioResourceManager()
{
    // ctor
}

AudioResourceManager::~AudioResourceManager()
{
    // dtor
}

const int AudioResourceManager::LoadSoundResource(std::string key, std::string fileName) throw()
{
    // declare a new sf::Texture pointer, try and allocate it and add it to the map
    // sf::SoundBuffer *newSnd = NULL;
    // newSnd = new sf::SoundBuffer();

    // if load was successful
    if (m_soundResources.count(key.c_str()) == 0)
    {
        // set the smooth property to false because SFML is dumb
        m_soundResources[key.c_str()] = fileName;
    }
    else
    {
        m_soundResources[key.c_str()] = fileName;
        std::cout << "Error: Object with this key already exists, returning original" << std::endl;
    }
    // if (newSnd->loadFromFile(fileName))
    // {
    //     if (m_soundResources.count(key.c_str()) == 0)
    //     {
    //         // set the smooth property to false because SFML is dumb
    //         m_soundResources[key.c_str()] = fileName;
    //     }
    //     else
    //     {
    //         m_soundResources[key.c_str()] = fileName;
    //         std::cout << "Error: Object with this key already exists, returning original" << std::endl;
    //     }
    // }
    // else
    // {
    //     std::cout << "Error: File'" << fileName.c_str() << "' not found, exiting..." << std::endl;
    //     exit(EXIT_FAILURE);
    // }
    // return new ImageResource to the user
    return 0;
}
const int AudioResourceManager::GetSoundResource(std::string key)
{
    // if the resource exists, return it, otherwise warn user and return NULL
    if (m_soundResources.count(key.c_str()) > 0)
    {
        // return *(m_soundResources[key.c_str()]);
        return 0;
    }
    std::cout << "Error: ImageResource with specified key does not exist." << std::endl;
    exit(EXIT_FAILURE);
}
void AudioResourceManager::RemoveSoundResource(std::string key)
{
    // check if there is an ImageResource to delete, warn user if image doesnt exist
    if (m_soundResources.count(key.c_str()) > 0)
    {
        // delete m_soundResources[key.c_str()];
        // m_soundResources[key.c_str()] = NULL;
        m_soundResources.erase(key.c_str());
    }
    else
    {
        std::cout << "Error: Sound Resource doesn't exist, can't delete." << std::endl;
    }
}
