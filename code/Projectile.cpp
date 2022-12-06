#include "Projectile.h"
#include <cmath>

Projectile::Projectile()
{
    m_ProjectileShape.setSize(sf::Vector2f(2, 2));
}

void Projectile::shoot(float startX, float startY, float targetX, float targetY)
{
    // Keep track of the projectile
    m_InFlight = true;
    m_Position.x = startX;
    m_Position.y = startY;
    // Calculate the gradient of the flight path
    float gradient = (startX - targetX) / (startY - targetY);
    // Any gradient less than 0 needs to be negative
    if (gradient < 0)
    {
        gradient *= -1;
    }
    // Calculate the ratio between x and y
    float ratioXY = m_ProjectileSpeed / (1 + gradient);
    // Set the "speed" horizontally and vertically
    m_ProjectileDistanceY = ratioXY;
    m_ProjectileDistanceX = ratioXY * gradient;

    // Point the projectile in the right direction
    if (targetX < startX)
    {
        m_ProjectileDistanceX *= -1;
    }
    if (targetY < startY)
    {
        m_ProjectileDistanceY *= -1;
    }

    // Set a max range of 1000 pixels
    float range = 1000;
    m_MinX = startX - range;
    m_MaxX = startX + range;
    m_MinY = startY - range;
    m_MaxY = startY + range;

    // Position the projectile ready to be drawn
    m_ProjectileShape.setPosition(m_Position);
}

void Projectile::stop()
{
    m_InFlight = false;
}
bool Projectile::isInFlight()
{
    return m_InFlight;
}
FloatRect Projectile::getPosition()
{
    return m_ProjectileShape.getGlobalBounds();
}
RectangleShape Projectile::getShape()
{
    return m_ProjectileShape;
}

void Projectile::update(float elapsedTime)
{
    // Update the Projectile position variables
    m_Position.x += m_ProjectileDistanceX * elapsedTime;
    m_Position.y += m_ProjectileDistanceY * elapsedTime;
    // Move the Projectile
    m_ProjectileShape.setPosition(m_Position);
    // Has the Projectile gone out of range?
    if (m_Position.x < m_MinX || m_Position.x > m_MaxX || m_Position.y < m_MinY || m_Position.y > m_MaxY)
    {
        m_InFlight = false;
    }
}