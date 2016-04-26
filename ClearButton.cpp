#include "ClearButton.h"
#include "Game.h"

ClearButton::ClearButton(sf::Vector2f &position) :
	Button(position)
{
	getText().setString("Clear");
	getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height);
	getText().setPosition(position);
}

ClearButton::~ClearButton()
{
}

void ClearButton::update()
{
	Game::control.clear_flag = true;
}