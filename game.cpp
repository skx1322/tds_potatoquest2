#include <iostream>
#include "fs.cpp"
#include "display.cpp"
using namespace std;
using namespace gameDisplay;

class gameBoard
{
private:
    player *currentPlayer;
    int currentStage;
    bool isRunning;

public:
    gameBoard() : currentPlayer(), currentStage(1), isRunning(true) {}

    void startGame()
    {
        int input = startMenu();
        cout << "Your choice: " << input << endl;

        switch (input)
        {
        case 1:
            newGame();
            break;
        case 2:
            loadGame();
            break;
        case 3:
            isRunning = false;
            break;
        }
    }

    void newGame()
    {
        string name = createUsername();

        entityStat entityDefault = {name, 100, 10, 5, 0};
        playerStat playerDefault = {{}, 0, 1};
        currentPlayer = new player(entityDefault, playerDefault);
    }

    void loadGame()
    {
        currentPlayer = loadSave();
        currentStage = currentPlayer->checkStage();
        if (currentPlayer == nullptr)
        {
            cout << "No save found, starting from scratch." << endl;
            newGame();
        };
    }
};

class combatBoard
{
private:
    player *activePlayer;
    enemy *activeEnemy;
    int rounds;
    bool combatActive;

public:
    combatBoard(player *h, enemy *e)
    {
        activePlayer = h;
        activeEnemy = e;
        rounds = 1;
        combatActive = true;
    }

    void initialFight(){
        enemyTitle(activeEnemy->getName());
        
        while (activePlayer->isAlive() && activeEnemy->isAlive()){
            
        }
    }
};