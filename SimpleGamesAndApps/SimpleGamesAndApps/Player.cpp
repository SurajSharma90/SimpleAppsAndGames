#include "Player.h"

Player::Player()
{
  this->shape.setFillColor(sf::Color::White);
  this->shape.setRadius(20.f);
  this->shape.setPosition(sf::Vector2f(500, 400));
  this->moveSpeed = 7.f;
  this->shootTimerMax = 20.f;
  this->shootTimer = this->shootTimerMax;
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

void Player::move(const sf::Vector2f direction)
{
  this->shape.move(moveSpeed * direction);
}

void Player::shoot(const sf::Vector2f direction)
{
  if(this->shootTimer >= this->shootTimerMax)
  {
    this->bullets.push_back(new Bullet(this->getCenter(), direction, 5.f, 20.f));
    this->shootTimer = 0.f;
  }
}

void Player::updateBullets()
{
  for (size_t i = 0; i < this->bullets.size(); i++)
  {
    this->bullets[i]->update();

    if (this->bullets[i]->canDelete())
    {
      delete this->bullets[i];
      this->bullets.erase(this->bullets.begin() + i);
      continue;
    }
  }
}

void Player::update()
{
  this->updateBullets();

  if(this->shootTimer < this->shootTimerMax)
    this->shootTimer += 1.f;
}

void Player::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
  
  for (size_t i = 0; i < this->bullets.size(); i++)
  {
    this->bullets[i]->render(target);
  }
}
