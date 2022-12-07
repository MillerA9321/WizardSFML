#include "wizardBattle.h"
#include "Entity.h"

using namespace std;
using namespace sf;

Entity* slimeHoard(float timeElapsed, vector <Entity&> slimeVector)
{
    KingSlime kingSlime;
    GreenSlime greenSlime;
    RedSlime redSlime;
    YellowSlime yellowSlime;

    if (kingSlime.spawnRate(timeElapsed))
    {
        slimeVector.push_back(kingSlime);
    }

}
