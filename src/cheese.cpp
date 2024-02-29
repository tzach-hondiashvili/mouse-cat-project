#include "cheese.h"



Cheese::Cheese(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller)
	:StaticObjects(newTexture, newLocation, newSize, "cheese",controller)
{
	
}
void Cheese::collide(Mouse& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	otherObject.eatCheese();
	otherObject.updateScore(25);
	deleteFlag = true;
	static sf::Sound eatCheese;
	eatCheese.setBuffer(soundFX[0]);
	eatCheese.play();
}