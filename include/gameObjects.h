#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <memory>


class Cat;
class Mouse;
class Cheese;

class GameObjects
{
public:
	GameObjects();
	GameObjects(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, std::string newType);
	virtual ~GameObjects() = default;
	void setSize(sf::Vector2f newSize);
	void setLocation(sf::Vector2f newLocation);
	void setTexture(sf::Texture* newTexture);
	void setType(std::string newType);

	const sf::Texture* getTexture()const;
	sf::Vector2f getLocation()const;
	sf::Vector2f getSize()const;
	std::string getType()const;
	void setSpriteLocation(sf::Vector2f newLocation);
	sf::Sprite &getSprite();

	//collision
	virtual void collide(GameObjects &otherObject, bool& deleteFlag ,const std::vector <sf::SoundBuffer>& soundFX) = 0;
	virtual void collide(Mouse &otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX) = 0;
	

	
private:
	sf::Vector2f m_Location,
				 m_Size;

	sf::Sprite m_sprite;
	std::string m_Type;
};
