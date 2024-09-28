#pragma once

#include "Tile.h"
#include "Button.h"
#include <vector>
#include <map>
#include <iostream>

class GameBoard
{
private:
  sf::RenderWindow* window;
  std::map<std::string, sf::Texture> textures;
  std::vector<Tile*> tiles;
  std::map<std::string, Button*> buttons;
  float keyTime, keyTimeMax;
  sf::Vector2f mousePosView;
  bool exitGame;

  void loadTextures();
  void initializeButtons();
  void createBoard();
  void randomizeBoard();

  void updateKeyTime();
  void updateButtons();

public:
  GameBoard(sf::RenderWindow* window);
  ~GameBoard();

  inline const bool checkExit() const {return this->exitGame;}
  inline const bool checkKeyTime() const {return this->keyTime >= this->keyTimeMax;}
  inline void resetKeyTime() {this->keyTime = 0.f;}

  void update(sf::RenderWindow& window);
  void render(sf::RenderTarget& target);
};

