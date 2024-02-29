#include "portal.h"

Portal::Portal(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "portal",controller),m_TPLocation(sf::Vector2f(0,0))
{

}

void Portal::collide(Mouse& otherObject, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& soundFX)
{
	static sf::Sound portal;

	otherObject.getSprite().setPosition(m_TPLocation + (sf::Vector2f(0, 40)));
	portal.setBuffer(soundFX[6]);
	portal.setVolume(100);
	portal.play();
}

void Portal::setTPLocation(sf::Vector2f TPLocation)
{
	m_TPLocation = TPLocation;
}
