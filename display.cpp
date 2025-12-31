#include <iostream>
#include "fs.cpp"
#include "header.hpp"
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
                cout << "Invalid Choice. Please just pick between 1 and 3." << endl;
                continue;
            }
        }

        return input;
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

    void enemyTitle(enemy activeEnemy)
    {
        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << "The " << activeEnemy.getName() << endl;
        cout << "Health: " << activeEnemy.getHealth() << "| Dice: " << activeEnemy.getDice() << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }

    void combatChoice(entityStat playerStat)
    {
        cout << "[---- -----" << playerStat.entityName << " ----- -----]" << endl;
        cout << "[Potato Quest Console]" << endl;
        cout << "['1' to Attack.]" << "['2' to Roll.]" << endl;
        cout << "['3' to Inventory.]" << "['4' to Run.]" << endl;
        cout<< "Your Current Dice: "<< playerStat.entityDice <<endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }

    int combatMenu(entityStat stat)
    {
        int input;

        combatChoice(stat);

        while (true)
        {
            cout << "Your Input: ";
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                combatChoice(stat);
                cout << "Insert Number Between 1 and 4." << endl;
                continue;
            }

            if (input >= 1 && input <= 4)
            {
                break;
            }
            else
            {
                cout << "Invalid Choice. Please just pick between 1 and 4." << endl;
                continue;
            }
        }

        return input;
    };

    void winnerDisplay(entityStat winner, entityStat loser)
    {
        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << winner.entityName << " has won the battle!" << endl;
        cout << "Your Health: " << winner.entityHealth << " | Your Damage: " << winner.entityDamage << endl;
        cout << "Your Defense: " << winner.entityDefense << " | Your Final Dice: " << winner.entityDice << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << loser.entityName << " has been defeated!" << endl;
        cout << "Your Health: " << loser.entityHealth << " | Your Damage: " << loser.entityDamage << endl;
        cout << "Your Defense: " << loser.entityDefense << " | Your Final Dice: " << loser.entityDice << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    } 
    
}