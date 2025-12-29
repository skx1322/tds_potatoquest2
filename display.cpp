#include <iostream>
using namespace std;

namespace gameDisplay
{
    void titleOutput()
    {
        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << "[Potato Quest II]" << endl;
        cout << "['1' to Start New Game.]" << endl;
        cout << "['2' to Load Previous Game.]" << endl;
        cout << "['3' to Quit Game.]" << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }

    int startMenu()
    {
        int input;
        int confirm;

        titleOutput();

        while (true)
        {
            cout << "Your Input: ";
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                titleOutput();
                cout << "Insert Number Between 1 and 3." << endl;
                continue;
            }

            if (input >= 1 && input <= 3)
            {
                break;
            }
            else
            {
                cout << "Out of Range Input." << endl;
                continue;
            }
        }
    };

    string createUsername()
    {
        string nameTemp;

        cout << "What is your name..." << endl;
        do
        {
            cout << "I'm... ";
            getline(cin, nameTemp);
        } while (nameTemp.empty());
        cin.clear();

        return nameTemp;
    }

    void enemyTitle(string name)
    {
        cout << "The " << name << endl;
    }

    void combatChoice(int dice)
    {
        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << "[Potato Quest Console]" << endl;
        cout << "['1' to Attack.]" << endl;
        cout << "['2' to Roll.]" << endl;
        cout << "['3' to Inventory.]" << endl;
        cout << "['4' to Run.]" << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }
}