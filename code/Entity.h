#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#include "TextureHolder.h"
#pragma once

using namespace sf;
using namespace std;

class Entity
{
    public:

    Entity();
    void hit();
    bool isAlive();
    bool spawnRate(float timeElapsed);
    FloatRect getPosition();
    void updatePosition(float elapsedTime);
    Sprite getSprite();

    protected:
    Sprite slimeSprite;
    float currentHealth;
    float maxHealth;
    float maxSpeed;
    float damageDealt;
    Vector2f slimePosition;
};

class KingSlime: public Entity
{
    public:
    KingSlime();
    bool spawnRate(float timeElapsed);
    Sprite getSprite();

    private:
    
};

class GreenSlime: public Entity
{
    public:
    GreenSlime();
    bool spawnRate(float timeElapsed);
    Sprite getSprite();

    private:
    
};

class RedSlime: public Entity
{
    public:
    RedSlime();
    bool spawnRate(float timeElapsed);
    Sprite getSprite();

    private:
    
};

class YellowSlime: public Entity
{
    public:
    YellowSlime();
    bool spawnRate(float timeElapsed);
    Sprite getSprite();

    private:
};


