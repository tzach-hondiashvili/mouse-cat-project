#pragma once
#include <SFML/Graphics.hpp>


class Tile
{
public:
	Tile();
	Tile(sf::Texture* texture, int i, int j);
	sf::Texture* getTexture() const;
	sf::Vector2f getLocation() const;
	sf::Vector2f getSize() const;

	void setTexture(sf::Texture * texture);
	void draw(sf::RenderWindow& game);


private:
	sf::Texture* m_texture;
	sf::RectangleShape m_shape;
};