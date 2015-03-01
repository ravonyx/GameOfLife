#include "Board.h"
#include <iostream>

Board::Board()
{
	height_c = (float)HEIGTH_W / (float)SIZE_TAB;
	width_c = (float)WIDTH_W / (float)SIZE_TAB;
}

void Board::generate(sf::RenderWindow* window, int color)
{
	for (int i = 0; i <= SIZE_TAB - 1; i++)
		for (int j = 0; j <= SIZE_TAB - 1; j++)
		{		
			if (color == 2)
			{
				grid[i][j].setColor(rand()%2);
				grid[i][j].setState(rand()%2);
			}
			else
			{
				grid[i][j].setColor(color);
				grid[i][j].setState(color);
			}
		}
}

void Board::print(sf::RenderWindow* window)
{
	float y = 0;
	for (int i = 0; i <= SIZE_TAB - 1; i++)
	{
		float x = 0;
		for (int j = 0; j <= SIZE_TAB - 1; j++)
		{
			sf::RectangleShape rectangle(sf::Vector2f(width_c, height_c));
			if (grid[i][j].getColor() == 1)
				rectangle.setFillColor(sf::Color::White);
				
			else
				rectangle.setFillColor(sf::Color::Black);
			rectangle.setPosition(sf::Vector2f((float)x,(float)y));
			window->draw(rectangle);
			x = x + width_c;
		}
		y = y + height_c;
	}
}
void Board::draw(sf::RenderWindow* window, sf::Vector2i position)
{
	grid[(int)(position.y / height_c)][int(position.x / width_c)].setColor(1);
	grid[(int)(position.y / height_c)][int(position.x / width_c)].setState(1);
}


void Board::maj()
{
	int tab[SIZE_TAB][SIZE_TAB];
	int count_alives;

	for (int i = 0; i < SIZE_TAB; i++)
	{
		for (int j = 0; j < SIZE_TAB; j++)
		{
			tab[i][j] = 0;
		}
	}

	for (int i = 0; i < SIZE_TAB; i++)
	{
		for (int j = 0; j < SIZE_TAB; j++)
		{
			count_alives = countAlives(i, j);

			if (grid[i][j].getState() == "Alive" && count_alives < 2)
				tab[i][j] = 0;
			else if (grid[i][j].getState() == "Alive" && count_alives == 2 || count_alives == 3)
				tab[i][j] = 1;
			else if (grid[i][j].getState() == "Alive" && count_alives > 3)
				tab[i][j] = 0;
			else if (grid[i][j].getState() == "Dead" && count_alives == 3)
				tab[i][j] = 1;
			else
				tab[i][j] = 0;
		}
	}

	for (int i = 0; i < SIZE_TAB; i++)
	{
		for (int j = 0; j < SIZE_TAB; j++)
		{
			grid[i][j].setState(tab[i][j]);
			grid[i][j].setColor(tab[i][j]);
		}
	}
}


int Board::countAlives(int i, int j)
{
	int count_alives = 0;
	if (i != 0)
	{
		if (j != 0)
		{
			if (grid[i - 1][j - 1].getState() == "Alive")
				count_alives++;
		}

		if (j != SIZE_TAB - 1)
		{
			if (grid[i - 1][j + 1].getState() == "Alive")
				count_alives++;
		}

		if (grid[i - 1][j].getState() == "Alive")
			count_alives++;
	}
	if (i != SIZE_TAB - 1)
	{
		if (j != 0)
		{
			if (grid[i + 1][j - 1].getState() == "Alive")
				count_alives++;
		}
		if (j != SIZE_TAB - 1)
		{
			if (grid[i + 1][j + 1].getState() == "Alive")
				count_alives++;
		}
		if (grid[i + 1][j].getState() == "Alive")
			count_alives++;

	}

	if (j != 0)
	{
		if (grid[i][j - 1].getState() == "Alive")
			count_alives++;
	}

	if (j != SIZE_TAB - 1)
	{
		if (grid[i][j + 1].getState() == "Alive")
			count_alives++;
	}

	return count_alives;
}