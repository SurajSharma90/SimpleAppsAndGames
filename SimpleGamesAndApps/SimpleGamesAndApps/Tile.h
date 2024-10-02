#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Tile
{
  private:
  sf::RectangleShape shape;
  sf::Color colorInactive;
  sf::Color colorActive;
  sf::Uint8 alphaIdle;
  sf::Uint8 alphaHover;
  sf::Uint8 alphaPressed;
  bool active;
  bool pressed;

  public:
  Tile();
  Tile(sf::Vector2f position, float size, bool active);
  ~Tile();

  inline const bool isPressed() {return this->pressed;}

  inline void setActive(const bool active) {this->active = active;}
  inline void setColorInactive() {this->shape.setFillColor(this->colorInactive); }
  inline void setColorActive() {this->shape.setFillColor(this->colorActive); }

  inline const bool getActive() const {return this->active;}

  void update(const sf::Vector2f& mousePosView, const bool lmb_pressed);
  void render(sf::RenderTarget& target);
};

