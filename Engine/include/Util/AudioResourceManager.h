#ifndef AUDIORESOURCEMANAGER_H
#define AUDIORESOURCEMANAGER_H

#include <map>
#include <string>
class AudioResourceManager
{
public:
    virtual ~AudioResourceManager();
    static const int LoadSoundResource(std::string key, std::string fileName) throw();
    static const int GetSoundResource(std::string key);
    static void RemoveSoundResource(std::string key);

protected:
private:
    AudioResourceManager();
    static std::map<std::string, std::string> m_soundResources;
};

#endif // AUDIORESOURCEMANAGER_H
