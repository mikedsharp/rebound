#include "Util/ImageResourceManager.h"
#include <iostream>

std::map<std::string, std::string> ImageResourceManager::m_imageResources;

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

const int ImageResourceManager::LoadImageResource(std::string key, std::string fileName) throw()
{
    std::cout << "loading image resource with path: " << fileName << " and key: " << key << std::endl;
    m_imageResources[key.c_str()] = fileName;
    return 0;
}
const int ImageResourceManager::GetImageResource(std::string key)
{
    std::cout << "returning image resource with key: " << key << std::endl;
    // if the resource exists, return it, otherwise warn user and return NULL
    if (m_imageResources.count(key.c_str()) > 0)
    {
        return 0;
    }
    std::cout << "Error: ImageResource with specified key does not exist." << std::endl;
    exit(EXIT_FAILURE);
}
void ImageResourceManager::RemoveImageResource(std::string key)
{
    // check if there is an ImageResource to delete, warn user if image doesnt exist
    if (m_imageResources.count(key.c_str()) > 0)
    {
        // delete m_imageResources[key.c_str()];
        // m_imageResources[key.c_str()] = NULL;
        m_imageResources.erase(key.c_str());
    }
    else
    {
        std::cout << "Error: ImageResource doesn't exist, can't delete." << std::endl;
    }
}
