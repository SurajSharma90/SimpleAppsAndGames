#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player
{
private:
  sf::CircleShape shape;
  float moveSpeed;

public:
  Player();
  ~Player();
  
  inline const sf::Vector2f getPosition() const {return this->shape.getPosition(); }
  const sf::Vector2f getCenter() const;

  void move(const sf::Vector2f& direction);

  void update();

  void render(sf::RenderTarget& target);

};

