#include "GridButton.h"
#include "Game.h"

GridButton::GridButton(sf::Vector2f &position) :
	Button(position)
{
	getText().setString("Grid");
	getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height);
	getText().setPosition(position);
}

GridButton::~GridButton()
{
}

void GridButton::update()
{
	if (Game::control.hide_grid_flag == true)
		Game::control.hide_grid_flag = false;
	else
		Game::control.hide_grid_flag = true;
}