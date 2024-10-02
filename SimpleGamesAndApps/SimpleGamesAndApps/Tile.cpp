#include "Tile.h"

Tile::Tile()
{ 
  this->active = false;
  this->pressed = false;
  this->alphaIdle = 0.f;
  this->alphaHover = 0.f;
  this->alphaPressed = 0.f;
}

Tile::Tile(sf::Vector2f position, float size, bool active)
{
  this->active = active;
  this->colorActive = sf::Color::Green;
  this->colorInactive = sf::Color::Red;
  this->shape.setFillColor(this->colorInactive);
  this->shape.setSize(sf::Vector2f(size, size));
  this->shape.setOutlineThickness(2.f);
  this->shape.setOutlineColor(sf::Color::White);
  this->alphaIdle = 100;
  this->alphaHover = 255;
  this->alphaPressed = 50;
  this->pressed = false;
  this->shape.setPosition(position);
}

Tile::~Tile()
{
}

void Tile::update(const sf::Vector2f& mousePosView, const bool lmb_pressed)
{
  this->pressed = false;

  if (this->shape.getGlobalBounds().contains(mousePosView))
  {
    this->shape.setFillColor(sf::Color(this->shape.getFillColor().r, this->shape.getFillColor().g, this->shape.getFillColor().b, this->alphaHover));

    if (lmb_pressed)
    {
      this->shape.setFillColor(sf::Color(this->shape.getFillColor().r, this->shape.getFillColor().g, this->shape.getFillColor().b, this->alphaPressed));
      this->pressed = true;
    }
  }
  else
  {
    this->shape.setFillColor(sf::Color(this->shape.getFillColor().r, this->shape.getFillColor().g, this->shape.getFillColor().b, this->alphaIdle));
  }
}

void Tile::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
