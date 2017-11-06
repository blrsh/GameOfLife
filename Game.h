#pragma once
#include <sfml/Graphics.hpp>
class Game
{
public:
	Game();

private:
	void gameLoop(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	void handleEvents(sf::RenderWindow & window);
	void reset();
	int getIndex(int row, int col);
	int getNeighbours(int index);
	bool isAlive(int row, int col);
	sf::Vector2i getPos(int index);
	void updateCells();
	int gen = 0;
	bool editMode = true;
};

