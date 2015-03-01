#include "Cellule.h"
#include <random>

Cellule::Cellule()
{
	color = 0;
	state = "Dead";
}

Position Cellule::getPosition()
{
	return position;
}

std::string Cellule::getState()
{
	return state;
}
void Cellule::setState(int s)
{
	if (s == 1)
		state = "Alive";
	else
		state = "Dead";
}

int	Cellule::getColor()
{
	return color;
}
void Cellule::setColor(int c)
{
	color = c;
}
