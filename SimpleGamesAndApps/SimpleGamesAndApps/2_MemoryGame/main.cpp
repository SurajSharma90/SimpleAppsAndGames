#include "GameBoard.h"

int main()
{
  const int BOARD_WIDTH = 5;
  const int BOARD_HEIGHT = 5;
  const int ACTIVE_TILES = 4;
  const float TILE_SIZE = 100.f;

  srand(time(0));
  sf::RenderWindow window(sf::VideoMode(BOARD_WIDTH * (int)TILE_SIZE, BOARD_HEIGHT * (int)TILE_SIZE), "Memory Game");
  window.setFramerateLimit(60);
  
  GameBoard gameBoard(&window, TILE_SIZE, BOARD_WIDTH, BOARD_HEIGHT, ACTIVE_TILES);

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