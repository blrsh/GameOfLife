#pragma once
#include <sfml/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Config {
/*public:
	float screenX = 1920;
	float screenY = 980;
	int cellCols = 80;
	int cellRows = 40;
	int cellSize = 24;
	int gridSize = 1;
	int frameRate = 30;
	sf::Color aliveColor = sf::Color::Blue;
	sf::Color deadColor = sf::Color::White;*/

public:
	int screenX, screenY, cellCols, cellRows, cellSize, gridSize, frameRate;
	int vals[10];
	sf::Color aliveColor, deadColor;
	int i = 0;
	Config() {
		ifstream file("config.txt");
		string word;
		int value;
		while (file >> word >> value) {
			vals[i] = value;
			i++;
		}
		screenX = vals[0];
		screenY = vals[1];
		cellRows = vals[2];
		cellCols = vals[3];
		cellSize = vals[4];
		gridSize = vals[5];
		frameRate = vals[6];
		aliveColor = toColor(vals[7]);
		deadColor = toColor(vals[8]);

	}

	sf::Color toColor(int c) {
		switch (c) {
		case 0:
			return sf::Color::White;
			break;
		case 1:
			return sf::Color::Black;
			break;
		case 2:
			return sf::Color::Red;
			break;
		case 3:
			return sf::Color::Green;
			break;
		case 4:
			return sf::Color::Blue;
			break;
		case 5:
			return sf::Color::Yellow;
			break;
		case 6:
			return sf::Color::Magenta;
			break;
		case 7:
			return sf::Color::Cyan;
			break;
		default:
			return sf::Color::Black;
		}
	}
};