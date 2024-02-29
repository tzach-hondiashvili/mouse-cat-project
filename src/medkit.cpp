#include "medkit.h"

Medkit::Medkit(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize,Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "medkit",controller)
{

}

void Medkit::collide(Mouse& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	deleteFlag = true;
	otherObject.updateLives(1);
	otherObject.updateScore(5);
	static sf::Sound pickupMedkit;
	pickupMedkit.setBuffer(soundFX[4]);
	pickupMedkit.setVolume(70);
	pickupMedkit.play();
}