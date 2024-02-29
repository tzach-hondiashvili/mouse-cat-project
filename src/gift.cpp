#include "gift.h"
#include "controller.h"

Gift::Gift(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize,Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "gift",controller)
{

}

void Gift::collide(Mouse& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	deleteFlag = true;
	int num = rand() % size(getController()->getCats());

	getController()->getCats().erase(getController()->getCats().begin() + num);
	otherObject.updateScore(10);

	static sf::Sound killCat;
	killCat.setBuffer(soundFX[5]);
	killCat.setVolume(100);
	killCat.play();
}