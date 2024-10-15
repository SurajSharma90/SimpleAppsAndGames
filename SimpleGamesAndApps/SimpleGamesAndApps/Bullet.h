#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Bullet
{
private:
sf::CircleShape shape;
sf::Vector2f directionNorm;
float speed;
float lifeTime;

void move();

public:
Bullet(sf::Vector2f position, sf::Vector2f direction_norm, float speed, float life_time);
~Bullet();

inline const bool intersects(sf::FloatRect bounds) const { return this->shape.getGlobalBounds().intersects(bounds); }
inline const bool canDelete() const { return this->lifeTime <= 0.f; }
inline void setDelete() { this->lifeTime = 0.f; }

void update();
void render(sf::RenderTarget& target);
};

