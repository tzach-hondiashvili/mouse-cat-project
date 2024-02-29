#include "wall.h"

Wall::Wall(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "wall",controller)
{

}

void Wall::collide(Mouse& otherObject, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& /*soundFX*/)
{
	otherObject.getSprite().setPosition(otherObject.getPrevLocation());
}

