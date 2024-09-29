#include "GameBoard.h"

int main()
{
  srand(time(0));
  sf::RenderWindow window(sf::VideoMode(1500,1000), "Memory Game");
  window.setFramerateLimit(60);
  
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