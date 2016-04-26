#include "Grid.h"
#include "Game.h"

Grid::Grid(int tile_dimension) :
	tile_dimension(tile_dimension),
	border_tile_dimension(tile_dimension + 1),
	grid_width(Game::SCREEN_WIDTH),
	grid_height(Game::SCREEN_HEIGHT / 8 * 7),
	num_horizontal_lines(grid_height / border_tile_dimension),
	num_vertical_lines(grid_width / border_tile_dimension),
	horizontal_lines(sf::Lines, num_horizontal_lines * 2),
	vertical_lines(sf::Lines, num_vertical_lines * 2)
{
	for (int i = 0; i < (num_horizontal_lines * 2); i += 2)
	{
		horizontal_lines[i].position =
			sf::Vector2f(0, border_tile_dimension * (i / 2 + 1));
		horizontal_lines[i].color = sf::Color(192, 192, 192);
		horizontal_lines[i + 1].position =
			sf::Vector2f(grid_width, border_tile_dimension * (i / 2 + 1));
		horizontal_lines[i + 1].color = sf::Color(192, 192, 192);
	}

	for (int i = 0; i < (num_vertical_lines * 2); i += 2)
	{
		vertical_lines[i].position =
			sf::Vector2f(border_tile_dimension * (i / 2 + 1), 0);
		vertical_lines[i].color = sf::Color(192, 192, 192);
		vertical_lines[i + 1].position =
			sf::Vector2f(border_tile_dimension * (i / 2 + 1), grid_height);
		vertical_lines[i + 1].color = sf::Color(192, 192, 192);
	}
}

Grid::~Grid()
{
}

int Grid::getTileDimension() const
{
	return tile_dimension;
}

int Grid::getBorderTileDimension() const
{
	return border_tile_dimension;
}

int Grid::getWitdth() const
{
	return grid_width;
}

int Grid::getHeight() const
{
	return grid_height;
}

int Grid::getHorizontalLineCount() const
{
	return num_horizontal_lines;
}

int Grid::getVerticalLineCount() const
{
	return num_vertical_lines;
}

sf::VertexArray &Grid::getHorizontalLines()
{
	return horizontal_lines;
}

sf::VertexArray &Grid::getVerticalLines()
{
	return vertical_lines;
}