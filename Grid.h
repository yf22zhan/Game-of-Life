#pragma once
#include "SFML/Graphics.hpp"

class Grid
{
public:
	Grid(int tile_dimension = 6);
	~Grid();

	int getTileDimension() const;
	int getBorderTileDimension() const;
	int getWitdth() const;
	int getHeight() const;
	int getHorizontalLineCount() const;
	int getVerticalLineCount() const;
	sf::VertexArray &getHorizontalLines();
	sf::VertexArray &getVerticalLines();

private:
	int tile_dimension;
	int border_tile_dimension;
	int grid_width;
	int grid_height;
	int num_horizontal_lines;
	int num_vertical_lines;
	sf::VertexArray horizontal_lines;
	sf::VertexArray vertical_lines;
};