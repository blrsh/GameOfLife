#include "Game.h"
#include <sfml/Graphics.hpp>
#include <iostream>
#include "Config.h"
#include "Cell.h"
using namespace std;
//dividing stuff
Config config;
int cellCols = config.cellCols;
int cellRows = config.cellRows;
int cellSize = config.cellSize;
vector<Cell> cells;

Game::Game()
{
	srand(time(NULL));
	sf::RenderWindow window(sf::VideoMode(config.screenX, config.screenY), "Game Of Life");
	window.setFramerateLimit(2000);
	//initial world generation
	for (int row = 0; row < cellRows; row++) {
		for (int col = 0; col < cellCols; col++) {
			cells.push_back(Cell(row, col, rand() & 1));
		}
	}

	while (window.isOpen()) gameLoop(window);
}

void Game::gameLoop(sf::RenderWindow & window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		reset();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) {
		for (int i = 0; i < cells.size(); i++) {
			cells.at(i).setState(false);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) {
		for (int i = 0; i < cells.size(); i++) {
			cells.at(i).setState(true);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;
		if (mouseX > 0 && mouseY > 0 && mouseX < config.screenX && mouseY < config.screenY) {
			int col = sf::Mouse::getPosition(window).x / config.cellSize;
			int row = sf::Mouse::getPosition(window).y / config.cellSize;
			cells.at(getIndex(row, col)).setState(true);
		}
	}

	if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
		float mouseX = sf::Mouse::getPosition(window).x;
		float mouseY = sf::Mouse::getPosition(window).y;
		if (mouseX > 0 && mouseY > 0 && mouseX < config.screenX && mouseY < config.screenY) {
			int col = sf::Mouse::getPosition(window).x / config.cellSize;
			int row = sf::Mouse::getPosition(window).y / config.cellSize;
			cells.at(getIndex(row, col)).setState(false);
		}
	}

	//RULES
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
		window.setFramerateLimit(config.frameRate);
		editMode = false;
		gen++;
		window.setTitle("Game Of Life - Generation " + to_string(gen));
		for (int i = 0; i < cells.size(); i++) {
			int neighbours = getNeighbours(i);
			bool alive = cells.at(i).state;

			if (alive) {
				if (neighbours < 2 || neighbours > 3) {
					cells.at(i).futureState = false;
				}
				else {
					cells.at(i).futureState = true;
				}
			}
			else {
				if (neighbours == 3) {
					cells.at(i).futureState = true;
				}
				else {
					cells.at(i).futureState = false;
				}
			}
		}
		updateCells();
	}
	else {
		editMode = true;
		window.setFramerateLimit(2000);
	}

	handleEvents(window);
	draw(window);
}

void Game::draw(sf::RenderWindow & window)
{
	window.clear();

	//draw cells
	for (int i = 0; i < cells.size(); i++) {
		cells.at(i).showTo(window);
	}
	window.display();
}

void Game::handleEvents(sf::RenderWindow & window)
{
	sf::Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::Closed) window.close();
	}
}

void Game::reset()
{
	gen = 0;
	for (int i = 0; i < cells.size(); i++) {
		cells.at(i).setState(rand() & 1);
	}

}

int Game::getIndex(int row, int col) {
	return cellCols*row + col;
}

int Game::getNeighbours(int index) {
	cells.at(index).cell.setFillColor(sf::Color::Red);
	int neighbours = 0;
	int row = getPos(index).x;
	int col = getPos(index).y;
	if (col < cellCols - 1 && isAlive(row, col + 1)) neighbours++;
	if (col > 0 && isAlive(row, col - 1)) neighbours++;
	if (row < cellRows - 1 && isAlive(row + 1, col)) neighbours++;
	if (row > 0 && isAlive(row - 1, col)) neighbours++;
	if (col < cellCols - 1 && row < cellRows - 1 && isAlive(row + 1, col + 1)) neighbours++;
	if (row < cellRows - 1 && col > 0 && isAlive(row + 1, col - 1)) neighbours++;
	if (row > 0 && col < cellCols - 1 && isAlive(row - 1, col + 1)) neighbours++;
	if (row > 0 && col > 0 && isAlive(row - 1, col - 1)) neighbours++;
	return neighbours;
}

bool Game::isAlive(int row, int col)
{
	return cells.at(getIndex(row, col)).state;
}

sf::Vector2i Game::getPos(int index)
{
	return cells.at(index).getPos();
}

void Game::updateCells()
{
	for (int i = 0; i < cells.size(); i++) {
		cells.at(i).setState(cells.at(i).futureState);
	}
}
