//Include libraries here (can get rid of any of these if not used, just got it in here in case)
#include <SFML/Graphics.hpp>
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

//Make code easier to type with "using namespace"
using namespace sf;
using namespace std;

int main()
{
	//Get the screen resolution and create an SFML window
	Vector2f resolution;
	resolution.x = VideoMode::getDesktopMode().width;
	resolution.y = VideoMode::getDesktopMode().height;

	RenderWindow window(VideoMode(resolution.x, resolution.y),
		"WIP Wizard", Style::Default);


	//Create the view (so map can move a bit)
	View mainView(FloatRect(0, 0, 1920, 1080));

	//Setup clock for future use
	Clock clock;

	//Setup total game time for future use
	Time gameTimeTotal;

	//The main loop
	while (window.isOpen())
	{
		//Handle the player quitting
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}


		//Draw Scene
		window.clear();

		window.display();
	}
	return 0;
}
//In class last wednesday my original plan was to have like each entity do an action and draw itself in their own class
//but the professor suggested that the actual drawing be done in a new class called Engine Class and I have been stuck on this

//Alright I'll look into it here soon, been caught up dealing with some stuff
//Check his chapter 13 folder for the zombie game if you want a useable reference of what we're aiming for
//Granted a lot of that we're gonna have to crunch down to fit requirements I think