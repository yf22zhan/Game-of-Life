#pragma once
#include "Button.h"

class RunButton : public Button
{
public:
	RunButton(sf::Vector2f &position);
	~RunButton();

	void alter();

private:
	void update();
};