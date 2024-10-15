#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Enemy
{
private:
sf::CircleShape shape;
float moveSpeed;
float rotation;
bool isDead;

public:
Enemy(sf::Vector2f position, sf::Color color, float radius, size_t point_count, float move_speed, float rotation);
~Enemy();

inline bool getIsDead() const {return this->isDead;}
inline const sf::FloatRect getGlobalBounds() const { return this->shape.getGlobalBounds(); }
const sf::Vector2f getCenter() const;
const sf::Vector2f getNormVec(sf::Vector2f fromPos) const;

void move(sf::Vector2f target_position);
void move(sf::Vector2f direction, float amount);

inline void destroy() {this->isDead = true;}

void update(sf::Vector2f target_position);

void render(sf::RenderTarget& target);

};

