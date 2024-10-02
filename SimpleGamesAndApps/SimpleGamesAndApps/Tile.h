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
  bool visible;
  bool pressed;

  public:
  Tile();
  Tile(sf::Vector2f position, float size, bool active);
  ~Tile();

  inline const bool isPressed() {return this->pressed;}

  inline void setPosition(const sf::Vector2f& position) {this->shape.setPosition(position); }
  inline void setVisible(const bool visible) {this->visible = visible;}
  inline void setActive(const bool active) {this->active = active;}
  inline void setColorInactive() {this->shape.setFillColor(this->colorInactive); }
  inline void setColorActive() {this->shape.setFillColor(this->colorActive); }

  inline const bool checkVisible() const {return this->visible;}
  inline const bool getActive() const {return this->active;}

  void update(const sf::Vector2f& mousePosView, const bool lmb_pressed);
  void render(sf::RenderTarget& target);
};

