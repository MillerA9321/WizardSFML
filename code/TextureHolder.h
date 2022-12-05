#pragma once
#include <SFML/Graphics.hpp>
#include <map>

using namespace std;
using namespace sf;

class TextureHolder
{
    private:
    map< string, Texture> m_Textures;
    static TextureHolder* m_Instance;

    public:
    TextureHolder();
    static Texture& getTexture(string const& filename);
};