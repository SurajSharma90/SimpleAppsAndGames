#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>

class Player
{
private:
  sf::CircleShape shape;
  float moveSpeed;
  std::vector<sf::CircleShape*> bullets;
  float shootTimer;
  float shootTimerMax;

public:
  Player();
  ~Player();
  
  inline const sf::Vector2f getPosition() const {return this->shape.getPosition(); }
  const sf::Vector2f getCenter() const;
  inline std::vector<sf::CircleShape*>& getBullets() { return this->bullets; };

  void move(const sf::Vector2f& direction);
  void shoot(const sf::Vector2f& direction);
  void moveBullets();

  void update();

  void render(sf::RenderTarget& target);
};

