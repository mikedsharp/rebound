#include "Util/ImageResourceManager.h"
#include <iostream>

std::map<std::string, SDL_Texture *> ImageResourceManager::m_imageResources;

ImageResourceManager::ImageResourceManager()
{
    // ctor
}

void ImageResourceManager::DeallocateAll()
{
    // for (std::map<std::string, std::string>::iterator it = m_imageResources.begin(); it != m_imageResources.end(); it++)
    // {
    //     if (it->second)
    //     {
    //         delete (it->second);
    //         (it->second) = NULL;
    //     }
    // }
    m_imageResources.clear();
}

SDL_Texture *ImageResourceManager::LoadImageResource(std::string key, std::string fileName, SDL_Renderer *renderer) throw()
{
    std::cout << "loading image resource with path: " << fileName << " and key: " << key << std::endl;
    SDL_Surface *spriteSurface = IMG_Load(fileName.c_str());
    m_imageResources[key.c_str()] = SDL_CreateTextureFromSurface(renderer, spriteSurface);
    SDL_FreeSurface(spriteSurface);
    return m_imageResources[key.c_str()];
}
SDL_Texture *ImageResourceManager::GetImageResource(std::string key)
{
    std::cout << "returning image resource with key: " << key << std::endl;
    // if the resource exists, return it, otherwise warn user and return NULL
    if (m_imageResources.count(key.c_str()) > 0)
    {
        return m_imageResources[key.c_str()];
    }
    std::cout << "Error: ImageResource with specified key does not exist." << std::endl;
    exit(EXIT_FAILURE);
}
void ImageResourceManager::RemoveImageResource(std::string key)
{
    // check if there is an ImageResource to delete, warn user if image doesnt exist
    if (m_imageResources.count(key.c_str()) > 0)
    {
        SDL_Texture *textureToDelete = m_imageResources[key.c_str()];
        m_imageResources.erase(key.c_str());
        SDL_DestroyTexture(textureToDelete);
    }
    else
    {
        std::cout << "Error: ImageResource doesn't exist, can't delete." << std::endl;
    }
}
