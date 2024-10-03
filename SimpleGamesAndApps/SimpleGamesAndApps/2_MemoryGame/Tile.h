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

  inline const bool isPressed() const { return this->pressed; }
  inline const bool isActive() const { return this->active; }

  inline void setActive(const bool active) { this->active = active; }
  inline void setColorInactive() {this->shape.setFillColor(this->colorInactive); }
  inline void setColorActive() {this->shape.setFillColor(this->colorActive); }

  void update(sf::Vector2f& mousePosView, const bool lmb_pressed);
  void render(sf::RenderTarget& target);
};

