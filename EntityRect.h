#pragma once
#include <sfml/Graphics.hpp>
class EntityRect
{
public:
	float x, y, velX, velY, accX, accY, width, height;
	EntityRect(sf::Vector2f size, sf::Vector2f pos);
	void show(sf::RenderWindow& window);

	void setColor(sf::Color color);
	sf::FloatRect getBounds();
	void setSize(sf::Vector2f size);

protected:
	sf::RectangleShape entity;
};

