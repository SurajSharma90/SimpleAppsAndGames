#pragma once

#include "Tile.h"
#include <vector>
#include <map>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <algorithm>

class GameBoard
{
private:
  sf::RenderWindow* window;
  std::vector<Tile*> tilesVec;
  std::vector<int> activeTilesVec;
  std::vector<int> selectionVec;
  float keyTime, keyTimeMax;
  sf::Vector2f mousePosView;
  float tileSize;
  bool exitGame;
  int tilesSelected;
  int nrActiveTiles;
  bool restarting;
  float displayTimer;
  int correct;
  int incorrect;

  void createBoard(int board_width, int board_height);
  void randomizeBoard();
  void displayOrder();
  const bool checkSelection();

  void updateKeyTime();
  void updateBoard();

public:
  GameBoard(sf::RenderWindow* window, float tile_size = 100.f, int board_width = 5, int board_height = 5, int nr_active = 4);
  ~GameBoard();

  inline const bool checkExit() const {return this->exitGame;}
  inline const bool checkKeyTime() const {return this->keyTime >= this->keyTimeMax;}
  inline void resetKeyTime() {this->keyTime = 0.f;}

  void restart();

  void update(sf::RenderWindow& window);
  void render(sf::RenderTarget& target);
};

