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
    Vector2f position;
};

class KingSlime: public Entity
{
    public:
    KingSlime();
    bool spawnRate(float timeElapsed);
    Sprite getSprite();

    private:
    float currentHealth;
};

