#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

enum buttonState{IDLE=0, HOVER=1, PRESSED=2};

class Button
{
private:
  sf::Sprite shape;
  sf::Texture* texIdle;
  sf::Texture* texHover;
  sf::Texture* texPressed;
  short buttonState;

public:
  Button();
  Button(sf::Vector2f position, sf::Texture* texIdle, sf::Texture* texHover, sf::Texture* texPressed);

  inline const bool isPressed() const {return buttonState == PRESSED;}

  void update(const sf::Vector2f& mousePosView, bool lmb_pressed);
  void render(sf::RenderTarget& target);
};