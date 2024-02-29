#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>


class Resources
{
public:
	Resources();
	void fillTextures();
	sf::Texture *getTexture(int index);
	std::vector<sf::Texture>& getAllTextures();
	sf::Music& getGameMusic();
	void updateGameMusic();
	sf::Music& getMenuMusic();
	void updateMenuMusic();
	void updateFont();
	sf::Font* getFont();
	void fillSoundFX();
	std::vector <sf::SoundBuffer> &getSoundFX();


private:
	std::vector <sf::Texture> m_textures;
	std::vector <sf::SoundBuffer> m_soundFX;
	sf::Music m_gameMusic, m_menuMusic;
	sf::Font m_charFont;
};