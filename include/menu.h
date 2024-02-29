#pragma once
#include <iostream>
#include "resources.h"
#include "button.h"
#include <SFML/Graphics.hpp>
#include "controller.h"
#include "scoreboard.h"

class Menu
{
public:
	Menu();
	
	void runMenu();
	void updateButtons();
	void drawButtons();
	void hoverButton(sf::Vector2i position);
	void handleClick(const sf::Event::MouseButtonEvent& event);
	void runGame();
	void checkDirection(sf::Time deltaTime);
	void playGameMusic();
	void playMenuMusic();
	void winWindow(sf::RenderWindow& prevWindow);
	void loseWindow(sf::RenderWindow& prevWindow);
private:
	sf::RenderWindow m_window;
	Resources m_resources;
	Button m_buttons[3];
	Controller m_controller;
	Scoreboard m_scoreBoard;

};
