#pragma once
#include "SFML/Graphics.hpp"

class BelowGridBackground
{
public:
	const static sf::Color bg_color;

public:
	BelowGridBackground();
	~BelowGridBackground();

	int getWitdth() const;
	int getHeight() const;
	sf::RectangleShape &getRectangleShape() const;

private:
	int width;
	int height;
	sf::RectangleShape *rect;
};