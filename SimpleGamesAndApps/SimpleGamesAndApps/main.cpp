#include "GameBoard.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800,600), "Memory Game");
  
  GameBoard gameBoard(&window);

  while (window.isOpen() && !gameBoard.checkExit())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    gameBoard.update(window);

    //Render
    window.clear();
    gameBoard.render(window);
    window.display();
  }

  window.close();
  return 0;
}