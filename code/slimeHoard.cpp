#include "wizardBattle.h"
#include "Entity.h"

using namespace std;
using namespace sf;

Entity* slimeHoard(float timeElapsed, IntRect arena)
{
    Entity* slimes = new Entity[200];

    KingSlime kingSlime;
    GreenSlime greenSlime;
    RedSlime redSlime;
    YellowSlime yellowSlime;

    int maxY = arena.height - 5;
    int minY = arena.top + 5;
    int maxX = arena.width - 5;
    int minX = arena.left + 5;

    string slimeType;


    int i = 0;

    if (kingSlime.spawnRate(timeElapsed))
    {
        slimeType = "King";
        slimes[i].slimeSpawn(maxX, minY, slimeType);
        i++;
    }

    if (greenSlime.spawnRate(timeElapsed))
    {
        slimeType = "Green";
        slimes[i].slimeSpawn(minX, minY, slimeType);
        cout << "Testing" << endl;
        i++;
    }

    if (redSlime.spawnRate(timeElapsed))
    {
        slimeType = "Red";
        slimes[i].slimeSpawn(minX, maxY, slimeType);
        i++;
    }

    if (yellowSlime.spawnRate(timeElapsed))
    {
        slimeType = "Yellow";
        slimes[i].slimeSpawn(maxX, maxY, slimeType);
        i++;
    }                                                                            

    return slimes;
}
