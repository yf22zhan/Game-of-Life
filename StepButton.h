#pragma once
#include "Button.h"

class StepButton : public Button
{
public:
	StepButton(sf::Vector2f &position);
	~StepButton();

private:
	void update();
};