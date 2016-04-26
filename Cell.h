#pragma once
#include "SFML/Graphics.hpp"

class Cell
{
public:
	enum CellAge
	{
		Live_Strong, Live_Average,
		Live_Weak, Dead
	};

	Cell(int);
	~Cell();

	int getDimension() const;
	sf::RectangleShape &getShape();
	void setPosition(int, int);

	void changeColor();
	void setColor(CellAge &age);

private:
	int dimension;
	sf::RectangleShape shape;
	sf::Color color;
};