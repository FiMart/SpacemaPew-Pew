#define _CRT_SECURE_NO_WARNINGS 1
#include "Highscore.h"

void Highscore::initHighscore()
{
	this->font.loadFromFile("Font/retrogaming.ttf");
	this->scoreBoardText.setFont(this->font);
	this->scoreBoardText.setCharacterSize(60);
	this->scoreBoardText.setFillColor(sf::Color::White);
	this->scoreBoardText.setString("Leaderboard");
	this->scoreBoardText.setPosition((this->windowX / 2) - (this->scoreBoardText.getGlobalBounds().width / 2), 80);
	this->high = fopen("BackEn/highscore.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		fscanf(high, "%s", &temp);
		name[i] = temp;
		fscanf(high, "%d", &score[i]);
		this->userScore.push_back(std::make_pair(this->score[i], this->name[i]));
	}
	fclose(this->high);
	for (int i = 0; i < 5; i++)
	{
		this->playerName[i].setString(this->name[i]);
		this->playerScore[i].setString(std::to_string(this->score[i]));
		this->playerName[i].setFont(this->font);
		this->playerName[i].setCharacterSize(30);
		this->playerName[i].setFillColor(sf::Color::White);
		this->playerName[i].setPosition((this->windowX / 2) - (this->scoreBoardText.getGlobalBounds().width / 2), 200 + 100 * i);
		this->playerScore[i].setFont(this->font);
		this->playerScore[i].setCharacterSize(30.f);
		this->playerScore[i].setFillColor(sf::Color::White);
		this->playerScore[i].setPosition((this->windowX / 2) + (this->scoreBoardText.getGlobalBounds().width / 2), 200 + 100 * i);
	}
}

void Highscore::initBackground()
{
	this->backgroundTexture.loadFromFile("Texture/highscore.jpg");
	this->background.setTexture(this->backgroundTexture);
}

Highscore::Highscore()
{
	this->initHighscore();
	this->initBackground();
}

Highscore::~Highscore()
{
	this->backgroundTexture;
	this->background;
}

void Highscore::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->scoreBoardText);

	for (int i = 0; i < 5; i++)
	{
		target->draw(this->playerName[i]);
		target->draw(this->playerScore[i]);
	}
}