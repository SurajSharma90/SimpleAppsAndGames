#include "Bullet.h"

Bullet::Bullet(sf::Vector2f position, sf::Vector2f direction_norm, float speed, float life_time)
{
  this->shape.setFillColor(sf::Color::Red);
  this->shape.setRadius(5.f);
  this->shape.setPosition(position);
  this->directionNorm = direction_norm;
  this->speed = speed;
  this->lifeTime = life_time;
}

Bullet::~Bullet()
{
}

void Bullet::move()
{
  this->shape.move(directionNorm.x * this->speed, directionNorm.y * this->speed);
}

void Bullet::update()
{
  this->move();

  if(this->lifeTime > 0.f)
    this->lifeTime -= 1.f;
}

void Bullet::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
