#include "GameBoard.h"

void GameBoard::createBoard(const int board_width, const int board_height)
{
  float x = 0.f;
  float y = 0.f;
  for (size_t i = 0; i < board_height; i++)
  {
    for (size_t k = 0; k < board_width; k++)
    {
      this->tilesVec.push_back(new Tile(sf::Vector2f(x, y), this->tileSize, false));
      x += this->tileSize;
    }
    y += this->tileSize;
    x = 0.f;
  }
}

void GameBoard::randomizeBoard()
{
  this->activeTilesVec.clear();

  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    this->tilesVec[i]->setActive(false);
    this->tilesVec[i]->setColorInactive();
  }

  std::vector<int> index_vector;
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    index_vector.push_back(i);
  }

  int tiles_added = 0;
  int index = -1;
  while (tiles_added != this->nrOfActiveTiles)
  {
    index = rand()%index_vector.size();
    this->tilesVec[index_vector[index]]->setActive(true);
    this->tilesVec[index_vector[index]]->setColorActive();
    this->activeTilesVec.push_back(index_vector[index]);
    index_vector.erase(index_vector.begin() + index);
    tiles_added++;
  }
}

void GameBoard::displayOrder()
{
  //Show board
  if (this->displayTimer < 50.f)
  {
    for (size_t i = 0; i < this->tilesVec.size(); i++)
    {
      this->tilesVec[i]->setColorInactive();
    }
  }
  else if (this->displayTimer >= 50.f && this->displayTimer < 100.f)
  {
    for (size_t i = 0; i < this->tilesVec.size(); i++)
    {
      if(this->tilesVec[i]->isActive())
        this->tilesVec[i]->setColorActive();
    }
  }
  else if (this->displayTimer >= 100.f && this->displayTimer < 150.f)
  {
    for (size_t i = 0; i < this->tilesVec.size(); i++)
    {
      this->tilesVec[i]->setColorInactive();
    }
  }
  else
  {
    this->restarting = false;
  }

  this->displayTimer += 1.f;
}

const bool GameBoard::checkSelection()
{
  std::sort(this->activeTilesVec.begin(), this->activeTilesVec.end());
  std::sort(this->selectionVec.begin(), this->selectionVec.end());

  return this->activeTilesVec == this->selectionVec;
}

void GameBoard::updateKeyTime()
{
  if(this->keyTime < this->keyTimeMax)
    this->keyTime += 1.f;
}

void GameBoard::updateBoard()
{
  if (this->restarting)
  {
    this->displayOrder();
  }
  else
  {
    if (this->tilesSelected < this->nrOfActiveTiles)
    {
      for (size_t i = 0; i < this->tilesVec.size(); i++)
      {
        this->tilesVec[i]->update(this->mousePosView, sf::Mouse::isButtonPressed(sf::Mouse::Left));

        if (this->tilesVec[i]->isPressed() && this->checkKeyTime())
        {
          this->selectionVec.push_back(i);
          this->tilesVec[i]->setColorActive();
          this->tilesSelected++;
          this->resetKeyTime();
        }
      }
    }
    else
    {
      if (this->checkSelection())
      {
        std::cout << "Correct!" << "\n";
        this->correct++;
      }
      else
      {
        std::cout << "Incorrect!" << "\n";
        this->incorrect++;
      }
      std::cout << "Correct/Incorrect: " << this->correct << "/" << this->incorrect << "\n";
      this->restart();
    }
  }
}

GameBoard::GameBoard()
{
  this->window = nullptr;
  this->tileSize = 0.f;
  this->exitGame = false;
  this->keyTimeMax = 0.f;
  this->keyTime = 0.f;
  this->nrOfActiveTiles = 0;
  this->tilesSelected = 0;
  this->restarting = false;
  this->displayTimer = 0.f;
  this->correct = 0;
  this->incorrect = 0;
}

GameBoard::GameBoard(sf::RenderWindow* window, float tile_size, int board_width, int board_height, int nr_active)
: window(window)
{
  this->tileSize = tile_size;
  this->exitGame = false;
  this->keyTimeMax = 10.f;
  this->keyTime = this->keyTimeMax;
  this->nrOfActiveTiles = nr_active;
  this->tilesSelected = 0;
  this->restarting = true;
  this->displayTimer = 0.f;
  this->correct = 0;
  this->incorrect = 0;

  this->createBoard(board_width, board_height);
  this->randomizeBoard();
}

GameBoard::~GameBoard()
{
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    delete this->tilesVec[i];
  }
}

void GameBoard::restart()
{
  this->tilesSelected = 0;
  this->restarting = true;
  this->displayTimer = 0.f;
  this->selectionVec.clear();
  this->randomizeBoard();
}

void GameBoard::update(sf::RenderWindow& window)
{
  this->mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

  this->updateKeyTime();
  this->updateBoard();
}

void GameBoard::render(sf::RenderTarget& target)
{
  for (size_t i = 0; i < this->tilesVec.size(); i++)
  {
    this->tilesVec[i]->render(target);
  }
}
