#pragma once
#include <SFML\Graphics.hpp>
class Text {
public:
	sf::Text text;
	Text(std::string textString, float size, sf::Vector2f pos, sf::Color color, std::string fontFile) {
		font.loadFromFile(fontFile);
		text.setFont(font);
		text.setString(textString);
		text.setCharacterSize(size);
		text.setFillColor(color);
		text.setPosition(pos);
	}

	void showTo(sf::RenderWindow &window) {
		window.draw(text);
	}

	void setText(std::string textString) {
		text.setString(textString);
	}


private:
	sf::Font font;

};