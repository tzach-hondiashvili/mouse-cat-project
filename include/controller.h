#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "board.h"
#include "staticObjects.h"
#include "cheese.h"
#include "key.h"
#include "door.h"
#include "wall.h"
#include "cat.h"
#include "medkit.h"
#include "freeze.h"
#include "gift.h"
#include "portal.h"
#include "plus10.h"

class Mouse;

class Controller
{
public:
	Controller();
	Board & getBoardForController();
	void updateBoard(std::vector<sf::Texture>& textures);
	void drawCats(sf::RenderWindow &window);
	Mouse& getMouse();
	void clearBoard();
	void drawStatics(sf::RenderWindow& game);
	int getCheeseCount();
	int getLevel();
	void UpdateLevel(int numOfLevel);
	void handleCollision(const std::vector <sf::SoundBuffer> &soundFX);
	void moveCats(std::vector<std::unique_ptr<StaticObjects>> &statics, std::vector <std::vector <Tile>>& board, sf::Time deltaTime);
	std::vector<std::unique_ptr<StaticObjects>>& getStatics();
	std::vector<Cat>& getCats();
	sf::Time getFreezeTime();
	void resetFreezeTime();
	void addTime(sf::Time deltaTime);
	void updatePortal();
	void resetKeys();
	void increaseTime();
	float getAddedTime();
	void resetAddedTime();

private:
	Board m_board;
	Mouse m_mouse;
	std::vector<std::unique_ptr<StaticObjects>> m_staticObjects;
	std::vector <Cat> m_cats;
	int m_Level;
	sf::Time m_freezeTimer,m_addedTime;
};