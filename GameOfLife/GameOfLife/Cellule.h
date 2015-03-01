#ifndef CELLULE_H
#define CELLULE_H

#include <string>

struct Position 
{
	int x;
	int y;
};

class Cellule
{
	private:
		int color;
		std::string state;
		Position position;
	public:
		Cellule();
		Position getPosition();
		std::string getState();
		void setState(int state);
		int	getColor();
		void setColor(int color);
};
#endif