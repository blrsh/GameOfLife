#pragma once
#include <sfml/Graphics.hpp>
#include "Config.h"
class Cell
{
public:
	Cell(int rowNum, int colNum, bool isAlive);
	bool state, futureState = true;
	int row, col;
	void showTo(sf::RenderWindow & window);
	void setState(bool isAlive);
	sf::Vector2i getPos();
	sf::RectangleShape cell;
	Config config;
};
