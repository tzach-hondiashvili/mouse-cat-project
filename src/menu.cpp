#include "menu.h"
#include <iostream>
Menu::Menu()
    :m_window(sf::VideoMode(1456, 816), "Mouse&Cat"),
    m_resources(Resources()), m_controller(Controller()),m_scoreBoard(Scoreboard())
{
    for (int i=0; i < 2; i++)
    {
        m_buttons[i] = Button();
    }
}

void Menu::runGame()
{
    sf::Clock clockDelta, clockTimer;
    sf::Sprite frameSprite(*m_resources.getTexture(11));
    frameSprite.setScale((1456) / frameSprite.getLocalBounds().width, (816) / frameSprite.getLocalBounds().height);
    m_controller.updateBoard(m_resources.getAllTextures());
    m_controller.updatePortal();
    playGameMusic();

    while (m_window.isOpen())
    {
        const auto deltaTime = clockDelta.restart();

        for (auto event = sf::Event{}; m_window.pollEvent(event);)
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                m_window.close();
                break;
            }
        }
        //update block
        m_scoreBoard.updateLives(m_controller.getMouse().getLives(),m_resources.getFont());
        m_scoreBoard.updateCheeses(m_controller.getCheeseCount(),m_resources.getFont(),m_controller.getMouse().getEatenCheeses());
        m_scoreBoard.updateScore(m_controller.getMouse().getScore(), m_resources.getFont());
        m_scoreBoard.updateKeys(m_controller.getMouse().getKeys(), m_resources.getFont());
        m_scoreBoard.updateLevel(m_controller.getLevel(), m_resources.getFont());
        m_scoreBoard.updateTime(clockTimer, m_resources.getFont(),m_controller.getAddedTime());
        checkDirection(deltaTime);
       

        //collisions block
        m_controller.handleCollision(m_resources.getSoundFX());
        m_controller.addTime(deltaTime);

        if (m_controller.getFreezeTime() >= sf::seconds(5))
        {
            m_controller.moveCats(m_controller.getStatics(), m_controller.getBoardForController().getBoard(), deltaTime);
        }
        m_controller.getMouse().collisionWithCats(m_controller.getCats(), m_resources.getSoundFX()[7]);

        //print block
        m_window.clear();
        m_window.draw(frameSprite);
        m_controller.getBoardForController().draw(m_window);
        m_controller.drawStatics(m_window);
        m_controller.getMouse().drawMouse(m_window);
        m_controller.drawCats(m_window);
        m_window.draw(m_scoreBoard.getLives());
        m_window.draw(m_scoreBoard.getCheeses());
        m_window.draw(m_scoreBoard.getScore());
        m_window.draw(m_scoreBoard.getKeys());
        m_window.draw(m_scoreBoard.getLevel());
        m_window.draw(m_scoreBoard.getTime());
        m_window.display();

        if (m_controller.getBoardForController().getCheeseCount() - m_controller.getMouse().getEatenCheeses() == 0)
        {
            m_controller.getMouse().updateScore(200);

            if (m_controller.getLevel() == 3)
            {
                m_resources.getGameMusic().stop();
                winWindow(m_window);
            }
            m_controller.UpdateLevel(1);
            m_controller.clearBoard();
            m_controller.getBoardForController().resetCheeseCount();
            m_controller.updateBoard(m_resources.getAllTextures());
            m_controller.updatePortal();
            m_controller.getMouse().resetEatenCheese();
            clockTimer.restart();
            m_controller.resetAddedTime();
        }

        if (clockTimer.getElapsedTime().asSeconds() >= 120 + m_controller.getAddedTime())
        {
            m_controller.clearBoard();
            m_controller.getBoardForController().resetCheeseCount();
            m_controller.updateBoard(m_resources.getAllTextures());
            m_controller.updatePortal();
            m_controller.getMouse().updateLives(-1);
            m_controller.resetKeys();
            m_controller.getMouse().resetEatenCheese();
            clockTimer.restart();
            m_controller.resetAddedTime();
        }

        if (m_controller.getMouse().getLives() == 0)
        {
            m_resources.getGameMusic().stop();
            loseWindow(m_window);
        }

    }
}

void Menu::runMenu()
{
	m_resources.fillTextures();
    m_resources.fillSoundFX();
    m_resources.updateGameMusic();
    m_resources.updateFont();
	m_window.setFramerateLimit(60);
    m_resources.updateMenuMusic();
    playMenuMusic();

    updateButtons();

	sf::Sprite backgroundSprite(*m_resources.getTexture(0));

	    
        while (m_window.isOpen()) 
        {
            for (auto event = sf::Event{}; m_window.pollEvent(event);)
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    m_window.close();
                    break;
                case sf::Event::MouseButtonReleased:
                    handleClick(event.mouseButton);
                    break;
                }
            }
            sf::Vector2i mousePosition = sf::Mouse::getPosition(m_window);
            
            m_window.clear();
            m_window.draw(backgroundSprite);
            drawButtons();
            hoverButton(mousePosition);
            m_window.display();
        }

}

void Menu::updateButtons()
{
    //1456x816
    sf::Vector2f temp;
    
    for (int i = 0; i < 2; i++)
    {
        temp.x = 580;
        temp.y = 300+250*(float)i;
        m_buttons[i].setSize({250,250});
        m_buttons[i].updateButtonLocation(temp);
        m_buttons[i].updateTexture(m_resources.getTexture(i+1));
    }
    temp.x = 1200;
    temp.y = 550;
    m_buttons[2].setSize({ 250,250 });
    m_buttons[2].updateButtonLocation(temp);
    m_buttons[2].updateTexture(m_resources.getTexture(16));

}

