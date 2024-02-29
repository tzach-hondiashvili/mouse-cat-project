#pragma once
#include <vector>
#include "tile.h"


class Board
{
public:
	Board();
	std::vector<std::vector<Tile>>& getBoard();
	void draw(sf::RenderWindow& game);
	int getCheeseCount() const;
	void updateCheeseCount();
	void resetCheeseCount();

private:
	std::vector<std::vector<Tile>> m_board;
	int m_cheeseCount;
};