#include <SFML/Graphics.hpp>
#include "wizardBattle.h"
#include "Player.h"
#include "TextureHolder.h"
#include "Projectile.h"
#include "Entity.h"
#include <vector>
#include <sstream>
#include <iomanip>

//Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	TextureHolder holder;

	Text text;
	Font font;

	font.loadFromFile("font/IMMORTAL.ttf");
	if(!font.loadFromFile("font/IMMORTAL.ttf"))
	{
		cout << "Font file not found" << endl;
	}

	// Create Enum Class for 4 stages
	enum class State { PAUSED, DEAD, GAME_OVER, PLAYING, LEVELING_UP};
	
	// Set class to GAME_OVER
	State state = State::GAME_OVER;

	// Get the screen resolution
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"Wizard Battles", Style::Fullscreen);

	// Create main view 
	View mainView(sf::FloatRect(0, 0, resolution.x, resolution.y));

	
	Clock clock;

	Time gameTimeTotal;

	Vector2f mouseWorldPosition;
	
	Vector2i mouseScreenPosition;

	Player player;

	IntRect arena;

	VertexArray background;
	Texture textureBackground = TextureHolder::getTexture("sprites/newBackground.png");

	// "Mana amount" 
	Projectile projectiles[100];
	int currentProjectileCount = 0;
	int spareProjectileCount = 16;
	int projectileClip = 50;
	int clipSize = 50;
	float fireRate = 1;

	//Spell last cast
	Time lastPressed;

	//Create Slime Pointer
	Entity* slimes = nullptr;

	// The main game loop
	while (window.isOpen())
	{
		// Create event
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::KeyPressed)
			{
				// Pause the game while playing
				if (event.key.code == Keyboard::Return &&
					state == State::PLAYING)
				{
					state = State::PAUSED;
				}

				// Restart while paused
				else if (event.key.code == Keyboard::Return && state == State::PAUSED)
				{
					state = State::PLAYING;
					clock.restart();
				}

				else if (event.key.code == Keyboard::Return && state == State::GAME_OVER)
				{
					state = State::LEVELING_UP;
				}

				//What to do while playingS
				if (state == State::PLAYING)
				{
					if (event.key.code == Keyboard::R)
					{
						if (spareProjectileCount >= clipSize)
						{
							// Plenty of bullets. Reload.
							projectileClip = clipSize;
							spareProjectileCount -= clipSize;
						}
						else if (spareProjectileCount > 0)
						{
							// Only few bullets left
							projectileClip = spareProjectileCount;
							spareProjectileCount = 0;
						}
						else
						{

						}
				}

			}
		}
	}



		 // Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}

		// Handle controls while playing
		if (state == State::PLAYING)
		{
			// Handle Player Input
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
		//Fire Projectile
		if (Mouse::isButtonPressed(sf::Mouse::Left))
			{
				if (gameTimeTotal.asMilliseconds() - lastPressed.asMilliseconds() > 1000 / fireRate && projectileClip > 0)
				{
					// Pass the centre of the player 
					// and the centre of the cross-hair
					// to the shoot function
					projectiles[currentProjectileCount].shoot(
						player.getPlayerCenter().x, player.getPlayerCenter().y,
						mouseWorldPosition.x, mouseWorldPosition.y);
					currentProjectileCount++;
					if (currentProjectileCount > 99)
					{
						currentProjectileCount = 0;
					}
					lastPressed = gameTimeTotal;
					projectileClip--;
				}
			}

		 // Handle the levelling up state
		if (state == State::LEVELING_UP)
		{
			// Handle the player levelling up
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
			arena.width = 2000;
			arena.height = 2000;
			arena.left = 0;
			arena.top = 0;

			int tileSize = createBackground(background, arena);
			player.spawnPlayer(arena, resolution, tileSize);
			slimes = slimeHoard(gameTimeTotal.asSeconds(), arena);
			clock.restart();
			}
		}
		//Update the Scene
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

			//Loops through each sliime
			for (int i = 0; i < 50; i++)
			{
				if (slimes[i].isAlive())
				{
					slimes[i].updatePosition(dtAsSeconds, playerPosition);
				}
			}
			// Update projectiles
			for (int i = 0; i < 100; i++)
			{
				if (projectiles[i].isInFlight())
				{
					projectiles[i].update(dtAsSeconds);
				}
			}
		}
		
		// Draw the scene

		if (state == State::PLAYING)
		{
			window.clear();
			// Draw related to the main view
			window.setView(mainView);
			// Draw the background
			window.draw(background, &textureBackground);
			// Draw projectiles
			for (int i = 0; i < 100; i++)
			{
				if (projectiles[i].isInFlight())
				{
					window.draw(projectiles[i].getShape());
				}
			}
			// Draw the player
			window.draw(player.getPlayerSprite());

			//Draw the slimes
			for (int i = 0; i < 50; i++)
			{
				window.draw(slimes[i].getSprite());
			}
		}

		//If a projetile hits a slime
		if (state == State::PLAYING)
		{
			for (int i = 0; i < 50; i++)
			{
				if (player.getPlayerPosition().intersects(slimes[i].getPosition()))
				{
					state = State::DEAD;
				}
			}

		}

		if (state == State::PLAYING)
		{
			text.setFont(font);
			text.setFillColor(Color::Black);
			text.setCharacterSize(32);
			text.setPosition(player.getPlayerCoordinates().x - 140, player.getPlayerCoordinates().y - 120);

			stringstream display;

			display << "Time Survived: " << fixed << setprecision(2) << gameTimeTotal.asSeconds() << endl;
			text.setString(display.str());

			window.draw(text);
		}

		//Title Screen
		if (state == State::GAME_OVER)
		{
			text.setFont(font);
			text.setFillColor(Color::Blue);
			text.setCharacterSize(64);
			text.setPosition(400, 400);

			stringstream display;

			display << "			Wizards" << endl << "	Press Enter + 1 To Play" << endl;
			text.setString(display.str());

			window.draw(text);
		}

		if(state == State::DEAD)
		{
			text.setFont(font);
			text.setFillColor(Color::Red);
			text.setCharacterSize(64);

			text.setPosition(player.getPlayerCoordinates().x - 300 , player.getPlayerCoordinates().y - 300 );

			stringstream display;

			display << "	You Died!!!!" << endl << "Better Luck Next Time" << endl;
			text.setString(display.str());

			window.draw(text);
		}
		
		window.display();

	}
	// End game loop

	return 0;
}