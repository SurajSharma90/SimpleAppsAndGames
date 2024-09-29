#pragma once

#include "Tile.h"
#include "Button.h"
#include <vector>
#include <map>
#include <iostream>
#include <time.h>
#include <windows.h>

class GameBoard
{
private:
  sf::RenderWindow* window;
  std::map<std::string, sf::Texture> textures;
  std::vector<Tile*> tilesVec;
  std::vector<int> orderVec;
  std::map<std::string, Button*> buttonsMap;
  float keyTime, keyTimeMax;
  sf::Vector2f mousePosView;
  bool exitGame;

  void loadTextures();
  void initializeButtons();
  void createBoard(int board_width, int board_height, int nr_active);
  void randomizeBoard(int nr_active);

  void updateKeyTime();
  void updateButtons();
  void updateBoard();

public:
  GameBoard(sf::RenderWindow* window, int board_width = 5, int board_height = 5, int nr_active = 4);
  ~GameBoard();

  inline const bool checkExit() const {return this->exitGame;}
  inline const bool checkKeyTime() const {return this->keyTime >= this->keyTimeMax;}
  inline void resetKeyTime() {this->keyTime = 0.f;}

  void update(sf::RenderWindow& window);
  void render(sf::RenderTarget& target);
};

