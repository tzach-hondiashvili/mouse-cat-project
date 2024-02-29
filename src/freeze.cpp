#include "freeze.h"
#include "controller.h"

Freeze::Freeze(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize,Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "freeze", controller)
{

}

void Freeze::collide(Mouse& /*otherObject*/, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	deleteFlag = true;
	getController()->resetFreezeTime();

	static sf::Sound pickupFreeze;
	pickupFreeze.setBuffer(soundFX[8]);
	pickupFreeze.setVolume(100);
	pickupFreeze.play();
}