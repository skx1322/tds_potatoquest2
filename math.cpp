#include <iostream>
#include <cmath>
#include "header.hpp"
using namespace std;

namespace mathSystem
{
    int damageCalc(int dmg, int dice)
    {
        if (dice <= 4) // missed
        {
            return 0;
        }
        else if (dice >= 20)
        { // super hit
            return dmg * 2;
        }
        else
        {
            float multiplier = 1.0f + (dice / 100.0f); // float multiplier
            return floor(dmg * multiplier);            // round down
        }
    };

    int diceRoll(bool pity)
    {
        const int randomNum = (rand() % 20) + 1; // rng, 1-20, you don't want to roll less than 4 btw!
        return randomNum;
    }
};
namespace algorithmLib
{
    int binarySearch(string *inv, string target)
    {
        int first = 0;
        int last = inv->length(); // to find array size/length
        while (first <= last)
        {
            int center = first + (last - first) / 2;
            if (inv[center] == target)
            {
                return center;
            }
            else if (inv[center] < target)
            {
                first = center + 1;
            }
            else
            {
                last = center - 1;
            }
        }
        return -1;
    }
}