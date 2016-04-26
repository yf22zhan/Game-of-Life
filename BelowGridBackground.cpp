#include "BelowGridBackground.h"
#include "Game.h"

const sf::Color BelowGridBackground::bg_color = sf::Color(64, 115, 148);

BelowGridBackground::BelowGridBackground() :
	width(Game::SCREEN_WIDTH),
	height(Game::SCREEN_HEIGHT / 8)
{
	rect = new sf::RectangleShape();
	rect->setSize(sf::Vector2f(width, height));
	rect->setPosition(0, Game::SCREEN_HEIGHT / 8 * 7);
	rect->setOutlineThickness(0);
	rect->setFillColor(bg_color);
}

BelowGridBackground::~BelowGridBackground()
{
	delete rect;
}

int BelowGridBackground::getWitdth() const
{
	return width;
}

int BelowGridBackground::getHeight() const
{
	return height;
}

sf::RectangleShape &BelowGridBackground::getRectangleShape() const
{
	return *rect;
}