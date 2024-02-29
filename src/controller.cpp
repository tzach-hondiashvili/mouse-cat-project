#include "controller.h"
#include <fstream>
//#include "portal.h"

Controller::Controller()
	:m_board(Board()), m_mouse(Mouse()), m_Level(1), m_cats({}),m_freezeTimer(sf::seconds(5)),m_addedTime(sf::seconds(0))
{

}

Board& Controller::getBoardForController()
{
	return m_board;
}

std::vector<Cat>& Controller::getCats()
{
	return m_cats;
}

sf::Time Controller::getFreezeTime()
{
	return m_freezeTimer;
}

void Controller::resetFreezeTime()
{
	m_freezeTimer = sf::seconds(0);
}

void Controller::addTime(sf::Time deltaTime)
{
	m_freezeTimer += deltaTime;
}

void Controller::updatePortal()
{
	int port1Index = -1, port2Index = -1,index = 1;

	for (int i = 0; i < size(m_staticObjects); i++)
	{
		if (m_staticObjects[i]->getType() == "portal")
		{
			if (index == 1)
			{
				port1Index = i;
				index++;
			}
			else if (index == 2)
			{
				port2Index = i;
			}
		}
	}

	if (port2Index == -1)
	{
		return;
	}

	auto* portal1 = dynamic_cast<Portal*>(m_staticObjects[port1Index].get());
	auto* portal2 = dynamic_cast<Portal*>(m_staticObjects[port2Index].get());

	portal1->setTPLocation(portal2->getSprite().getPosition());
	portal2->setTPLocation(portal1->getSprite().getPosition());
}

void Controller::resetKeys()
{
	while (m_mouse.getKeys() != 0)
	{
		m_mouse.updateKeys(-1);
	}
}

void Controller::increaseTime()
{
	m_addedTime += sf::seconds(10);
}

float Controller::getAddedTime()
{
	return m_addedTime.asSeconds();
}

void Controller::resetAddedTime()
{
	m_addedTime = sf::seconds(0);
}

void Controller::updateBoard(std::vector<sf::Texture>& textures)
{
	std::ifstream file("board" + std::to_string(m_Level)+".txt");
	char temp_char;
	std::vector<Tile> temp_line;
	sf::Vector2f temp_size;
	Tile temp_tile;
	int i = 0, j = 0;
	

	if (file.is_open())
	{
		while (!file.eof())
		{
			file.get(temp_char);

			while (temp_char != '\n')
			{
				temp_tile = Tile(&textures[3], i, j);

				switch (temp_char) {
				case '%':
					m_mouse.getSprite().setPosition(sf::Vector2f(temp_tile.getLocation().x + 20,temp_tile.getLocation().y + 20));
					m_mouse.getSprite().setOrigin(m_mouse.getSprite().getLocalBounds().width / 2.f, m_mouse.getSprite().getLocalBounds().height / 2.f);
					m_mouse.setLocation(sf::Vector2f(sf::Vector2f(temp_tile.getLocation().x + 20, temp_tile.getLocation().y + 20)));
					temp_size = temp_tile.getSize();
					temp_size.x -= 15;
					temp_size.y -= 15;
					m_mouse.setSize(temp_size);
					m_mouse.setTexture(&textures[9]);
					m_mouse.getSprite().setScale(m_mouse.getSize().x / m_mouse.getSprite().getLocalBounds().width, m_mouse.getSize().y / m_mouse.getSprite().getLocalBounds().height);
					break;
				case '*':
					m_staticObjects.push_back(std::make_unique<Cheese>(&textures[8], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(10, 10),this));
					m_board.updateCheeseCount();
					break;
				case 'F':
					m_staticObjects.push_back(std::make_unique<Key>(&textures[7], temp_tile.getLocation(), temp_tile.getSize(),this));
					break;
				case 'D':
					m_staticObjects.push_back(std::make_unique<Door>(&textures[5], temp_tile.getLocation(), temp_tile.getSize(),this));
					break;
				case '#':
					m_staticObjects.push_back(std::make_unique<Wall>(&textures[4], temp_tile.getLocation(), temp_tile.getSize(),this));
					break;
				case '^':
					m_cats.push_back(Cat(&textures[10], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(13, 13)));
					break;
				case '3':
					m_staticObjects.push_back(std::make_unique<Medkit>(&textures[12], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(13, 13),this));
					break;
				case 'z':
					m_staticObjects.push_back(std::make_unique<Freeze>(&textures[13], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(13, 13),this));
					break;
				case '$':
					m_staticObjects.push_back(std::make_unique<Gift>(&textures[14], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(13, 13),this));
					break;
				case 'p':
					m_staticObjects.push_back(std::make_unique<Portal>(&textures[15], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(13, 13),this));
					break;
				case '+':
					m_staticObjects.push_back(std::make_unique<Plus10>(&textures[18], temp_tile.getLocation(), temp_tile.getSize() - sf::Vector2f(13, 13), this));
					break;
				default:
					break;
				}


				
				temp_line.push_back(temp_tile);
				i++;
				file.get(temp_char);
			}
			m_board.getBoard().push_back(temp_line);
			temp_line.clear();
			j++;
			i = 0;
		}
	}


}

void Controller::clearBoard()
{
	m_board.getBoard().clear();
	m_staticObjects.clear();
	m_cats.clear();
}

Mouse& Controller::getMouse()
{
	return m_mouse;
}

void Controller::drawStatics(sf::RenderWindow &game)
{
	for (int i = 0; i < size(m_staticObjects); i++)
	{
		game.draw(m_staticObjects[i]->getSprite());
	}
}

int Controller::getCheeseCount()
{
	return m_board.getCheeseCount();
}

void Controller::moveCats(std::vector<std::unique_ptr<StaticObjects>> &statics, std::vector <std::vector <Tile>>& board, sf::Time deltaTime)
{
	for (int i = 0; i < size(m_cats); i++)
	{
		m_cats[i].move(statics, board, deltaTime,m_mouse.getSprite().getPosition());
	}
}

std::vector<std::unique_ptr<StaticObjects>>& Controller::getStatics()
{
	return m_staticObjects;
}

int Controller::getLevel()
{
	return m_Level;
}
void Controller::UpdateLevel(int numOfLevel)
{
	m_Level += numOfLevel;
}

void Controller::handleCollision(const std::vector <sf::SoundBuffer>& soundFX)
{
	int indexCollided = -1;
	bool deleteFlag = false;

	for (int i = 0; i < size(m_staticObjects); i++)
	{
		if (m_mouse.checkCollision(*m_staticObjects[i]))//if collided
		{
			m_mouse.collide(*m_staticObjects[i], deleteFlag, soundFX);
			indexCollided = i;
			break; //break if collided
		}
	}
	if (indexCollided >= 0 && deleteFlag)
	{
		m_staticObjects.erase(m_staticObjects.begin() + indexCollided);
	}
}


void Controller::drawCats(sf::RenderWindow& window)
{
	for (int i = 0; i < size(m_cats); i++)
	{
		m_cats[i].drawCat(window);
	}
}