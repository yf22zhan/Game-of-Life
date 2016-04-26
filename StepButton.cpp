#include "StepButton.h"
#include "Game.h"

StepButton::StepButton(sf::Vector2f &position) :
	Button(position)
{
	getText().setString("Step");
	getText().setOrigin(getText().getLocalBounds().width / 2, getText().getLocalBounds().height * 0.8);
	getText().setPosition(position);
}

StepButton::~StepButton()
{
}

void StepButton::update()
{
	Game::control.step_flag = true;
}