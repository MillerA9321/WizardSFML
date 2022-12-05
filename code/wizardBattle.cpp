//Include libraries here (can get rid of any of these if not used, just got it in here in case)
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Player.h"
#include "wizardBattle.h"

//Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	enum class State { PAUSED, LEVELING_UP, GAME_OVER, PLAYING };

	State state = State::GAME_OVER;

	Vector2f resolution;

	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;
	RenderWindow window(VideoMode(resolution.x, resolution.y), "Wizard Battle", Style::Resize);

	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	Clock clock;

	Time gameTimeTotal;

	Vector2f mouseWorldPosition;

	Vector2i mouseScreenPosition;

	Player player;

	IntRect arena;

	VertexArray background;

	Texture textureBackground;

	textureBackground.loadFromFile("sprites/background_sheet.png");

	while (window.isOpen())
	{
		/*
		Handle Player Input
		*/

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Pause the game while playing
				if (event.key.code == Keyboard::Return && state == State::PLAYING)
				{
					state = State::PAUSED;
				}
				// Restart while paused
				else if (event.key.code == Keyboard::Return && state == State::PAUSED)
				{
					state = State::PLAYING;
					clock.restart();
				}
				// Start a new game if game over
				else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
				}
				// What to do while playing
				if (state == State::PLAYING)
				{

				}
			}
		}

		// Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle Movement
		if (state == State::PLAYING)
		{
			if (Keyboard::isKeyPressed(Keyboard::W))
			{
				player.moveUp();
			}
			else
			{
				player.stopUp();
			}
			if (Keyboard::isKeyPressed(Keyboard::S))
			{
				player.moveDown();
			}
			else
			{
				player.stopDown();
			}
			if (Keyboard::isKeyPressed(Keyboard::A))
			{
				player.moveLeft();
			}
			else
			{
				player.stopLeft();
			}
			if (Keyboard::isKeyPressed(Keyboard::D))
			{
				player.moveRight();
			}
			else
			{
				player.stopRight();
			}
		}
		// Handle Leveling up
		if (state == State::LEVELING_UP)
		{
			// Handle the player LEVELING up
			if (event.key.code == Keyboard::Num1)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num2)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num3)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num4)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num5)
			{
				state = State::PLAYING;
			}
			if (event.key.code == Keyboard::Num6)
			{
				state = State::PLAYING;
			}

			if (state == State::PLAYING)
			{
				// Prepare the level
				arena.width = 500;
				arena.height = 500;
				arena.left = 0;
				arena.top = 0;
				
				int tileSize = createBackground(background,arena);
				// Spawn the player in the middle of the arena
				player.playerSpawn(arena, resolution, tileSize);

				clock.restart();
			}
		}
		// Update the Scene
		if (state == State::PLAYING)
		{
			// Update the delta time
			Time deltaTime = clock.restart();

			// Update the total game time
			gameTimeTotal += deltaTime;

			// Make a decimal fraction of 1 from the delta time
			float dtAsSeconds = deltaTime.asSeconds();
			// Where is the mouse pointer
			mouseScreenPosition = Mouse::getPosition();
			// Convert mouse position to world coordinates of mainView
			mouseWorldPosition = window.mapPixelToCoords(
				Mouse::getPosition(), mainView);
			// Update the player
			player.updatePlayer(dtAsSeconds, Mouse::getPosition());
			// Make a note of the players new position
			Vector2f playerPosition(player.getPlayerCenter());

			// Make the view center around the player                
			mainView.setCenter(player.getPlayerCenter());
		}
		// Draw the scene
		if (state == State::PLAYING)
		{
			window.clear();
			// Draw related to the main view
			window.setView(mainView);
			// Draw the background
			window.draw(background, &textureBackground);
			// Draw the player
			window.draw(player.getPlayerSprite());

		
		}
		if (state == State::LEVELING_UP)
		{
			
		}
		if (state == State::PAUSED)
		{
			
		}
		if (state == State::GAME_OVER)
		{
			
		}
		window.display();
	}

	return 0;
}