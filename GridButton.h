#pragma once
#include "Button.h"

class GridButton : public Button
{
public:
	GridButton(sf::Vector2f &position);
	~GridButton();

private:
	void update();
};