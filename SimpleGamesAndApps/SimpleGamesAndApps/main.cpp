#include "Player.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(1000, 800), "Auto Shooter");

  Player player;

  sf::Event event;
  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    //Update

    //Render
    window.clear();
    player.render(window);
    window.display();
  }

  return 0;
}