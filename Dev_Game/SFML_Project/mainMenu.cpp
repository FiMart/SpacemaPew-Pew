#include "mainMenu.h"

mainMenu::mainMenu()
{
	this->blackGroundTexture.loadFromFile("Texture/menu.png");
	this->blackGroundSprite.setTexture(this->blackGroundTexture);
}

mainMenu::~mainMenu()
{

}

void mainMenu::update()
{

}

void mainMenu::render(sf::RenderTarget& target)
{
	target.draw(this->blackGroundSprite);
}