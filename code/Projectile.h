#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile
{
public:
    // The constructor
    Projectile();
    // Stop the projectile
    void stop();
    // Returns the value of m_InFlight
    bool isInFlight();
    // Launch a new projectile
    void shoot(float startX, float startY, float xTarget, float yTarget);
    // Tell the calling code where the projectile is in the world
    FloatRect getPosition();
    // Return the actual shape (for drawing)
    RectangleShape getShape();
    // Update the bullet each frame
    void update(float elapsedTime);
private:
    // Projectile location
    Vector2f m_Position;
    // What each projectile looks like
    RectangleShape m_ProjectileShape;
    // Is this projectile currently whizzing through the air
    bool m_InFlight = false;
    // How fast does a projectile travel?
    float m_ProjectileSpeed = 1000;
    // What fraction of 1 pixel does the projectile travel, 
    // Horizontally and vertically each frame?
    // These values will be derived from m_ProjectileSpeed
    float m_ProjectileDistanceX;
    float m_ProjectileDistanceY;

    // Some boundaries so the projectile doesn't fly forever
    float m_MaxX;
    float m_MinX;
    float m_MaxY;
    float m_MinY;
};