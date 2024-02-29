#pragma once
#include "movingObjects.h"
#include "staticObjects.h"

class Cat : public MovingObjects
{
public:
	Cat(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize);
	void move(std::vector<std::unique_ptr<StaticObjects>> &statics, std::vector <std::vector <Tile>>& board, sf::Time deltaTime,sf::Vector2f mousePos);
	void collide(Mouse& /*otherObject*/, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& /*soundFX*/) override {};
	void collide(GameObjects& /*otherObject*/, bool& /*deleteFlag*/, const std::vector <sf::SoundBuffer>& /*soundFX*/) override {};
	void drawCat(sf::RenderWindow& window);
	bool isLegal(std::vector<std::unique_ptr<StaticObjects>> &statics, sf::Vector2f move, std::vector <std::vector <Tile>> &board);
	sf::Vector2f calculateDirection(std::vector<std::unique_ptr<StaticObjects>>& /*statics*/, std::vector <std::vector <Tile>>& /*board*/,sf::Vector2f mousePos);
	void sortDirections(sf::Vector2f directions[], int size, const sf::Vector2f& target);
	float squaredDistance(const sf::Vector2f& v1, const sf::Vector2f& v2);
	bool compareDistances(const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Vector2f& target);


private:

};