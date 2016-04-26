#pragma once
#include "Button.h"

class ColorsButton : public Button
{
public:
	ColorsButton(sf::Vector2f &position);
	~ColorsButton();

private:
	void update();
};