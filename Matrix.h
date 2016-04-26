#pragma once
#include "SFML/Graphics.hpp"
#include"Cell.h"

class Matrix
{
public:
	Matrix(int, int);
	~Matrix();

	void randomize();
	void clear();
	void update();
	void onLeftClick(sf::Vector2i &position);
	void onRightClick(sf::Vector2i &position);
	
	Cell::CellAge **getMatrixPointer() const;
	int getLiveCellCount() const;

	int num_rows;
	int num_cols;

private:
	int getLivingNeighborCount(int row, int col);

	Cell::CellAge **current_generation;
	Cell::CellAge **next_generation;
};