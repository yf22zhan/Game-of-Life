#include "ColorsButton.h"
#include "Game.h"

ColorsButton::ColorsButton(sf::Vector2f &position) :
	Button(position)
{
	getText().setString("Colors");
	getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height);
	getText().setPosition(position);
}

ColorsButton::~ColorsButton()
{
}

void ColorsButton::update()
{
	Game::control.color_flag = true;
}