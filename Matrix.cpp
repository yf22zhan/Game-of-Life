#include "Matrix.h"
#include "Game.h"
#include <ctime>
#include <cstdlib>

Matrix::Matrix(int num_rows, int num_cols) :
	num_rows(num_rows),
	num_cols(num_cols)
{
	current_generation = new Cell::CellAge*[num_rows];
	for (int i = 0; i < num_rows; ++i)
	{
		current_generation[i] = new Cell::CellAge[num_cols];
	}

	next_generation = new Cell::CellAge*[num_rows];
	for (int i = 0; i < num_rows; ++i)
	{
		next_generation[i] = new Cell::CellAge[num_cols];
	}

	clear();
}

Matrix::~Matrix()
{
	for (int i = 0; i < num_rows; ++i)
	{
		delete[] current_generation[i];
	}
	delete[] current_generation;

	for (int i = 0; i < num_rows; ++i)
	{
		delete[] next_generation[i];
	}
	delete[] next_generation;
}

void Matrix::randomize()
{
	srand(time(NULL));

	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			int randomval = rand() % 10;
			if (randomval == 0)
			{
				current_generation[i][j] = Cell::CellAge::Live_Strong;
			}
			else
			{
				current_generation[i][j] = Cell::CellAge::Dead;
			}
		}
	}

	Game::control.random_flag = false;
}

void Matrix::clear()
{
	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			current_generation[i][j] = Cell::CellAge::Dead;
		}
	}

	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			next_generation[i][j] = Cell::CellAge::Dead;
		}
	}
}

void Matrix::update()
{

	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			int count = getLivingNeighborCount(i, j);

			if (count < 2)
				next_generation[i][j] = Cell::CellAge::Dead;
			else if (count == 2)
			{
				switch (current_generation[i][j])
				{
				case Cell::CellAge::Dead:
					next_generation[i][j] = Cell::CellAge::Dead;
					break;
				case Cell::CellAge::Live_Strong:
					next_generation[i][j] = Cell::CellAge::Live_Average;
					break;
				case Cell::CellAge::Live_Average:
					next_generation[i][j] = Cell::CellAge::Live_Weak;
					break;
				case Cell::CellAge::Live_Weak:
					next_generation[i][j] = Cell::CellAge::Live_Weak;
					break;
				}
			}
			else if (count == 3)
			{
				switch (current_generation[i][j])
				{
				case Cell::CellAge::Dead:
					next_generation[i][j] = Cell::CellAge::Live_Strong;
					break;
				case Cell::CellAge::Live_Strong:
					next_generation[i][j] = Cell::CellAge::Live_Average;
					break;
				case Cell::CellAge::Live_Average:
					next_generation[i][j] = Cell::CellAge::Live_Weak;
					break;
				case Cell::CellAge::Live_Weak:
					next_generation[i][j] = Cell::CellAge::Live_Weak;
					break;
				}
			}
			else if (count > 3)
				next_generation[i][j] = Cell::CellAge::Dead;
		}
	}

	Cell::CellAge **temp = current_generation;
	current_generation = next_generation;
	next_generation = temp;
}

void Matrix::onLeftClick(sf::Vector2i &position)
{
	if ((position.x >= 0) &&
		(position.x < Game::SCREEN_WIDTH) &&
		(position.y >= 0) &&
		(position.y < Game::SCREEN_HEIGHT / 8 * 7))
	{
		int row_position = position.y / 7;
		int col_position = position.x / 7;
		current_generation[row_position][col_position] = Cell::CellAge::Live_Strong;
	}
}

void Matrix::onRightClick(sf::Vector2i &position)
{
	if ((position.x >= 0) &&
		(position.x < Game::SCREEN_WIDTH) &&
		(position.y >= 0) &&
		(position.y < Game::SCREEN_HEIGHT / 8 * 7))
	{
		int row_position = position.y / 7;
		int col_position = position.x / 7;
		current_generation[row_position][col_position] = Cell::CellAge::Dead;
	}
}

Cell::CellAge **Matrix::getMatrixPointer() const
{
	return current_generation;
}

int Matrix::getLiveCellCount() const
{
	int count = 0;
	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_cols; ++j)
		{
			if (current_generation[i][j] != Cell::CellAge::Dead)
				count++;
		}
	}
	
	return count;
}

int Matrix::getLivingNeighborCount(int row, int col)
{
	int count = 0;

	// Check cell on the right.
	if (col < num_cols - 1)
		if (current_generation[row][col + 1] != Cell::CellAge::Dead)
			count++;

	// Check cell on the bottom right.
	if (row < num_rows - 1 && col < num_cols - 1)
		if (current_generation[row + 1][col + 1] != Cell::CellAge::Dead)
			count++;

	// Check cell on the bottom.
	if (row < num_rows - 1)
		if (current_generation[row + 1][col] != Cell::CellAge::Dead)
			count++;

	// Check cell on the bottom left.
	if (row < num_rows - 1 && col > 0)
		if (current_generation[row + 1][col - 1] != Cell::CellAge::Dead)
			count++;

	// Check cell on the left.
	if (col > 0)
		if (current_generation[row][col - 1] != Cell::CellAge::Dead)
			count++;

	// Check cell on the top left.
	if (row > 0 && col > 0)
		if (current_generation[row - 1][col - 1] != Cell::CellAge::Dead)
			count++;

	// Check cell on the top.
	if (row > 0)
		if (current_generation[row - 1][col] != Cell::CellAge::Dead)
			count++;

	// Check cell on the top right.
	if (row > 0 && col < num_cols - 1)
		if (current_generation[row - 1][col + 1] != Cell::CellAge::Dead)
			count++;

	return count;
}