#ifndef GAME_H
#define GAME_H

#include "Board.h"
#include <iostream>

class Game
{
private:
	sf::RenderWindow	*window;
	sf::Mouse::Button	*button;
	sf::Clock			clock;
	Board				*board;
	float speed;
	unsigned int fps;

public:
	Game();
	void handleMenu();
	void menu();
	void draw();
	void play(bool drawing);
	void shutDown();
};

#endif