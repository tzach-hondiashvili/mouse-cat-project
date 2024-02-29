#Mouse and Cat Game - Daniel Dalal & Tzach Hondiashvili

Mouse Maze Game is a simple maze game where the player controls a mouse trying to navigate through a maze while avoiding cats and collecting cheese.
The game is implemented using C++ and SFML (Simple and Fast Multimedia Library) for graphics rendering.

## Overview

In Mouse Maze Game, the player controls a mouse character navigating through various mazes filled with obstacles, challenges, and rewards.
The objective is to collect cheese scattered throughout the maze while avoiding cats that roam the area.
The game features multiple levels with increasing difficulty, each with unique maze layouts and obstacles.
Players must use strategy and quick reflexes to navigate through the maze, collect cheese, and reach the exit without being caught by the cats.
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              
## Features

- **Player Control**: Navigate the mouse character using keyboard arrows.
- **Collision Detection**: Handle interactions between mouse, obstacles, and other objects.
- **Game Objects**: Walls, cheese, cats, keys, doors, medkits, freeze power-ups, gift, time add, and portals.
- **Scoring System**: Track score based on collected cheese and other objects.
- **Sound Effects and Music**: Integrated sounds and background music for immersive gameplay.
- **User Interface**: Buttons for starting and quitting the game, as well as help.

## Installation

1. Install SFML library if not already installed. Follow the the PDF (SFMLInstallation) file included in the main folder.

2. Build the project using CMake:

   Follow the the PDF file included in the main folder.

3. Run the game using the IDE

## Game Objects

- **Mouse**: Player-controlled character navigating the maze.
- **Cheese**: Collectible items that increase the player's score.
- **Cats**: Enemies that follow the mouse and decrease the player's health if caught.
- **Keys**: Used to unlock doors and access new areas.
- **Doors**: Blockades that require keys to open.
- **Medkits**: Provide extra lives to the player.
- **Freeze Power-ups**: Temporarily stop cats from moving for 5 seconds.
- **Water Gun**: Removing a cat from the level.
- **Portals**: Teleport the mouse character to different locations in the maze.
- **+10 clock**: Adds 10 seconds to the level timer.

## Files

### Headers

- **button.h**: Defines the `Button` class for creating UI buttons in the game.
- **cat.h**: Contains the `Cat` class declaration representing the cat enemy in the game.
- **cheese.h**: Defines the `Cheese` class for representing cheese objects that players collect.
- **controller.h**: Declares the `Controller` class responsible for controlling game logic and managing game objects.
- **door.h**: Contains the `Door` class declaration representing door objects that players can unlock with keys.
- **freeze.h**: Defines the `Freeze` class representing freeze power-ups in the game.
- **gameObjects.h**: Contains the `GameObjects` class declaration, which is a base class for all game objects.
- **gift.h**: Defines the `Gift` class representing gift objects that provide various benefits or penalties.
- **key.h**: Contains the `Key` class declaration representing key objects that players collect to unlock doors.
- **medkit.h**: Declares the `Medkit` class representing medkit objects that provide extra lives to the player.
- **menu.h**: Defines the `Menu` class representing the main menu of the game.
- **movingObjects.h**: Contains the `MovingObjects` class declaration, which is a base class for moving game objects.
- **portal.h**: Declares the `Portal` class representing portal objects that teleport the player to another location.
- **staticObjects.h**: Defines the `StaticObjects` class representing static game objects in the game.
- **tile.h**: Contains the `Tile` class declaration representing tiles in the game's maze.
- **wall.h**: Declares the `Wall` class representing wall objects that block the player's path.

### Source Files (CPP)

- **button.cpp**: Implements the methods of the `Button` class for UI buttons.
- **cat.cpp**: Defines the behavior of the `Cat` class representing cat enemies.
- **cheese.cpp**: Implements the methods of the `Cheese` class representing cheese objects.
- **controller.cpp**: Implements the game logic and methods of the `Controller` class.
- **door.cpp**: Defines the behavior of the `Door` class representing door objects.
- **freeze.cpp**: Implements the methods of the `Freeze` class representing freeze power-ups.
- **gameObjects.cpp**: Implements methods of the `GameObjects` base class for game objects.
- **gift.cpp**: Defines the behavior of the `Gift` class representing gift objects.
- **key.cpp**: Implements the methods of the `Key` class representing key objects.
- **medkit.cpp**: Defines the behavior of the `Medkit` class representing medkit objects.
- **menu.cpp**: Implements the methods of the `Menu` class for the game's main menu.
- **portal.cpp**: Defines the behavior of the `Portal` class representing portal objects.
- **staticObjects.cpp**: Implements methods of the `StaticObjects` class for static game objects.
- **tile.cpp**: Defines the behavior of the `Tile` class representing tiles in the maze.
- **wall.cpp**: Implements the methods of the `Wall` class representing wall objects.

### Adding a new level
to add a new level add a file named board[the level number].txt, and update in menu cpp the winning condition
to the amount of levels currently.

MAKE SURE when adding a new level that its size is EXACTLY 15x23.

dictionary for making a new level:

% - mouse.
^ - cat.
$ - water gun(kills a cat).
p - portal (make sure to use exactly 2 per level).
3 - medkit (increase lives by 1).
# - wall.
* - cheese.
+ - increase the level timer by 10 seconds.
F - key (used to open doors).
D - door.
z - freeze (stops the cats in place for 5 seconds).

## Credits

- Game developed by Daniel Dalal & Tzach Hondiashvili.
- Sound effects and music obtained from Youtube, Pixabay.
- Special thanks to our lecturers Michal Merkin & Yehezkel Bernat for their assistance and feedback.
- Inspired by Mouse Maze and puzzle games.

## License

This project is licensed under the Hadassah Academic College students:
Daniel Dalal & Tzach Hondiashvili.
