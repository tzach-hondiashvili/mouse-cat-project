#pragma once
#include "gameObjects.h"
#include "tile.h"

class MovingObjects :public GameObjects
{
public:
	MovingObjects();
	MovingObjects(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, std::string newType);
	void setDirection(sf::Vector2f newDirection);
	sf::Vector2f getDirection() const;
	bool isBlocked(sf::Vector2f move, std::vector <std::vector <Tile>> &board);
	void setPrev_location(sf::Vector2f prevLocation);
	sf::Vector2f getPrevLocation() const;

private:
	sf::Vector2f m_direction,m_prevLocation;
};