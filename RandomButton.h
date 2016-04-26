#pragma once
#include "Button.h"

class RandomButton : public Button
{
public:
	RandomButton(sf::Vector2f &position);
	~RandomButton();

private:
	void update();
};