void Menu::drawButtons()
{
    for (int i = 0; i < 3; i++)
    {
        m_buttons[i].draw(m_window);
    }
}

void Menu::hoverButton(sf::Vector2i position)
{
    for (int i = 0; i < 3; i++)
    {
        if (m_buttons[i].getShape().getGlobalBounds().contains(
            m_window.mapPixelToCoords({ position.x, position.y })))
        {
            m_buttons[i].drawButtonOutline(m_window);
        }
    }
}

void Menu::handleClick(const sf::Event::MouseButtonEvent& event)
{
    if (m_buttons[1].getShape().getGlobalBounds().contains(m_window.mapPixelToCoords({event.x, event.y})))//quit
    {
        m_window.close();
        exit(EXIT_SUCCESS);
    }
    if (m_buttons[0].getShape().getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y })))//run game
    {
        m_resources.getMenuMusic().stop();
        runGame(); 
    }
    if (m_buttons[2].getShape().getGlobalBounds().contains(m_window.mapPixelToCoords({ event.x, event.y })))//help
    {
        sf::RenderWindow helpScreen(sf::VideoMode(396,561 ),"help screen");

        while (helpScreen.isOpen())
        {
            for (auto event1 = sf::Event{}; helpScreen.pollEvent(event1);)
            {
                switch (event1.type)
                {
                case sf::Event::Closed:
                    helpScreen.close();
                    break;
                }
            }
            sf::Sprite temp;
            temp.setTexture(*m_resources.getTexture(17));
            temp.setScale(sf::Vector2f(396.f / 1587, 561.f / 2245));
            helpScreen.clear();
            helpScreen.draw(temp);
            helpScreen.display();
        }

    }
}

void Menu::checkDirection(sf::Time deltaTime)
{
   auto temp = sf::Vector2f(m_controller.getMouse().getSize().x / m_controller.getMouse().getSprite().getLocalBounds().width, m_controller.getMouse().getSize().y / m_controller.getMouse().getSprite().getLocalBounds().height);
   m_controller.getMouse().getSprite().setOrigin(m_controller.getMouse().getSprite().getLocalBounds().width / 2.f, m_controller.getMouse().getSprite().getLocalBounds().height / 2.f);
   sf::Vector2f tempDirection = sf::Vector2f(0,0);
   double moves = 1;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) 
    {

        m_controller.getMouse().getSprite().setScale(-1.f * temp.x, 1.f * temp.y);
        tempDirection += sf::Vector2f(-1, 0);
        moves += 0.4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) 
    {
        m_controller.getMouse().getSprite().setScale(temp);
        tempDirection += sf::Vector2f(1, 0);
        moves += 0.4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
    {
        m_controller.getMouse().setDirection(sf::Vector2f(0, -1));
        tempDirection += sf::Vector2f(0, -1);
        moves += 0.4;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) 
    {
        m_controller.getMouse().setDirection(sf::Vector2f(0, 1));
        tempDirection += sf::Vector2f(0, 1);
        moves += 0.4;
    }

    if (moves != 1)
    {
        moves-= 0.4;
    }

    tempDirection.x /= (float)moves;
    tempDirection.y /= (float)moves;
    m_controller.getMouse().setDirection(tempDirection);
    m_controller.getMouse().moveMouse(deltaTime, m_controller.getBoardForController().getBoard());
    
}

void Menu::playGameMusic()
{
    m_resources.getMenuMusic().stop();
    m_resources.getGameMusic().play();
    m_resources.getGameMusic().setLoop(true);
}

void Menu::playMenuMusic()
{
    m_resources.getMenuMusic().play();
    m_resources.getMenuMusic().setLoop(true);
}

void Menu::winWindow(sf::RenderWindow& prevWindow)
{
    prevWindow.close();

    sf::RenderWindow winScreen(sf::VideoMode(1456, 816), "win screen");

    sf::Sprite temp;
    sf::Sound winSound;

    winSound.setBuffer(m_resources.getSoundFX()[10]);
    winSound.play();

    temp.setTexture(*m_resources.getTexture(19));
    temp.setScale(sf::Vector2f(1456.f / 535, 816.f / 298));

    while (winScreen.isOpen())
    {
        for (auto event1 = sf::Event{}; winScreen.pollEvent(event1);)
        {
            switch (event1.type)
            {
            case sf::Event::Closed:
                winScreen.close();
                break;
            }
        }
        winScreen.clear();
        winScreen.draw(temp);
        winScreen.display();
    }

}

void Menu::loseWindow(sf::RenderWindow& prevWindow)
{
    prevWindow.close();

    sf::RenderWindow loseScreen(sf::VideoMode(1456, 816), "lose screen");

    sf::Sprite temp;
    sf::Sound loseSound;

    loseSound.setBuffer(m_resources.getSoundFX()[11]);
    loseSound.play();

    temp.setTexture(*m_resources.getTexture(20));
    temp.setScale(sf::Vector2f(1456.f / 533, 816.f / 299));

    while (loseScreen.isOpen())
    {
        for (auto event1 = sf::Event{}; loseScreen.pollEvent(event1);)
        {
            switch (event1.type)
            {
            case sf::Event::Closed:
                loseScreen.close();
                break;
            }
        }
        loseScreen.clear();
        loseScreen.draw(temp);
        loseScreen.display();
    }

}

