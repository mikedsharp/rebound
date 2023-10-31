#include "Util/ImageResourceManager.h"
#include <iostream>

std::map<std::string,sf::Texture*> ImageResourceManager::m_imageResources;

ImageResourceManager::ImageResourceManager()
{
    //ctor
}

void ImageResourceManager::DeallocateAll()
{
    for(std::map<std::string,sf::Texture*>::iterator it = m_imageResources.begin(); it != m_imageResources.end();it++)
    {
        if(it->second)
        {
            delete (it->second);
            (it->second) = NULL;
        }
    }
    m_imageResources.clear();
}

const sf::Texture& ImageResourceManager::LoadImageResource(std::string key, std::string fileName)throw()
{
    // declare a new sf::Texture pointer, try and allocate it and add it to the map
    sf::Texture* newImg = NULL;
    newImg = new sf::Texture();

    // if load was successful
    if(newImg->loadFromFile(fileName))
    {
        //std::cout << "KEY:" << key.c_str() << std::endl;
        if(m_imageResources.count(key.c_str()) == 0)
        {
            // set the smooth property to false because SFML is dumb
            newImg->setSmooth(false);
            newImg->setRepeated(false);
            //newImg->createMaskFromColor(sf::Color(255,0,255));
            m_imageResources[key.c_str()] = newImg;
        }
        else
        {
            m_imageResources[key.c_str()] = newImg;
            std::cout << "Error: Object with this key already exists, returning original" << std::endl;
        }
    }
    else
    {
        std::cout << "Error: File'" << fileName.c_str() << "' not found, exiting..." << std::endl;
        exit(EXIT_FAILURE);
    }
    // return new ImageResource to the user
    return *(newImg);

}
const sf::Texture& ImageResourceManager::GetImageResource(std::string key)
{
    // if the resource exists, return it, otherwise warn user and return NULL
    if(m_imageResources.count(key.c_str()) > 0)
    {
        return *(m_imageResources[key.c_str()]);
    }
    std::cout << "Error: ImageResource with specified key does not exist." << std::endl;
    exit(EXIT_FAILURE);

}
void ImageResourceManager::RemoveImageResource(std::string key)
{
    // check if there is an ImageResource to delete, warn user if image doesnt exist
    if(m_imageResources.count(key.c_str()) > 0)
    {
        delete m_imageResources[key.c_str()];
        m_imageResources[key.c_str()] = NULL;
        m_imageResources.erase(key.c_str());

    }
    else
    {
        std::cout<< "Error: ImageResource doesn't exist, can't delete." << std::endl;
    }

}
