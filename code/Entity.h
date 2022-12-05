#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <vector>
#pragma once

using namespace sf;
using namespace std;

class Entity
{
    public:

    Entity();
    bool hit();
    bool isAlive();
    virtual bool spawnRate(Clock timeElapsed);
    Vector2f getPosition();
    void updatePosition();
    Sprite getSprite();

    protected:
    
    float maxHealth;
    float maxSpeed;
    float damageDealt;
    Vector2f position;
};

class GreenSlime: public Entity
{
    public:
    GreenSlime();
    bool spawnRate(Clock timeElapsed) override;

    private:
    float currentHealth;
};

