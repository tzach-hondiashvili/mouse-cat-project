#pragma once
#include "gameObjects.h"

class Controller;

class StaticObjects :public GameObjects
{
public:
	StaticObjects();
	StaticObjects(sf::Texture* newTexture, sf::Vector2f newLocation, sf::Vector2f newSize, std::string newType,Controller *controller);
	Controller* getController();

private:
	Controller* m_controller;
};