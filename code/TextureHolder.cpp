#include "TextureHolder.h"
#include <assert.h>

TextureHolder* TextureHolder::m_Instance = nullptr;

TextureHolder::TextureHolder()
{
    assert(m_Instance == nullptr);
    m_Instance = this;
}

Texture& TextureHolder::getTexture(string const& filename)
{
    auto& m = m_Instance->m_Textures;
    auto keyValuePair = m.find(filename);

    if (keyValuePair != m.end())
    {
        return keyValuePair -> second;
    }

    else
    {
        auto& texture = m[filename];
        texture.loadFromFile(filename);

        return texture;
    }
    
}