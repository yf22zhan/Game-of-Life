#pragma once
#include "SFML/Graphics.hpp"

class Button
{
public:
	const static sf::Color button_color;
	const static sf::Color text_released;
	const static sf::Color text_clicked;

public:
	Button(sf::Vector2f &position);
	virtual ~Button();

	sf::RectangleShape &getRectangleShape() const;
	sf::Text &getText() const;
	sf::Vector2f &getPosition();

	void onClick(float x, float y);
	void onRelease(float x, float y);

private:
	sf::RectangleShape *rect;
	sf::Text *text;
	sf::Vector2f position;

private:
	virtual void update();
};