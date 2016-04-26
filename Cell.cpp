#include "Cell.h"

Cell::Cell(int dimension) :
	dimension(dimension),
	color(sf::Color::Red)
{
	shape.setSize(sf::Vector2f(dimension, dimension));
	shape.setOutlineThickness(0);
	shape.setFillColor(color);
}

Cell::~Cell()
{
}

int Cell::getDimension() const
{
	return dimension;
}

sf::RectangleShape &Cell::getShape()
{
	return shape;
}

void Cell::setPosition(int x, int y)
{
	shape.setPosition(x, y);
}

void Cell::changeColor()
{
	if (color == sf::Color::Red)
		color = sf::Color::Green;
	else if (color == sf::Color::Green)
		color = sf::Color::Blue;
	else if (color == sf::Color::Blue)
		color = sf::Color::Red;
}

void Cell::setColor(CellAge &age)
{
	switch (age)
	{
	case Live_Strong:
		shape.setFillColor(color);
		break;
	case Live_Average:
		if (color.r == 255)
			shape.setFillColor(sf::Color(255, 76, 76));
		else if (color.g == 255)
			shape.setFillColor(sf::Color(76, 255, 76));
		else if (color.b == 255)
			shape.setFillColor(sf::Color(76, 76, 255));
		break;
	case Live_Weak:
		if (color.r == 255)
			shape.setFillColor(sf::Color(255, 153, 153));
		else if (color.g == 255)
			shape.setFillColor(sf::Color(153, 255, 153));
		else if (color.b == 255)
			shape.setFillColor(sf::Color(153, 153, 255));
		break;
	case Dead:
		shape.setFillColor(sf::Color::White);
		break;
	}
}