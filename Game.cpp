#include "Game.h"
#include <iostream>

int Game::SCREEN_WIDTH = 1021;
int Game::SCREEN_HEIGHT = 872;
int Game::UPS = 60;

FontProvider Game::fontProvider;
Game::GameState Game::game_state = PatternSetup;
sf::RenderWindow Game::window;
ControlFlags Game::control;

void Game::start()
{
	window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32), "Conway's Game of Life", sf::Style::Close);

	Grid grid;
	BelowGridBackground below_bg;

	RunButton run_button(sf::Vector2f(SCREEN_WIDTH / 9 * 3, SCREEN_HEIGHT / 8 * 7.5));
	StepButton step_button(sf::Vector2f(SCREEN_WIDTH / 9 * 4, SCREEN_HEIGHT / 8 * 7.5));
	ClearButton clear_button(sf::Vector2f(SCREEN_WIDTH / 9 * 5, SCREEN_HEIGHT / 8 * 7.5));
	RandomButton random_button(sf::Vector2f(SCREEN_WIDTH / 9 * 6, SCREEN_HEIGHT / 8 * 7.5));
	ColorsButton colors_button(sf::Vector2f(SCREEN_WIDTH / 9 * 7, SCREEN_HEIGHT / 8 * 7.5));
	GridButton grid_button(sf::Vector2f(SCREEN_WIDTH / 9 * 8, SCREEN_HEIGHT / 8 * 7.5));

	std::vector<Button*> button_vector =
		{ &run_button, &step_button, &clear_button, &random_button, &colors_button, &grid_button };

	//grid.getVerticalLineCount() + 1 due to SCREENWIDTH does not divide evenly
	//choosing SCREENWIDTH so because SFML drawing VertexArray not perfect
	//to pixel
	Matrix matrix(grid.getHorizontalLineCount(), grid.getVerticalLineCount() + 1);

	Cell cell(grid.getBorderTileDimension());

	sf::Text observation;
	observationSetup(observation);

	gameLoop(grid, below_bg, button_vector, matrix, cell, observation);
}

void Game::drawGrid(Grid &grid, bool hide_grid_flag)
{
	if (hide_grid_flag)
		return;
	window.draw(grid.getHorizontalLines());
	window.draw(grid.getVerticalLines());
}

void Game::drawBelowGridBackground(BelowGridBackground &bg)
{
	window.draw(bg.getRectangleShape());
}

void Game::drawButton(Button &button)
{
	window.draw(button.getRectangleShape());
	window.draw(button.getText());
}

void Game::drawCells(Matrix &matrix, Cell &cell, bool color_flag)
{
	if (color_flag)
	{
		cell.changeColor();
		control.color_flag = false;
	}

	for (int i = 0; i < matrix.num_rows; ++i)
	{
		for (int j = 0; j < matrix.num_cols; ++j)
		{
				cell.setPosition(j * cell.getDimension(), i * cell.getDimension());
				cell.setColor(matrix.getMatrixPointer()[i][j]);
				window.draw(cell.getShape());
		}
	}
}

void Game::drawObservation(sf::Text &observation)
{
	window.draw(observation);
}

void Game::observationSetup(sf::Text &observation)
{
	observation.setFont(Game::fontProvider.getFont(FontProvider::FontType::OpenSans));
	observation.setCharacterSize(15);
	observation.setColor(sf::Color::White);
	observation.setStyle(sf::Text::Regular);
	observation.setString("Generation: " + std::to_string(0) + "\nLive Cells: " + std::to_string(0));
	observation.setOrigin(observation.getLocalBounds().width / 2, observation.getLocalBounds().height * 0.7);
	observation.setPosition(sf::Vector2f(SCREEN_WIDTH / 9, SCREEN_HEIGHT / 8 * 7.5));
}

void Game::gameLoop(Grid &grid, BelowGridBackground &below_bg,
	std::vector<Button*> &button_vector, Matrix &matrix, Cell &cell, sf::Text &observation)
{
	sf::Event event;
	sf::Clock clock;
	int generation_count = 0;

	while (true)
	{
		switch (game_state)
		{
		case PatternSetup:
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					game_state = Exit;
				}

				if (event.type == sf::Event::MouseButtonPressed &&
					event.mouseButton.button == sf::Mouse::Left)
				{
					for (Button* button : button_vector)
					{
						(*button).onClick(event.mouseButton.x, event.mouseButton.y);
					}
				}

				if (event.type == sf::Event::MouseButtonReleased &&
					event.mouseButton.button == sf::Mouse::Left)
				{
					for (Button* button : button_vector)
					{
						(*button).onRelease(event.mouseButton.x, event.mouseButton.y);
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				matrix.onLeftClick(sf::Vector2i(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				matrix.onRightClick(sf::Vector2i(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}

			if (control.run_flag)
			{
				game_state = RunCellGeneration;
				clock.restart();
			}

			if (control.step_flag)
			{
				game_state = StepCellGeneration;
			}

			if (control.clear_flag)
			{
				matrix.clear();
				control.clear_flag = false;
				generation_count = 0;
				game_state = PatternSetup;
			}

			if (control.random_flag)
			{
				matrix.randomize();
				control.random_flag = false;
				generation_count = 0;
				game_state = PatternSetup;
			}

			break;
		}

		case StepCellGeneration:
		{
			matrix.update();
			control.step_flag = false;
			generation_count++;
			game_state = PatternSetup;
			break;
		}

		case RunCellGeneration:
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
				{
					game_state = Exit;
				}

				if (event.type == sf::Event::MouseButtonPressed &&
					event.mouseButton.button == sf::Mouse::Left)
				{
					for (Button* button : button_vector)
					{
						(*button).onClick(event.mouseButton.x, event.mouseButton.y);
					}
				}

				if (event.type == sf::Event::MouseButtonReleased &&
					event.mouseButton.button == sf::Mouse::Left)
				{
					for (Button* button : button_vector)
					{
						(*button).onRelease(event.mouseButton.x, event.mouseButton.y);
					}
				}
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
			{
				matrix.onLeftClick(sf::Vector2i(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}

			if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
			{
				matrix.onRightClick(sf::Vector2i(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y));
			}

			if (clock.getElapsedTime().asMilliseconds() >= (1000 / UPS))
			{
				matrix.update();
				generation_count++;
				clock.restart();
			}

			if (!control.run_flag)
			{
				game_state = PatternSetup;
			}

			if (control.clear_flag)
			{
				matrix.clear();
				control.clear_flag = false;
				dynamic_cast<RunButton*> (button_vector[0])->alter();
				generation_count = 0;
				game_state = PatternSetup;
			}

			if (control.random_flag)
			{
				matrix.randomize();
				control.random_flag = false;
				dynamic_cast<RunButton*> (button_vector[0])->alter();
				generation_count = 0;
				game_state = PatternSetup;
			}

			control.step_flag = false;
			break;
		}

		case Exit:
		{
			window.close();
			return;
		}
		}

		window.clear(sf::Color(255, 255, 255));
		drawCells(matrix, cell, control.color_flag);
		drawGrid(grid, control.hide_grid_flag);
		drawBelowGridBackground(below_bg);
		for (Button* button : button_vector)
		{
			drawButton(*button);
		}
		observation.setString("Generation: " + std::to_string(generation_count) + "\nLive Cells: " + std::to_string(matrix.getLiveCellCount()));
		drawObservation(observation);

		window.display();
	}
}