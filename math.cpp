#include <iostream>
#include <cmath>
using namespace std;

namespace entitySystem
{
    int damageCalc(int dmg, int dice)
    {
        if (4 > dice)
        {
            return 0;
        }
        else
        {
            return floor(dmg * ((dice / 100) + 1));
        }
    };

    int diceRoll(bool pity)
    {
        const int randomNum = (rand() % 20) + 1;
        return randomNum;
    }
}