#include "cat.h"

Cat::Cat(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize)
	:MovingObjects(newTexture,newLocation,newSize, "cat")
{

}

void Cat::move(std::vector<std::unique_ptr<StaticObjects>> &statics, std::vector <std::vector <Tile>>& board, sf::Time deltaTime,sf::Vector2f mousePos)
{
	const auto speedPerSecond = 70.f;

	setPrev_location(getSprite().getPosition());

	sf::Vector2f directions [4];

	directions[0] = getSprite().getPosition() + sf::Vector2f(1, 0);//right
	directions[1] = getSprite().getPosition() + sf::Vector2f(-1, 0);//left
	directions[2] = getSprite().getPosition() + sf::Vector2f(0, 1);//up
	directions[3] = getSprite().getPosition() + sf::Vector2f(0, -1);//down

	sortDirections(directions,4,mousePos);

	for (int i = 0; i < 4; i++)
	{

		setDirection(directions[i] - getSprite().getPosition());
		getSprite().move(getDirection()* speedPerSecond * deltaTime.asSeconds());

		if (isLegal(statics, getDirection(), board))
		{
			return;
		}
		getSprite().setPosition(getPrevLocation());
	}
}
void Cat::sortDirections(sf::Vector2f directions[], int size, const sf::Vector2f& target)
{
	// Bubble sort implementation
	for (int i = 0; i < size - 1; ++i)
	{
		for (int j = 0; j < size - i - 1; ++j)
		{
			// Calculate squared distances
			float dist1 = squaredDistance(directions[j], target);
			float dist2 = squaredDistance(directions[j + 1], target);

			// Swap if the squared distance of the current direction is greater than the next one
			if (dist1 > dist2)
			{
				std::swap(directions[j], directions[j + 1]);
			}
		}
	}
}

float Cat::squaredDistance(const sf::Vector2f& v1, const sf::Vector2f& v2) 
{
	float dx = v1.x - v2.x;
	float dy = v1.y - v2.y;
	return dx * dx + dy * dy;
}

// Comparator function to compare two vectors based on their squared distance from the target
bool Cat::compareDistances(const sf::Vector2f& v1, const sf::Vector2f& v2, const sf::Vector2f& target) 
{
	return squaredDistance(v1, target) < squaredDistance(v2, target);
}

void Cat::drawCat(sf::RenderWindow &window)
{
	window.draw(getSprite());
}

bool Cat::isLegal(std::vector<std::unique_ptr<StaticObjects>> &statics, sf::Vector2f move, std::vector <std::vector <Tile>> &board)
{	
		for (int i = 0; i < size(statics); i++)
		{
			if (statics[i]->getSprite().getGlobalBounds().intersects(getSprite().getGlobalBounds()))
			{
				if (statics[i]->getType() == "door" || statics[i]->getType() == "wall")
				{
					return false;
				}
			}
		}
		return !isBlocked(move, board);
}

sf::Vector2f Cat::calculateDirection(std::vector<std::unique_ptr<StaticObjects>>& /*statics*/, std::vector <std::vector <Tile>>& /*board*/, sf::Vector2f mousePos)
{
	int chooseRand = rand() % 100;
	//int randAmount

	if (chooseRand == 0)
	{
		int randNum = rand() % 4;

		switch (randNum)
		{
		case 0:
			return sf::Vector2f(1, 0);
		case 1:
			return sf::Vector2f(-1, 0);
		case 2:
			return sf::Vector2f(0, 1);
		case 3:
			return sf::Vector2f(0, -1);
		}
	}

	float xDistance, yDistance;

	xDistance = std::abs(mousePos.x - getSprite().getPosition().x);
	yDistance = std::abs(mousePos.y - getSprite().getPosition().y);

	if (xDistance > yDistance)
	{
		if (mousePos.x > getSprite().getPosition().x) //mouse to the right
		{
			return sf::Vector2f(1, 0);
		}
		else//mouse to the left
		{
			return sf::Vector2f(-1, 0);
		}
	}
	else// y greater
	{
		if (mousePos.y > getSprite().getPosition().y) //mouse is above
		{
			return sf::Vector2f(0, 1);
		}
		else//mouse is below
		{
			return sf::Vector2f(0, -1);
		}
	}
}