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
  this->buttons[buttonName] = new Button(sf::Vector2f(650.f, 500.f), &this->textures[buttonName + "_idle"], &this->textures[buttonName + "_hover"], &this->textures[buttonName + "_pressed"]);
  buttonName = "button_restart";
  this->buttons[buttonName] = new Button(sf::Vector2f(350.f, 500.f), &this->textures[buttonName + "_idle"], &this->textures[buttonName + "_hover"], &this->textures[buttonName + "_pressed"]);
  buttonName = "button_submit";
  this->buttons[buttonName] = new Button(sf::Vector2f(50.f, 500.f), &this->textures[buttonName + "_idle"], &this->textures[buttonName + "_hover"], &this->textures[buttonName + "_pressed"]);
}

void GameBoard::createBoard()
{
}

void GameBoard::randomizeBoard()
{
}

void GameBoard::updateKeyTime()
{
  if(this->keyTime < this->keyTimeMax)
    this->keyTime += 1.f;
}

void GameBoard::updateButtons()
{
  std::map<std::string, Button*>::iterator it;
  for (it = this->buttons.begin(); it != this->buttons.end(); it++)
  {
    it->second->update(this->mousePosView, sf::Mouse::isButtonPressed(sf::Mouse::Left));
  }

  if (this->buttons["button_exit"]->isPressed() && this->checkKeyTime())
  {
    this->exitGame = true;
    this->resetKeyTime();
  }
}

GameBoard::GameBoard(sf::RenderWindow* window)
: window(window)
{
  this->exitGame = false;
  this->keyTimeMax = 1000.f;
  this->keyTime = this->keyTimeMax;

  this->loadTextures();
  this->initializeButtons();
}

GameBoard::~GameBoard()
{
  //Delete buttons
  std::map<std::string, Button*>::iterator it;
  for (it = this->buttons.begin(); it != this->buttons.end(); it++)
  {
    delete it->second;
  }
}

void GameBoard::update(sf::RenderWindow& window)
{
  this->mousePosView = window.mapPixelToCoords(sf::Mouse::getPosition(window));

  this->updateKeyTime();
  this->updateButtons();
}

void GameBoard::render(sf::RenderTarget& target)
{
  std::map<std::string, Button*>::iterator it;
  for (it = this->buttons.begin(); it != this->buttons.end(); it++)
  {
    it->second->render(target);
  }
}
