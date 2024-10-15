#pragma once

#include "Bullet.h"
#include <vector>
#include <iostream>

class Player
{
private:
  sf::CircleShape shape;
  float moveSpeed;
  std::vector<Bullet*> bullets;
  float shootTimer;
  float shootTimerMax;

public:
  Player();
  ~Player();
  
  inline const sf::Vector2f getPosition() const {return this->shape.getPosition(); }
  const sf::Vector2f getCenter() const;
  inline std::vector<Bullet*>& getBullets() { return this->bullets; };

  void move(const sf::Vector2f direction);
  void shoot(const sf::Vector2f direction);
  void updateBullets();

  void update();

  void render(sf::RenderTarget& target);
};

