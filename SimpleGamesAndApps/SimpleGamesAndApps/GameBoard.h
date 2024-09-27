#pragma once

#include "Tile.h"
#include "Button.h"
#include <vector>
#include <map>

class GameBoard
{
private:
  std::map<std::string, sf::Texture> textures;
  std::vector<Tile*> tiles;
  std::vector<Button*> buttons;
  float keyTime, keyTimeMax;

  void loadTextures();
  void createBoard();
  void randomizeBoard();

  void updateKeyTime();
  void updateButtons();

public:
  GameBoard();
  ~GameBoard();

  void update();
  void render(sf::RenderTarget& target);
};

