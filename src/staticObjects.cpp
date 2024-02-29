#include "staticObjects.h"

StaticObjects::StaticObjects()
	:GameObjects()
{

}
StaticObjects::StaticObjects(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, std::string newType,Controller* controller)
	:GameObjects(newTexture, newLocation, newSize, newType)
{
	m_controller = controller;
}

Controller* StaticObjects::getController()
{
	return m_controller;
}