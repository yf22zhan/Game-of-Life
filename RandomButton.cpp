#include "RandomButton.h"
#include "Game.h"

RandomButton::RandomButton(sf::Vector2f &position) :
	Button(position)
{
	getText().setString("Random");
	getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height);
	getText().setPosition(position);
}

RandomButton::~RandomButton()
{
}

void RandomButton::update()
{
	Game::control.random_flag = true;
}