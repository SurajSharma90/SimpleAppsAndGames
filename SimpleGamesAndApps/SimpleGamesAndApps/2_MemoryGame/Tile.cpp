#include "Tile.h"

Tile::Tile()
{
  this->active = false;
  this->pressed = false;
  this->alphaIdle = 0;
  this->alphaHover = 0;
  this->alphaPressed = 0;
}

Tile::Tile(sf::Vector2f position, float size, bool active)
{
  this->colorActive = sf::Color::Green;
  this->colorInactive = sf::Color::Red;
  this->shape.setSize(sf::Vector2f(size, size));
  this->shape.setFillColor(this->colorInactive);
  this->shape.setPosition(position);
  this->shape.setOutlineThickness(2.f);
  this->shape.setOutlineColor(sf::Color::White);
  this->active = active;
  this->pressed = false;
  this->alphaIdle = 100;
  this->alphaHover = 255;
  this->alphaPressed = 50;
}

Tile::~Tile()
{
}

void Tile::update(sf::Vector2f& mousePosView, const bool lmb_pressed)
{
  this->pressed = false;
  const sf::Color sc = this->shape.getFillColor();

  if (this->shape.getGlobalBounds().contains(mousePosView)) //Hover
  {
    this->shape.setFillColor(sf::Color(sc.r, sc.g, sc.b, this->alphaHover));
    if (lmb_pressed) //Mouse click
    {
      this->shape.setFillColor(sf::Color(sc.r, sc.g, sc.b, this->alphaPressed));
      this->pressed = true;
    }
  }
  else //Idle
  {
    this->shape.setFillColor(sf::Color(sc.r, sc.g, sc.b, this->alphaIdle));
  }
}

void Tile::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
