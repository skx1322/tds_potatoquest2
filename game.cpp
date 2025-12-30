#include <iostream>
#include "display.cpp"
using namespace std;
using namespace gameDisplay;
using namespace dataStrucutre;
using namespace enemyList;

void runCombat(player* activePlayer, enemy* activeEnemy){
    combatQueue turnQueue;
    
    turnQueue.enqueue(activePlayer);
    turnQueue.enqueue(activeEnemy);

    while (activePlayer->isAlive() && activeEnemy->isAlive())
    {
        entity* current = turnQueue.dequeue();
        if (current == nullptr)
        {
            break;
        }
        if (current == activePlayer)
        {
            cout<<activePlayer->getName()<<" Turns!"<<endl;
            
            // placeholder, auto attack for now
            activePlayer->attackEntity(activeEnemy);
        } else {
            cout<<activeEnemy->getName()<<" Turns!"<<endl;
            activeEnemy->enemyRoll();

            activeEnemy->enemyTurn(activePlayer);
        }
        
        if (current->isAlive())
        {
            turnQueue.enqueue(current);
        }
    }
       
}

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

    void startTutorial(){
        enemy* tutorialEnemy = createPapadumSoldier();

        runCombat(currentPlayer, tutorialEnemy);
    }
};
