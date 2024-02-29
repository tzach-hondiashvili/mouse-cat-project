#include "door.h"

Door::Door(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "door",controller)
{

}
void Door::collide(Mouse& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	int numOfKeys = otherObject.getKeys();
    static sf::Sound soundDoor;
	if (numOfKeys !=0)
	{
		deleteFlag = true;
		otherObject.updateKeys(-1);
		soundDoor.setBuffer(soundFX[1]);
	}
	else
	{
		otherObject.getSprite().setPosition(otherObject.getPrevLocation());
		soundDoor.setBuffer(soundFX[2]);
	}
	soundDoor.setVolume(100);
	soundDoor.play();
}