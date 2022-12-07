#include "Entity.h"
#include "Player.h"
#include <SFML/Graphics.hpp>
#include <cmath>

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
        slimePosition.x = slimePosition.x + maxSpeed * elapsedTime;
    }
    
    if (playerCoord_Y > slimePosition.y)
    {
        slimePosition.y = slimePosition.y + maxSpeed * elapsedTime;
    }
    
    if (playerCoord_X < slimePosition.x)
    {
        slimePosition.x = slimePosition.y - maxSpeed * elapsedTime;
    }

    if(playerCoord_Y < slimePosition.y)
    {
        slimePosition.y = slimePosition.y - maxSpeed * elapsedTime;
    }

    slimeSprite.setPosition(slimePosition);

    float angle = (atan2(playerCoord_Y - slimePosition.y, playerCoord_X - slimePosition.x) * 180) / 3.141;
    slimeSprite.setRotation(angle);
}

void Entity::slimeSpawn(float x, float y, string slimeType)
{
    if(slimeType == "King")
    {
        KingSlime slimeKing;
        slimeSprite = slimeKing.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }

    if(slimeType == "Red")
    {
        RedSlime redSlime;
        slimeSprite = redSlime.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }

    if(slimeType == "Yellow")
    {
        YellowSlime yellowSlime;
        slimeSprite = yellowSlime.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }

    if (slimeType == "Green")
    {
        GreenSlime greenSlime;
        slimeSprite = greenSlime.getSprite();
        slimePosition.x = x;
        slimePosition.y = y;
        slimeSprite.setPosition(slimePosition);
    }
}



