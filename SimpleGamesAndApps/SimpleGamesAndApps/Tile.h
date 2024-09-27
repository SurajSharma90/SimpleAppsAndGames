#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Tile
{
  private:
  sf::Sprite shape;
  sf::Texture* texture;
  short type;
  bool visible;

  public:
  Tile();
  Tile(sf::Texture* texture);
  ~Tile();

  const bool isPressed(const sf::Vector2f& mousePosView);

  void setPosition(const sf::Vector2f& position);
  
  void show();

  void update();
  void render(sf::RenderTarget& target);
};

