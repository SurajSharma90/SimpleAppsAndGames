#include "Button.h"

Button::Button()
{
  this->texIdle = nullptr;
  this->texHover = nullptr;
  this->texPressed = nullptr;
  this->button_state = -1;
}

Button::Button(sf::Vector2f position, sf::Texture* texIdle, sf::Texture* texHover, sf::Texture* texPressed)
  : texIdle(texIdle), texHover(texHover), texPressed(texPressed)
{
  this->button_state = IDLE;
  this->shape.setTexture(*this->texIdle);
  this->shape.setPosition(position);
}

void Button::update(const sf::Vector2f& mousePosView, bool lmb_pressed)
{
  if (this->shape.getGlobalBounds().contains(mousePosView))
  {
    this->button_state = HOVER;
    this->shape.setTexture(*this->texHover);

    if (lmb_pressed)
    {
      this->button_state = PRESSED;
      this->shape.setTexture(*this->texPressed);
    }
  }
  else
  {
    this->button_state = IDLE;
    this->shape.setTexture(*this->texIdle);
  }
}

void Button::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
