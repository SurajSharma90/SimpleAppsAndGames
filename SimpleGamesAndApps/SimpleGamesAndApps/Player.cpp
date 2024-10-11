#include "Player.h"

Player::Player()
{
  this->shape.setFillColor(sf::Color::White);
  this->shape.setRadius(20.f);
  this->shape.setPosition(sf::Vector2f(500, 400));
}

Player::~Player()
{

}

void Player::update()
{
  
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
