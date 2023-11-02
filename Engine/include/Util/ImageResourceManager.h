#ifndef IMAGERESOURCEMANAGER_H
#define IMAGERESOURCEMANAGER_H

#include <string>
#include <map>
class ImageResourceManager
{
public:
    static const int LoadImageResource(std::string key, std::string fileName) throw();
    static const int GetImageResource(std::string key);
    static void DeallocateAll();
    static void RemoveImageResource(std::string key);

protected:
private:
    ImageResourceManager();
    static std::map<std::string, std::string> m_imageResources;
};

#endif // IMAGERESOURCEMANAGER_H
