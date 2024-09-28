#include "Tile.h"

Tile::Tile()
{
  this->texture = nullptr;
  this->visible = false;
  this->type = -1;
}

Tile::Tile(sf::Vector2f position, sf::Texture* texture, short type)
{
  this->type = type;
  this->texture = texture;
  this->shape.setTexture(*this->texture);
  this->visible = false;
}

Tile::~Tile()
{
}

const bool Tile::isPressed(const sf::Vector2f& mousePosView)
{
  return false;
}

void Tile::setPosition(const sf::Vector2f& position)
{
}

void Tile::show()
{
}

void Tile::update()
{
}

void Tile::render(sf::RenderTarget& target)
{
}
