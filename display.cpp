#include <iostream>
#include "fs.cpp"
#include "system.cpp"
#include "header.hpp"
using namespace std;
using namespace systemConsole;

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
            cout << "\nYour Input: ";
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

        system("cls");
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

    void tutorialStage()
    {
        int confirm;
        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << "This is the tutorial stage." << endl;
        cout << "You'll be up against this enemy." << endl;
        cout << "1. Press '1' to attack. Keep in mind, if your current dice is below 4, you won't be able to deal damage." << endl;
        cout << "2. Since your dice is under 4, we recommend rolling for a better chance next time." << endl;
        cout << "3. Inventory, you can check it to use items for your advantage though it take one turn to use." << endl;
        cout << "4. Do not run (placeholder)." << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;

        cout << "Proceed? ";
        cin >> confirm;
    }

    void enemyTitle(enemy *enemyTarget)
    {
        enemy activeEnemy = *enemyTarget;

        cout << "[---- ----- ----- ----- -----]" << endl;
        cout << "The " << activeEnemy.getName() << endl;
        cout << "Health: " << activeEnemy.getHealth() << "| Dice: " << activeEnemy.getDice() << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }

    void combatChoice(entityStat playerStat, entityStat enemyStat)
    {
        cout << "[---- -----" << playerStat.entityName << " ----- -----]" << endl;
        cout << "[ Your Health: "<< playerStat.entityHealth << " vs Enemy Health: " << enemyStat.entityHealth <<" ]" << endl;
        cout << "['1' to Attack.]" << "['2' to Roll.]" << endl;
        cout << "['3' to Inventory.]" << "['4' to Run.]" << endl;
        cout << "Your Current Dice: " << playerStat.entityDice << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }

    int combatMenu(entityStat stat, entityStat enemy)
    {
        int input;

        combatChoice(stat, enemy);

        while (true)
        {
            cout << "\nYour Input: ";
            cin >> input;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                // combatChoice(stat);
                cout << "Insert Action Between 1 and 4." << endl;
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
        clearConsole();

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
        cout << "Their Health: " << loser.entityHealth << " | Their Damage: " << loser.entityDamage << endl;
        cout << "Their Defense: " << loser.entityDefense << " | Their Final Dice: " << loser.entityDice << endl;
        cout << "[---- ----- ----- ----- -----]" << endl;
    }

}