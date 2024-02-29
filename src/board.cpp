#include "board.h"


Board::Board()
	:m_board({}), m_cheeseCount(0)
{

}
std::vector<std::vector<Tile>>& Board::getBoard()
{
	return m_board;
}

int Board::getCheeseCount() const
{
	return m_cheeseCount;
}

void Board::draw(sf::RenderWindow& game)
{
	for (int i = 0; i < size(m_board); i++)
	{
		for (int j = 0; j < size(m_board[i]); j++)
		{
			m_board[i][j].draw(game);
		}
	}
}

void Board::updateCheeseCount()
{
	m_cheeseCount++;
}

void Board::resetCheeseCount()
{
	m_cheeseCount = 0;
}
