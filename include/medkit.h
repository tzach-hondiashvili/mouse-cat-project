#pragma once
#include "staticObjects.h"
#include "mouse.h"


class Medkit :public StaticObjects
{
public:
	Medkit(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize,Controller* controller);
	void collide(Mouse& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX) override;
	void collide(GameObjects& /*otherObject*/, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& /*soundFX*/) override {};
private:

};