#include "Button.h"
#include "Game.h"

const sf::Color Button::button_color = sf::Color(230, 194, 18);
const sf::Color Button::text_released = sf::Color::White;
const sf::Color Button::text_clicked = sf::Color(64, 115, 148);

Button::Button(sf::Vector2f &position)
{
	rect = new sf::RectangleShape();
	text = new sf::Text();
	this->position = position;

	rect->setSize(sf::Vector2f(80, 30));
	rect->setOrigin(rect->getSize().x / 2, rect->getSize().y / 2);
	rect->setPosition(position);
	rect->setFillColor(button_color);

	text->setFont(Game::fontProvider.getFont(FontProvider::FontType::OpenSans));
	text->setCharacterSize(15);
	text->setStyle(sf::Text::Bold);
	text->setColor(text_released);
}

Button::~Button()
{
	delete rect;
	delete text;
}

sf::RectangleShape &Button::getRectangleShape() const
{
	return *rect;
}

sf::Text &Button::getText() const
{
	return *text;
}

sf::Vector2f &Button::getPosition()
{
	return position;
}

void Button::onClick(float x, float y)
{
	if ((x > this->position.x - rect->getSize().x / 2) &&
		(x < this->position.x + rect->getSize().x / 2) &&
		(y > this->position.y - rect->getSize().y / 2) &&
		(y < this->position.y + rect->getSize().y / 2))
	{
		text->setColor(text_clicked);
	}
}

void Button::onRelease(float x, float y)
{
	text->setColor(text_released);
	if ((x > this->position.x - rect->getSize().x / 2) &&
		(x < this->position.x + rect->getSize().x / 2) &&
		(y > this->position.y - rect->getSize().y / 2) &&
		(y < this->position.y + rect->getSize().y / 2))
	{
		update();
	}
}

void Button::update()
{
}