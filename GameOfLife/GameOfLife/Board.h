#ifndef BOARD_H
#define BOARD_H

#include <SFML/Graphics.hpp>
#include "Cellule.h"
#include "Global.h"

class Board
{
	private:
		Cellule grid[SIZE_TAB][SIZE_TAB];
		float	height_c;
		float	width_c;

	public:
		Board();
		int Board::countAlives(int i, int j);
		void generate(sf::RenderWindow* window, int color);
		void print(sf::RenderWindow* window);
		void draw(sf::RenderWindow* window, sf::Vector2i position);
		void maj();
};

#endif