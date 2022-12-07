#include "Entity.h"

//Initizialize KingSlime
KingSlime::KingSlime()
{
    maxHealth = 300;
    currentHealth = maxHealth;
    damageDealt = 20;
    maxSpeed = 20;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/kingSlime.png"));
    slimeSprite.setOrigin(256, 256);

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
    maxSpeed = 40;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/greenSlime.png"));
    slimeSprite.setOrigin(64, 64);
}

bool GreenSlime::spawnRate(float timeElapsed) 
{
    int spawn = timeElapsed;

    if (spawn % 1 == 0)
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
    damageDealt = 70;
    maxSpeed = 5;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/redSlime.png"));
    slimeSprite.setOrigin(64, 64);
}

Sprite RedSlime::getSprite()
{
    return slimeSprite;
}

bool RedSlime::spawnRate(float timeElapsed) 
{
    int spawn = timeElapsed;

    if (spawn % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//Initialize Yellow Slime
YellowSlime::YellowSlime()
{
    maxHealth = 100;
    currentHealth = maxHealth;
    damageDealt = 20;
    maxSpeed = 50;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/yellowSlime.png"));
    slimeSprite.setOrigin(64, 64);
}

Sprite YellowSlime::getSprite()
{
    return slimeSprite;
}
bool YellowSlime::spawnRate(float timeElapsed) 
{
    int spawn = timeElapsed;

    if (spawn % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}