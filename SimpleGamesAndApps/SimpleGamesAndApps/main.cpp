#include "Player.h"
#include "Enemy.h"
#include <time.h>

void movePlayer(Player& player);

int main()
{
  float keyTimeMax = 15.f;
  float keyTime = keyTimeMax;

  srand(time(0));
  sf::RenderWindow window(sf::VideoMode(1000, 800), "Auto Shooter");
  window.setFramerateLimit(60);

  Player player;
  std::vector<Enemy*> enemyVec;
  Enemy* targetEnemy = nullptr;

  sf::Event event;
  while (window.isOpen())
  {
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    //Update
    if(keyTime < keyTimeMax)
      keyTime += 1.f;

    //Create enemies
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && keyTime >= keyTimeMax)
    {
      enemyVec.push_back(new Enemy(sf::Vector2f(rand()%1000, rand()%800), sf::Color(rand() % 255, rand() % 255, rand() % 255, 255), 20.f, rand() % 20, rand() % 5 + 2, 2.f));
      targetEnemy = enemyVec[0];
      keyTime = 0.f;
    }

    movePlayer(player);
    player.update();

    //Enemy Collision and movement
    float distToPlayer = -1.0;
    for (size_t i = 0; i < enemyVec.size(); i++)
    {
      enemyVec[i]->update(player.getCenter());

      sf::Vector2f dirToTarget(player.getCenter() - enemyVec[i]->getCenter());
      float magnitude = static_cast<float>(sqrt(pow((double)dirToTarget.x, 2) + pow((double)dirToTarget.y, 2)));
      if(distToPlayer == -1.0)
        distToPlayer = magnitude;

      if(distToPlayer > magnitude)
      {
        distToPlayer = magnitude;
        targetEnemy = enemyVec[i];
      }

      //Collision
      for (size_t k = 0; k < enemyVec.size(); k++)
      {
        if (enemyVec[i] != enemyVec[k])
        {
          if (enemyVec[i]->getGlobalBounds().intersects(enemyVec[k]->getGlobalBounds()))
          {
            sf::Vector2f dir = sf::Vector2f(enemyVec[i]->getCenter() - enemyVec[k]->getCenter());
            enemyVec[i]->move(dir, 0.1f);
            enemyVec[k]->move(-dir, 0.1f);
          }
        }
      }
    }

    //Player
    if (targetEnemy != nullptr)
    {
      player.shoot(targetEnemy->getNormVec(player.getCenter()));
    }

    //Render
    window.clear();
    player.render(window);
    for (size_t i = 0; i < enemyVec.size(); i++)
    {
      enemyVec[i]->render(window);
    }
    window.display();
  }

  for (size_t i = 0; i < enemyVec.size(); i++)
  {
    delete enemyVec[i];
  }

  return 0;
}

void movePlayer(Player& player)
{
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
  {
    player.move(sf::Vector2f(-1.f, 0.f));
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
  {
    player.move(sf::Vector2f(1.f, 0.f));
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
  {
    player.move(sf::Vector2f(0.f, -1.f));
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
  {
    player.move(sf::Vector2f(0.f, 1.f));
  }
}