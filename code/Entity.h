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

    protected:
    
    float maxHealth;
    float maxSpeed;
    float damage;
};

class Player: public Entity
{
    public:
    
    Player();
    void getPlayerPosition();


    private:
    
    Vector2f playerPosition;
    float currentHealth;
};