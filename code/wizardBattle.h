#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Entity.h"

using namespace sf;
using namespace std;

int createBackground(VertexArray& rVA, IntRect arena);
Entity* slimeHoard(float timeElapsed, IntRect arena);
