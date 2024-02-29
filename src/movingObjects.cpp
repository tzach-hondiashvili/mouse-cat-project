#include "movingObjects.h"

MovingObjects::MovingObjects()
	:m_direction(sf::Vector2(0,0)),m_prevLocation(sf::Vector2f(0,0))
{

}
MovingObjects::MovingObjects(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, std::string newType)
	:GameObjects(newTexture, newLocation, newSize, newType)
{

}
void MovingObjects::setDirection(sf::Vector2f newDirection)
{
	m_direction = newDirection;
}
void MovingObjects::setPrev_location(sf::Vector2f prevLocation)
{
	m_prevLocation = prevLocation;
}

sf::Vector2f MovingObjects::getPrevLocation() const
{
	return m_prevLocation;
}

sf::Vector2f MovingObjects::getDirection() const
{
	return m_direction;
}

bool MovingObjects::isBlocked(sf::Vector2f move, std::vector <std::vector <Tile>> &board)
{
	auto mouseBounds = getSprite().getGlobalBounds();

	sf::Vector2f topBound(board[0][0].getLocation());
	sf::Vector2f bottomBound(board[14][22].getLocation() + board[0][0].getSize());

	// Check if the mouse is outside the bounds
	if (mouseBounds.left < topBound.x ||
		mouseBounds.left + mouseBounds.width > bottomBound.x ||
		mouseBounds.top < topBound.y ||
		mouseBounds.top + mouseBounds.height > bottomBound.y)
	{
		// Handle reflection if the mouse is outside bounds &
		// Reflect back into the playable area
		if (mouseBounds.left < topBound.x)
			getSprite().setPosition(topBound.x + mouseBounds.width, getSprite().getPosition().y);
		else if (mouseBounds.left + mouseBounds.width > bottomBound.x)
			getSprite().setPosition(bottomBound.x - mouseBounds.width, getSprite().getPosition().y);
		if (mouseBounds.top < topBound.y)
			getSprite().setPosition(getSprite().getPosition().x, topBound.y + mouseBounds.height);
		else if (mouseBounds.top + mouseBounds.height > bottomBound.y)
			getSprite().setPosition(getSprite().getPosition().x, bottomBound.y - mouseBounds.height);

		return true;
	}
	return false;
}