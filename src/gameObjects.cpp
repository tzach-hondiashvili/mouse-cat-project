#include "gameObjects.h"

GameObjects::GameObjects()
	:m_Location({0,0}), m_Size({0,0}), m_sprite(sf::Sprite()), m_Type("")
{

}

void GameObjects::setSize(sf::Vector2f newSize)
{
	m_Size = newSize;
}

void GameObjects::setLocation(sf::Vector2f newLocation)
{
	m_Location = newLocation;
}

sf::Vector2f GameObjects::getLocation() const
{
	return m_Location;
}
sf::Vector2f GameObjects::getSize() const
{
	return m_Size;
}

void GameObjects::setTexture(sf::Texture* newTexture)
{
	m_sprite.setTexture(*newTexture);
}
const sf::Texture* GameObjects::getTexture() const
{
	auto temp = m_sprite.getTexture();
	return temp;
}
void GameObjects::setType(std::string newType)
{
	m_Type = newType;
}
std::string GameObjects::getType() const
{
	return m_Type;
}
void GameObjects::setSpriteLocation(sf::Vector2f newLocation)
{
	m_sprite.setPosition(newLocation);
}
sf::Sprite& GameObjects::getSprite()
{
	return m_sprite;
}
GameObjects::GameObjects(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, std::string newType)
{
	m_Type = newType;
	m_Size = newSize;
	m_sprite.setTexture(*newTexture);

	newLocation.x = newLocation.x + 20;
	newLocation.y = newLocation.y + 20;
	m_Location = newLocation;

	m_sprite.setPosition(newLocation);
	m_sprite.setOrigin(getSprite().getLocalBounds().width / 2.f, getSprite().getLocalBounds().height / 2.f);
	m_sprite.setScale(m_Size.x  / m_sprite.getLocalBounds().width, m_Size.y / m_sprite.getLocalBounds().height);
}

