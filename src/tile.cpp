#include "tile.h"

Tile::Tile()
	:m_texture(NULL), m_shape(sf::RectangleShape())
{

}
sf::Texture* Tile::getTexture() const
{
	return m_texture;

}
sf::Vector2f Tile::getLocation() const
{
	return m_shape.getPosition();
}
sf::Vector2f Tile::getSize() const
{
	return m_shape.getSize();
}
void Tile::setTexture(sf::Texture* texture)
{
	m_texture = texture;
}
Tile::Tile(sf::Texture* texture, int i, int j)
{
	m_texture = texture;

	sf::Vector2f temp;

	temp.x = float(470 + 40 * i);
	temp.y = float(110 + 40 * j);

	m_shape.setPosition(temp);
	m_shape.setSize({40,40});
}

void Tile::draw(sf::RenderWindow &game)
{
	sf::Sprite temp;

	temp.setTexture(*m_texture);
	temp.setPosition(m_shape.getPosition());
	temp.setScale((40) / temp.getLocalBounds().width, (40) / temp.getLocalBounds().height);

	game.draw(temp);

}