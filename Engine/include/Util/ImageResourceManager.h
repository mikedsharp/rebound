#ifndef IMAGERESOURCEMANAGER_H
#define IMAGERESOURCEMANAGER_H

#include<string>
#include<SFML/System.hpp>
#include<SFML/Graphics.hpp>
#include<map>
class ImageResourceManager
{
public:
    static const sf::Texture& LoadImageResource(std::string key, std::string fileName)throw();
    static const sf::Texture& GetImageResource(std::string key);
    static void DeallocateAll();
    static void RemoveImageResource(std::string key);
protected:
private:
    ImageResourceManager();
    static std::map<std::string,sf::Texture*> m_imageResources;
};

#endif // IMAGERESOURCEMANAGER_H
