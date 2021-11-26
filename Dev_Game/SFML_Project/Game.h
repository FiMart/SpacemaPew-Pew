#define _CRT_SECURE_NO_WARNINGS

#ifndef GAME_H
#define GAME_H
#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <stdlib.h>
#include <fstream>
#include <utility>
#include <algorithm>

#include "Player.h"
#include "Background.h"
#include "Bullet.h"
#include "Enemy.h"
#include "GUI.h"
#include "Item.h"
#include "mainMenu.h"
#include "Botton.h"
#include "Highscore.h"
#include "Gameover.h"
#include "Entername.h"

class Game
{
private:
	sf::Image icon;
	sf::Event ev;
	sf::RenderWindow* window;
	sf::Clock clock;

	float windowX;
	float deltaTime;
	int State;
	bool gameStop;
	
	
	//mainmenu
	mainMenu* menu;
	sf::Text me;
	sf::SoundBuffer menuBuffer;
	sf::Sound menuSound;

	//highscore
	Highscore* highscore;

	//botton
	sf::Vector2i mouse;
	sf::Vector2f mousePos;
	sf::Font font;
	Botton* Newgame;
	Botton* Exit;
	Botton* HighScore;
	Botton* Back;
	Botton* Play;
	Botton* BackInput;
	Botton* Continuous;
	Botton* ExitGamePause;
	Botton* GoToHighScore;
	Botton* ExtitGame;

	Entername* enterName;
	std::vector<sf::Event> textName;
	sf::Texture exEnemy[2];

	//background
	sf::Texture highscoreTex;
	sf::Sprite highScoreSpirte;
	sf::Texture backgroundTexture[2];
	sf::RectangleShape background2;
	sf::Texture background2Texture;
	std::vector<Background> backgrounds;

	//Item
	std::vector<Item*> items;
	sf::SoundBuffer itemBuffer;
	sf::Sound itemSound;
	float itemSpawnTimer;
	float itemSpawnTimerMax;
	float setScale[3];
	int randomItem;
	sf::Texture itemTexture[3];
	sf::Sprite itemSprite;

	//bullet
	sf::SoundBuffer hitBuffer;
	sf::Sound hitSound;
	std::map<std::string, sf::Texture*> bulletTexture;
	std::vector<Bullet*> bullets;
	int bulletFlag;
	float flagcooldown;
	float flagcooldownMax;

	//enemy
	std::vector<Enemy*> enemies;
	sf::SoundBuffer expoBuffer;
	sf::Sound expoSound;
	float spawnEnemyTimer;
	float spawnEnemyTimerMax;
	sf::Texture Enemies[2];
	int enemySpeed[2];
	int enemyHP[2];
	int enemyScore[2];
	int enemyDmg[2];
	unsigned random;
	float PosY;
	float PosX;
	float updateSpawmTimer;
	float timer;

	//Gui
	GUI* gui;
	sf::SoundBuffer buffer;
	sf::Sound sound;

	//con
	void initWindow();
	void innitMainMenu();
	void initHighScore();
	void initEnterName();
	void initGamePause();
	void initGameOver();
	void initBackground();
	void initItem();
	void initVar();
	void initPlayer();
	void initBullet();
	void initEnemy();
	void initGame();

	sf::Text gamePause;

	//player
	Player* player;
	sf::SoundBuffer oofBuffer;
	sf::Sound oof;

	GameOver* gameOver;


public:
	Game();
	virtual ~Game();

	void updatePullEvent();

	void updateMenu();
	void updateHighScore();
	void updateEnterName();
	void updateGamePause();
	void updateGameOver();
	void updateHighOver();

	void updateInput();
	void updateCollisionWorld();
	void updateSpawnTimer();
	void updateAnimation();
	void updateEnemy();
	void updateItem();
	void updateBullet();
	void updateCombat();
	void updateGui();
	void update();

	void renderMenu();
	void renderHigh();
	void renderEnterName();
	void renderGamePause();
	void renderGameOver();
	void renderHighOver();
	void render();
	void run();
};

#endif // !GAME_H