#include "Player.h"

Player::Player()
{
  this->shape.setFillColor(sf::Color::White);
  this->shape.setRadius(20.f);
  this->shape.setPosition(sf::Vector2f(500, 400));
  this->moveSpeed = 7.f;
}

Player::~Player()
{
  for (size_t i = 0; i < this->bullets.size(); i++)
  {
    delete this->bullets[i];
  }
}

const sf::Vector2f Player::getCenter() const
{
  return sf::Vector2f(this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f, this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f);
}

void Player::move(const sf::Vector2f& direction)
{
  this->shape.move(moveSpeed * direction);
}

void Player::shoot(const sf::Vector2f& direction)
{
  
}

void Player::moveBullets()
{

}

void Player::update()
{
  
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
