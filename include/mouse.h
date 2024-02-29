#pragma once
#include "movingObjects.h"
#include "tile.h"
#include "cat.h"

class Mouse : public MovingObjects
{
public:
	Mouse();
	int getLives() const;
	void updateLives(int amount);
	int getScore() const;
	void updateScore(int amount);
	int getKeys() const;
	int getEatenCheeses() const;
	void eatCheese();
	void updateKeys(int amount);
	void drawMouse(sf::RenderWindow& game) ;
	void moveMouse(sf::Time deltaTime, std::vector <std::vector <Tile>> &board);
	void collisionWithCats(std::vector<Cat> &cats, sf::SoundBuffer& hit);
	void handleCatCollision(std::vector<Cat> &cats, sf::SoundBuffer &hit);
	void resetEatenCheese();
	
	//collision
	void collide(GameObjects& otherObject,bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX) override;
	bool checkCollision(GameObjects& otherObject);
	void collide(Mouse& /*otherObject*/, bool &/*deleteFlag*/, const std::vector <sf::SoundBuffer>& /*soundFX*/) override {};
private:
	int m_Lives, m_Score, m_Keys, m_eatenCheeses;
	
};