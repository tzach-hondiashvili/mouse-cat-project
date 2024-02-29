#include "key.h"

Key::Key(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "key",controller)
{

}

void Key::collide(Mouse& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	deleteFlag = true;
	otherObject.updateKeys(1);
	static sf::Sound pickupKey;
	pickupKey.setBuffer(soundFX[3]);
	pickupKey.play();
}