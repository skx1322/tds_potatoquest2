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
};

namespace algorithmLib
{
    int binarySearch(string* inv, string target)
    {
        int first = 0;
        int last = inv->size(); // to find array size/length
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