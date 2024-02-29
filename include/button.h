#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
public:
	Button();
	Button(sf::Vector2f location, sf::Vector2f size);
	void draw(sf::RenderWindow &game) const;
	void updateTexture(sf::Texture* newtTexture);
	void updateButtonLocation(sf::Vector2f newLocation);
	void setSize(sf::Vector2f newSize);
	sf::RectangleShape getShape();
	void drawButtonOutline(sf::RenderWindow& game);

private:
	sf::RectangleShape m_button;
	sf::Texture* m_texture;
};

	


