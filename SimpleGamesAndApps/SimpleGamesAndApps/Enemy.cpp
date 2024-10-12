#include "Enemy.h"

Enemy::Enemy(sf::Vector2f position, sf::Color color, float radius, size_t point_count, float move_speed, float rotation)
{
  this->shape.setRadius(radius);
  this->shape.setPosition(position);
  this->shape.setFillColor(color);
  this->shape.setPointCount(point_count);
  this->moveSpeed = move_speed;
  this->rotation = rotation;
  this->isDead = false;
}

Enemy::~Enemy()
{
}

void Enemy::move(sf::Vector2f target_position)
{
  sf::Vector2f center = sf::Vector2f(this->shape.getPosition().x + this->shape.getGlobalBounds().width / 2.f, this->shape.getPosition().y + this->shape.getGlobalBounds().height / 2.f);
  sf::Vector2f dirToTarget(target_position.x - center.x, target_position.y - center.y);
  float magnitude = sqrt(pow((double)dirToTarget.x,2) + pow((double)dirToTarget.y, 2));
  sf::Vector2f dirToTargetNorm = dirToTarget/magnitude;
  if(center != target_position)
    this->shape.move(moveSpeed * dirToTargetNorm);

  //this->shape.rotate(this->rotation);
}

void Enemy::move(sf::Vector2f direction, float amount)
{
  this->shape.move(direction * amount);
}

void Enemy::update(sf::Vector2f target_position)
{
 this->move(target_position);
}

void Enemy::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}

