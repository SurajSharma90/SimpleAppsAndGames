#include <vector>

#include "Button.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Button App");
  std::vector<Button*> buttonVec;
  float keyTimeMax = 1000.f;
  float keyTime = keyTimeMax;

  //Game loop
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

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::B) && keyTime >= keyTimeMax)
    {
      buttonVec.push_back(new Button(mousePosView));
      keyTime = 0.f;
    }

    for (size_t i = 0; i < buttonVec.size(); i++)
    {
      buttonVec[i]->update(window);
    }

    if (keyTime < keyTimeMax)
    {
      keyTime += 1.f;
    }

    //Render
    window.clear();

    for (size_t i = 0; i < buttonVec.size(); i++)
    {
      buttonVec[i]->render(window);
    }

    window.display();
  }

  for (size_t i = 0; i < buttonVec.size(); i++)
  {
    delete buttonVec[i];
  }

  return 0;
}