#include "Entity.h"
#include "Player.h"

Entity::Entity()
{
    maxHealth = 100;
    damageDealt = 10;
    maxSpeed = 5;
    position.x = 0;
    position.y = 0;
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
}

Vector2f Entity::getPosition()
{
    return position;
}

void Entity::updatePosition()
{
    Player player;
    position.x = player.getPlayerCoordinates().x;
    position.y = player.getPlayerCoordinates().y;

}