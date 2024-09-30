#include "GameBoard.h"

void GameBoard::loadTextures()
{ 
  std::string buttonName = "button_exit";
  if (!this->textures[buttonName + "_idle"].loadFromFile("Textures/" + buttonName + "_idle.png")) std::cout << "Could not load texture " + buttonName + "_idle.png";
  if (!this->textures[buttonName + "_hover"].loadFromFile("Textures/" + buttonName + "_hover.png")) std::cout << "Could not load texture " + buttonName + "_hover.png";
  if (!this->textures[buttonName + "_pressed"].loadFromFile("Textures/" + buttonName + "_pressed.png")) std::cout << "Could not load texture " + buttonName + "_pressed.png";
  buttonName = "button_restart";
  if (!this->textures[buttonName + "_idle"].loadFromFile("Textures/" + buttonName + "_idle.png")) std::cout << "Could not load texture " + buttonName + "_idle.png";
  if (!this->textures[buttonName + "_hover"].loadFromFile("Textures/" + buttonName + "_hover.png")) std::cout << "Could not load texture " + buttonName + "_hover.png";
  if (!this->textures[buttonName + "_pressed"].loadFromFile("Textures/" + buttonName + "_pressed.png")) std::cout << "Could not load texture " + buttonName + "_pressed.png";
  buttonName = "button_submit";
  if (!this->textures[buttonName + "_idle"].loadFromFile("Textures/" + buttonName + "_idle.png")) std::cout << "Could not load texture " + buttonName + "_idle.png";
  if (!this->textures[buttonName + "_hover"].loadFromFile("Textures/" + buttonName + "_hover.png")) std::cout << "Could not load texture " + buttonName + "_hover.png";
  if (!this->textures[buttonName + "_pressed"].loadFromFile("Textures/" + buttonName + "_pressed.png")) std::cout << "Could not load texture " + buttonName + "_pressed.png";
}

void GameBoard::initializeButtons()
{
  std::string buttonName = "button_exit";
  this->buttonsMap[buttonName] = new Button(sf::Vector2f(650.f, 500.f), &this->textures[buttonName + "_idle"], &this->textures[buttonName + "_hover"], &this->textures[buttonName + "_pressed"]);
  buttonName = "button_restart";
  this->buttonsMap[buttonName] = new Button(sf::Vector2f(350.f, 500.f), &this->textures[buttonName + "_idle"], &this->textures[buttonName + "_hover"], &this->textures[buttonName + "_pressed"]);
  buttonName = "button_submit";
  this->buttonsMap[buttonName] = new Button(sf::Vector2f(50.f, 500.f), &this->textures[buttonName + "_idle"], &this->textures[buttonName + "_hover"], &this->textures[buttonName + "_pressed"]);
}

void GameBoard::createBoard(int board_width, int board_height)
{
  float tile_width = 100.f;
  float tile_height = 100.f;
  float x = 0.f;
  float y = 0.f;
  for (size_t i = 0; i < board_height; i++)
  {
    for (size_t i = 0; i < board_width; i++)
    {
      this->tilesVec.push_back(new Tile(sf::Vector2f(x, y), false));
      x += tile_width;
    }
    y += tile_height;
    x = 0.f;
  }
}

void GameBoard::randomizeBoard()
{
  this->orderVec.clear();
  std::vector<int> index_vector;
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    index_vector.push_back(i);
  } 

  int tiles_added = 0;
  int index = -1;
  while (tiles_added != this->nrActiveTiles)
  {
    index = rand()%index_vector.size()-1;
    this->tilesVec[index_vector[index]]->setActive(true);
    this->tilesVec[index_vector[index]]->setColorActive();
    this->orderVec.push_back(index_vector[index]);
    index_vector.erase(index_vector.begin() + index);
    tiles_added++;
  }

  for (size_t i = 0; i < this->orderVec.size(); i++)
  {
    std::cout << orderVec[i] << " ";
  }
}

void GameBoard::displayOrder()
{
  //Show board
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    this->tilesVec[i]->setColorInactive();
  }
  
  //Show board active tiles in order
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    if (this->tilesVec[i]->getActive())
      this->tilesVec[i]->setColorActive();
  }
}

void GameBoard::updateKeyTime()
{
  if(this->keyTime < this->keyTimeMax)
    this->keyTime += 1.f;
}

void GameBoard::updateButtons()
{
  std::map<std::string, Button*>::iterator it;
  for (it = this->buttonsMap.begin(); it != this->buttonsMap.end(); it++)
  {
    it->second->update(this->mousePosView, sf::Mouse::isButtonPressed(sf::Mouse::Left));
  }

  if (this->buttonsMap["button_exit"]->isPressed() && this->checkKeyTime())
  {
    this->exitGame = true;
    this->resetKeyTime();
  }
}

void GameBoard::updateBoard()
{
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    this->tilesVec[i]->update(this->mousePosView, sf::Mouse::isButtonPressed(sf::Mouse::Left));

    if (this->tilesVec[i]->isPressed())
    {
        
    }
  }
}

GameBoard::GameBoard(sf::RenderWindow* window, int board_width, int board_height, int nr_active)
: window(window)
{
  this->exitGame = false;
  this->keyTimeMax = 1000.f;
  this->keyTime = this->keyTimeMax;
  this->nrActiveTiles = nr_active;

  this->loadTextures();
  this->initializeButtons();
  this->createBoard(board_width, board_height);
  this->randomizeBoard();
}

GameBoard::~GameBoard()
{
  //Delete buttonsMap
  std::map<std::string, Button*>::iterator it;
  for (it = this->buttonsMap.begin(); it != this->buttonsMap.end(); it++)
  {
    delete it->second;
  }
}

void GameBoard::update(sf::RenderWindow& window)
{
  this->mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

  this->updateKeyTime();
  this->updateButtons();
  this->updateBoard();
}

void GameBoard::render(sf::RenderTarget& target)
{
  std::map<std::string, Button*>::iterator it;
  for (it = this->buttonsMap.begin(); it != this->buttonsMap.end(); it++)
  {
    it->second->render(target);
  }

  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    this->tilesVec[i]->render(target);
  }
}
