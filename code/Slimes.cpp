/**#include "Entity.h"

//Initizialize KingSlime
KingSlime::KingSlime()
{
    maxHealth = 300;
    currentHealth = maxHealth;
    damageDealt = 20;
    maxSpeed = 3;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/kingSlime.png"));
}

bool KingSlime::spawnRate(float timeElapsed) 
{
    int spawn = timeElapsed;

    if (spawn % 60 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Sprite KingSlime::getSprite()
{
    return slimeSprite;
}

//Initialize GreenSlime
GreenSlime::GreenSlime()
{
    maxHealth = 100;
    currentHealth = maxHealth;
    damageDealt = 20;
    maxSpeed = 3;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/greenSlime.png"));
}

bool GreenSlime::spawnRate(float timeElapsed) 
{
    int spawn = timeElapsed;

    if (spawn % 60 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Sprite GreenSlime::getSprite()
{
    return slimeSprite;
}

//Initialize RedSLime()
//
RedSlime::RedSlime()
{
    maxHealth = 100;
    currentHealth = maxHealth;
    damageDealt = 20;
    maxSpeed = 5;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/redSlime.png"));
}

bool RedSlime::spawnRate(float timeElapsed) 
{
    int spawn = timeElapsed;

    if (spawn % 60 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

**/