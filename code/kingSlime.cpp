#include "Entity.h"

KingSlime::KingSlime()
{
    maxHealth = 300;
    currentHealth = maxHealth;
    damageDealt = 20;
    maxSpeed = 3;
    position.x = 0;
    position.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprite/kingSlime.png"));
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

