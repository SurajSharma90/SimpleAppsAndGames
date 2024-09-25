#include "Button.h"

Button::Button(sf::Vector2f mousePosView)
{
  this->colorIdle = sf::Color::White;
  this->colorHover = sf::Color::Green;
  this->colorPressed = sf::Color::Red;

  if (this->texIdle.loadFromFile("Textures/button_idle.png")
      && this->texHover.loadFromFile("Textures/button_hover.png")
      && this->texPressed.loadFromFile("Textures/button_pressed.png")
    )
  {
    std::cout << "Textures loaded!" << "\n";
    this->shape.setTexture(this->texIdle);
  }
  else 
  {
    std::cout << "Could not load textures!" << "\n";
  }

  this->buttonState = IDLE;
  this->shape.setPosition(mousePosView.x - this->shape.getGlobalBounds().width / 2.f, mousePosView.y - this->shape.getGlobalBounds().height / 2.f);
}

Button::~Button()
{
}

const bool& Button::isPressed() const
{
  return this->buttonState == PRESSED;
}

const bool& Button::isHover() const
{
  return this->buttonState == HOVER;
}

void Button::update(const sf::RenderWindow& window)
{
  sf::Vector2f mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

  if (this->shape.getGlobalBounds().contains(mousePosView))
  {
    this->shape.setTexture(this->texHover);
    this->buttonState = HOVER;

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
      this->shape.setTexture(this->texPressed);
      this->buttonState = PRESSED;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
      this->shape.setPosition(mousePosView.x - this->shape.getGlobalBounds().width / 2.f, mousePosView.y - this->shape.getGlobalBounds().height / 2.f);
    }
  }
  else
  {
    this->shape.setTexture(this->texIdle);
    this->buttonState = IDLE;
  }
}

void Button::render(sf::RenderTarget& target)
{
  target.draw(this->shape);
}
