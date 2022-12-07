/**#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>

Entity::Entity()
{
    maxHealth = 100;
    damageDealt = 10;
    maxSpeed = 5;
    slimePosition.x = 0;
    slimePosition.y = 0;
    slimeSprite = Sprite(TextureHolder::getTexture("sprites/greenSlime.png"));
}

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
    float playerCoord_X, playerCoord_Y;
    playerCoord_X = player.getPlayerCoordinates().x;
    playerCoord_Y = player.getPlayerCoordinates().y;

    if (playerCoord_X > slimePosition.x)
    {
        slimePosition.x = player.getPlayerCoordinates().x + maxSpeed * elapsedTime;
    }
    
    if (playerCoord_Y > slimePosition.y)
    {
        slimePosition.y = player.getPlayerCoordinates().y + maxSpeed * elapsedTime;
    }
    
    if (playerCoord_X < slimePosition.x)
    {
        slimePosition.x = player.getPlayerCoordinates().x - maxSpeed * elapsedTime;
    }

    if(playerCoord_Y < slimePosition.y)
    {
        slimePosition.y = player.getPlayerCoordinates().y - maxSpeed * elapsedTime;
    }
}



**/