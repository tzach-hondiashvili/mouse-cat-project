#include "mouse.h"

Mouse::Mouse()
	:m_Lives(3), m_Score(0), m_Keys(0),m_eatenCheeses(0)
{

}

void Mouse::collisionWithCats(std::vector<Cat> &cats, sf::SoundBuffer& hit)
{
	for (int i = 0; i < size(cats); i++)
	{
		if (cats[i].getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds()))
		{
			handleCatCollision(cats, hit);
			return;
		}
	}
}

void Mouse::handleCatCollision(std::vector<Cat>& cats, sf::SoundBuffer &hit)
{
	static sf::Sound sound;
	for (int i = 0; i < size(cats); i++)
	{
		cats[i].getSprite().setPosition(cats[i].getLocation());
	}
	getSprite().setPosition(getLocation());
	updateLives(-1);
	
	sound.setBuffer(hit);
	sound.play();
}

void Mouse::resetEatenCheese()
{
	m_eatenCheeses = 0;
}

int Mouse::getLives() const
{
	return m_Lives;
}
void Mouse::updateLives(int amount)
{
	m_Lives += amount;
}

int Mouse::getScore() const
{
	return m_Score;
}
void Mouse::updateScore(int amount)
{
	m_Score += amount;
}

int Mouse::getKeys() const
{
	return m_Keys;
}

void Mouse::updateKeys(int amount)
{
	m_Keys += amount;
}

void Mouse::eatCheese()
{
	m_eatenCheeses++;
}

void Mouse::drawMouse(sf::RenderWindow& game)
{
	game.draw(getSprite());
}

int Mouse::getEatenCheeses() const
{
	return m_eatenCheeses;
}

void Mouse::moveMouse(sf::Time deltaTime, std::vector <std::vector <Tile>> &board)
{
	const auto speedPerSecond = 150.f;
	setPrev_location(getSprite().getPosition());

	if (!isBlocked(getDirection() * speedPerSecond * deltaTime.asSeconds() , board))
	{
		getSprite().move(getDirection() * speedPerSecond * deltaTime.asSeconds());
	}
}
void Mouse::collide(GameObjects& otherObject, bool& deleteFlag, const std::vector <sf::SoundBuffer>& soundFX)
{
	otherObject.collide(*this, deleteFlag, soundFX);
}

bool Mouse::checkCollision(GameObjects& otherObject)
{
	if (getSprite().getGlobalBounds().intersects(otherObject.getSprite().getGlobalBounds()))
	{
		return true;
	}
	return false;
}

