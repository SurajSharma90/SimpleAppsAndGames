#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

enum BUTTON_STATE{IDLE = 0, HOVER = 1, PRESSED = 2};

class Button
{
  private:
    sf::Sprite shape;
    sf::Color colorIdle;
    sf::Color colorHover;
    sf::Color colorPressed;
    sf::Texture texIdle;
    sf::Texture texHover;
    sf::Texture texPressed;
    int buttonState;

  public:
    Button(sf::Vector2f mousePosView);
    ~Button();

    const bool& isPressed() const;
    const bool& isHover() const;

    void update(const sf::RenderWindow& window);
    void render(sf::RenderTarget& target);
};
