#include "GameBoard.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800,600), "Memory Game");
  
  sf::Texture btnIdle, btnHover, btnPressed;
  btnIdle.loadFromFile("Textures/button_restart_idle.png");
  btnHover.loadFromFile("Textures/button_restart_hover.png");
  btnPressed.loadFromFile("Textures/button_restart_pressed.png");
  Button test(sf::Vector2f(200.f, 200.f), &btnIdle, &btnHover, &btnPressed);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    //Update
    sf::Vector2f mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

    test.update(mousePosView, sf::Mouse::isButtonPressed(sf::Mouse::Left));

    //Render
    window.clear();
    test.render(window);
    window.display();
  }

  return 0;
}