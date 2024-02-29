#include<button.h>

Button::Button()
	: m_button(sf::RectangleShape())
{

}

Button::Button(sf::Vector2f location, sf::Vector2f size)
{
	m_button.setPosition(location);
	m_button.setSize(size);
}
void Button::updateTexture(sf::Texture* newTexture)
{
	m_texture = newTexture;
}

void Button::updateButtonLocation(sf::Vector2f newLocation)
{
	m_button.setPosition(newLocation);
}

void Button::setSize(sf::Vector2f newSize)
{
	m_button.setSize(newSize);
}

void Button::draw(sf::RenderWindow &game) const
{
	sf::Sprite temp;
	temp.setTexture(*m_texture);
	temp.setPosition(m_button.getPosition());
	temp.setScale((250) / temp.getLocalBounds().width, (250) / temp.getLocalBounds().height);
	game.draw(temp);
}
sf::RectangleShape Button::getShape()
{
	return m_button;
}

void Button::drawButtonOutline(sf::RenderWindow& game)
{
    sf::Vector2f outlinePosition = m_button.getPosition();

    // Draw the outline first
    sf::Sprite tempOutline;
    tempOutline.setTexture(*m_texture);
    tempOutline.setPosition({outlinePosition.x-30,outlinePosition.y-30});
    tempOutline.setScale(280.0f / tempOutline.getLocalBounds().width, 280.0f / tempOutline.getLocalBounds().height);

    // Increase the outline thickness by scaling the sprite
    float outlineThickness = 30.0f;
    tempOutline.setScale(tempOutline.getScale() + sf::Vector2f(outlineThickness / tempOutline.getLocalBounds().width, outlineThickness / tempOutline.getLocalBounds().height));
    tempOutline.setColor(sf::Color::White);

   

    // Draw the original sprite on top
    sf::Sprite tempImage;
    tempImage.setTexture(*m_texture);
    tempImage.setPosition(m_button.getPosition());
    tempImage.setScale(250.0f / tempImage.getLocalBounds().width, 250.0f / tempImage.getLocalBounds().height);

    game.draw(tempImage);
    game.draw(tempOutline);
}