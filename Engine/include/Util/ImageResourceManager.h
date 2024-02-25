#ifndef IMAGERESOURCEMANAGER_H
#define IMAGERESOURCEMANAGER_H

#include <string>
#include <map>
#include <SDL_image.h>
class ImageResourceManager
{
public:
    static SDL_Texture *LoadImageResource(std::string key, std::string fileName, SDL_Renderer *renderer) throw();
    static SDL_Texture *GetImageResource(std::string key);
    static void DeallocateAll();
    static void RemoveImageResource(std::string key);

protected:
private:
    ImageResourceManager();
    static std::map<std::string, SDL_Texture *> m_imageResources;
};

#endif // IMAGERESOURCEMANAGER_H
