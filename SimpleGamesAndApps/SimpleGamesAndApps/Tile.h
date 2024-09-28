#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

enum TILE_TYPES{INACTIVE=0, ACTIVE=1};

class Tile
{
  private:
  sf::Sprite shape;
  sf::Texture* texture;
  short type;
  bool visible;

  public:
  Tile();
  Tile(sf::Vector2f position, sf::Texture* texture, short type);
  ~Tile();

  const bool isPressed(const sf::Vector2f& mousePosView);

  void setPosition(const sf::Vector2f& position);
  void inline setVisible(const bool visible) {this->visible = visible;}
  
  void show();

  void update();
  void render(sf::RenderTarget& target);
};

