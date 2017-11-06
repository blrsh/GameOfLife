#include "EntityRect.h"
#include <sfml/Graphics.hpp>

EntityRect::EntityRect(sf::Vector2f size, sf::Vector2f pos) 
{
	setSize(size);
	x = pos.x;
	y = pos.y;

	velX = 0;
	velY = 0;
	accX = 0;
	accY = 0;
}

void EntityRect::setColor(sf::Color color) {
	entity.setFillColor(color);
}

void EntityRect::show(sf::RenderWindow& window)
{
	entity.setPosition(x, y);
	x += velX;
	y += velY;
	velX += accX;
	velY += accY;
	window.draw(entity);
}
void EntityRect::setSize(sf::Vector2f size) {
	width = size.x;
	height = size.y;

	entity.setSize({ width, height });
}
sf::FloatRect EntityRect::getBounds() { return entity.getGlobalBounds(); }
