#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

enum BUTTON_STATE{IDLE=0, HOVER=1, PRESSED=2};

class Button
{
private:
  sf::Sprite shape;
  sf::Texture* texIdle;
  sf::Texture* texHover;
  sf::Texture* texPressed;
  short button_state;

public:
  Button();
  Button(sf::Vector2f position, sf::Texture* texIdle, sf::Texture* texHover, sf::Texture* texPressed);

  inline const bool isPressed() const {return button_state == PRESSED;}

  void update(const sf::Vector2f& mousePosView, bool lmb_pressed);
  void render(sf::RenderTarget& target);
};