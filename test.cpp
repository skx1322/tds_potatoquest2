#include <iostream>
#include <iomanip>
#include <ctime>
#include "display.cpp"

using namespace std;
using namespace gameDisplay;

int main()
{
    srand(time(NULL));

    // int dice = diceRoll(false);
    string test[16] = {"Fu Hua", "Hua", "Senti", "Kiana", "Seele"};
    // int index = displayInventory(test);

    // cout << "Index: " << test[index] << endl;
    cout << setfill('-') << setw(50) << "" << endl;
    cout << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int i = 0; i < 8; i++)
        {
            cout << setfill(' ') << "| " << setw(12) << test[randomizeSequent(0, 4)] << " ";
        }
        cout << endl;
    }
    cout << endl;

    cout << setfill('-') << setw(50) << "" << endl;

    return 0;
}