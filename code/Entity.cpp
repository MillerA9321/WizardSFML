#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Entity::Entity()
{
    maxHealth = 100;
    damageDealt = 10;
    maxSpeed = 5;
    position.x = 0;
    position.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprite/greenSlime.png"));
};

void Entity::hit()
{
    currentHealth -= 50;
}

bool Entity::isAlive()
{
    if (currentHealth > 0)
    {
        return false;
    }
    else
    {
        return true;
    } 
}

Sprite Entity::getSprite()
{
    return slimeSprite;
}


FloatRect Entity::getPosition()
{
    return slimeSprite.getGlobalBounds();
}

void Entity::updatePosition(float elapsedTime)
{
    Player player;
    position.x = player.getPlayerCoordinates().x + maxSpeed * elapsedTime;
    position.y = player.getPlayerCoordinates().y + maxSpeed * elapsedTime;
}



