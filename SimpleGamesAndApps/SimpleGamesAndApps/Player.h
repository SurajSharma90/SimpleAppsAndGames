#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Player
{
private:
  sf::CircleShape shape;

public:
  Player();
  ~Player();

  void update();

  void render(sf::RenderTarget& target);

};

