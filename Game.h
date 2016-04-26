#pragma once
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "FontProvider.h"
#include "ControlFlags.h"
#include "Grid.h"
#include "BelowGridBackground.h"
#include "Button.h"
#include "Matrix.h"
#include "Cell.h"
#include "RunButton.h"
#include "StepButton.h"
#include "ClearButton.h"
#include "RandomButton.h"
#include "ColorsButton.h"
#include "GridButton.h"

class Game
{
public:
	static void start();
	static int SCREEN_WIDTH;
	static int SCREEN_HEIGHT;
	static int UPS; //Update per Second
	static FontProvider fontProvider;
	static ControlFlags control;

private:
	static void drawGrid(Grid &grid, bool hide_grid_flag);
	static void drawBelowGridBackground(BelowGridBackground &bg);
	static void drawButton(Button &button);
	static void drawCells(Matrix &matrix, Cell &cell, bool color_flag);
	static void drawObservation(sf::Text &observation);

	static void observationSetup(sf::Text &observation);

	static void gameLoop(Grid &grid, BelowGridBackground &bg,
		std::vector<Button*> &button_vector, Matrix &matrix, Cell &cell, sf::Text &observation);

	enum GameState
	{
		PatternSetup, StepCellGeneration, RunCellGeneration, Exit
	};

	static GameState game_state;
	static sf::RenderWindow window;
};