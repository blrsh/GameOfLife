#include "Cell.h"
#include <sfml/Graphics.hpp>
#include "Config.h"


Cell::Cell(int rowNum, int colNum, bool isAlive)
{
	//Config config;
	setState(isAlive);
	row = rowNum;
	col = colNum;
	cell.setSize({ (float)config.cellSize - config.gridSize, (float)config.cellSize - config.gridSize });
	cell.setPosition(config.cellSize*col, config.cellSize*row);
}

void Cell::showTo(sf::RenderWindow & window)
{
	window.draw(cell);
}

void Cell::setState(bool isAlive)
{
	//Config config;
	state = isAlive;
	if (state) {
		cell.setFillColor(config.aliveColor);
	}
	else {
		cell.setFillColor(config.deadColor);
	}
}

sf::Vector2i Cell::getPos()
{
	return sf::Vector2i(row, col);
}

