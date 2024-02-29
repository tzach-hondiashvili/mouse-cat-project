#pragma once
#include "staticObjects.h"
#include "mouse.h"


class Portal :public StaticObjects
{
public:
	Portal(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, Controller* controller);
	void collide(Mouse& otherObject, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& soundFX) override;
	void collide(GameObjects& /*otherObject*/, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& /*soundFX*/) override {};
	void setTPLocation(sf::Vector2f TPLocation);
private:
	sf::Vector2f m_TPLocation;
};