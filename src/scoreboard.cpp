#include "scoreboard.h"

Scoreboard::Scoreboard()
	:m_numberOfLives(sf::Text())
{

}

void Scoreboard::updateLives(int numberOfLives,sf::Font* newFont)
{
	m_numberOfLives.setString(std::to_string(numberOfLives));
	m_numberOfLives.setCharacterSize(50);
	m_numberOfLives.setFont(*newFont);
	m_numberOfLives.setOutlineColor(sf::Color::Black);
	m_numberOfLives.setOutlineThickness(3);
	m_numberOfLives.setPosition(sf::Vector2f(220, 420));
}

void Scoreboard::updateCheeses(int numberOfCheeses, sf::Font* newFont, int eatenCheases)
{
	m_numberOfCheeses.setString(std::to_string(numberOfCheeses - eatenCheases));
	m_numberOfCheeses.setCharacterSize(50);
	m_numberOfCheeses.setFont(*newFont);
	m_numberOfCheeses.setOutlineColor(sf::Color::Black);
	m_numberOfCheeses.setOutlineThickness(3);
	m_numberOfCheeses.setPosition(sf::Vector2f(220, 520));
}

sf::Text Scoreboard::getLives() const
{
	return m_numberOfLives;
}

sf::Text Scoreboard::getCheeses() const
{
	return m_numberOfCheeses;
}

void Scoreboard::updateScore(int Score, sf::Font* newFont)
{
	m_Score.setString(std::to_string(Score));
	m_Score.setScale(80.f / m_Score.getLocalBounds().width, 35.f / m_Score.getLocalBounds().height);
	m_Score.setCharacterSize(50);
	m_Score.setFont(*newFont);
	m_Score.setOutlineColor(sf::Color::Black);
	m_Score.setOutlineThickness(3);
	m_Score.setPosition(sf::Vector2f(305, 227));
}

sf::Text Scoreboard::getScore() const
{
	return m_Score;
}

void Scoreboard::updateKeys(int numberOfKeys, sf::Font* newFont)
{
	m_numberOfKeys.setString(std::to_string(numberOfKeys));
	m_numberOfKeys.setCharacterSize(50);
	m_numberOfKeys.setFont(*newFont);
	m_numberOfKeys.setOutlineColor(sf::Color::Black);
	m_numberOfKeys.setOutlineThickness(3);
	m_numberOfKeys.setPosition(sf::Vector2f(220, 604));
}

sf::Text Scoreboard::getKeys() const
{
	return m_numberOfKeys;
}

void Scoreboard::updateLevel(int numberOfLevel, sf::Font* newFont)
{
	m_Level.setString(std::to_string(numberOfLevel));
	m_Level.setCharacterSize(50);
	m_Level.setFont(*newFont);
	m_Level.setOutlineColor(sf::Color::Black);
	m_Level.setOutlineThickness(3);
	m_Level.setPosition(sf::Vector2f(305, 125));
}

sf::Text Scoreboard::getLevel() const
{
	return m_Level;
}

void Scoreboard::updateTime(sf::Clock Timer, sf::Font* newFont, float addedTime)
{
	sf::Time deltaTime = sf::seconds((float)2 * 60 - Timer.getElapsedTime().asSeconds() + addedTime);
	int minutes = deltaTime.asSeconds() / 60,
		seconds = int(deltaTime.asSeconds()) % 60;

	std::string temp = std::to_string(minutes)+":"+std::to_string(seconds);

	m_Time.setString(temp);
	m_Time.setCharacterSize(50);
	m_Time.setFont(*newFont);
	m_Time.setOutlineColor(sf::Color::Black);
	m_Time.setOutlineThickness(3);
	m_Time.setPosition(sf::Vector2f(208, 320));
}

sf::Text Scoreboard::getTime() const
{
	return m_Time;
}