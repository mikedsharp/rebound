#ifndef AUDIORESOURCEMANAGER_H
#define AUDIORESOURCEMANAGER_H

#include<SFML/System.hpp>
#include<SFML/Audio.hpp>
#include<map>
class AudioResourceManager
{
    public:
        virtual ~AudioResourceManager();
        static const sf::SoundBuffer& LoadSoundResource(std::string key, std::string fileName)throw();
        static const sf::SoundBuffer& GetSoundResource(std::string key);
        static void RemoveSoundResource(std::string key);
    protected:
    private:
        AudioResourceManager();
        static std::map<std::string, sf::SoundBuffer*> m_soundResources;
};

#endif // AUDIORESOURCEMANAGER_H
