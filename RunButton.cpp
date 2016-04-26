#include "RunButton.h"
#include "Game.h"

RunButton::RunButton(sf::Vector2f &position) :
	Button(position)
{
	getText().setString("Run");
	getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height);
	getText().setPosition(position);
}

RunButton::~RunButton()
{
}

void RunButton::alter()
{
	update();
}

void RunButton::update()
{
	if (getText().getString() == "Run")
	{
		getText().setString("Stop");
		getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height * 0.8);
		getText().setPosition(getPosition());
		Game::control.run_flag = true;
	}
	else
	{
		getText().setString("Run");
		getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height);
		getText().setPosition(getPosition());
		Game::control.run_flag = false;
	}
}
