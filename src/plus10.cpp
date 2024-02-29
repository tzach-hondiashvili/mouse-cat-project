#include "plus10.h"
#include "controller.h"

Plus10::Plus10(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "plus10", controller)
{

}

void Plus10::collide(Mouse& /*otherObject*/, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	deleteFlag = true;
	getController()->increaseTime();
	static sf::Sound pickupPlus10;
	pickupPlus10.setBuffer(soundFX[9]);
	pickupPlus10.play();
}