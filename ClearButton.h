#pragma once
#include "Button.h"

class ClearButton : public Button
{
public:
	ClearButton(sf::Vector2f &position);
	~ClearButton();

private:
	void update();
};