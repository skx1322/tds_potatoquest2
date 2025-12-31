#include <iostream>
#include "display.cpp"
using namespace std;
using namespace gameDisplay;
using namespace enemyList;

class combatQueue
{
private:
    Node *front;
    Node *back;

public:
    combatQueue()
    {
        front = nullptr;
        back = nullptr;
    };

    void enqueue(entity *ent)
    {
        Node *newNode = new Node(ent);
        if (back == nullptr)
        {
            front = back = newNode;
            return;
        }

        back->next = newNode;
        back = newNode;
    };

    entity *dequeue()
    {
        if (front == nullptr)
        {
            return nullptr;
        }

        Node *temp = front;
        entity *ent = temp->data;
        front = front->next;

        if (front == nullptr)
        {
            back = nullptr;
        }
        delete temp;
        return ent;
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    ~combatQueue()
    {
        while (!isEmpty())
        {
            dequeue();
        }
    }
};

void runCombat(player *activePlayer, enemy *activeEnemy)
{
    combatQueue turnQueue;

    int playerTemp = activePlayer->getHealth();

    turnQueue.enqueue(activePlayer);
    turnQueue.enqueue(activeEnemy);

    while (activePlayer->isAlive() && activeEnemy->isAlive())
    {
        entity *current = turnQueue.dequeue();
        if (current == nullptr)
        {
            break;
        }
        if (current == activePlayer)
        {
            cout << activePlayer->getName() << " Turns!" << endl;
            activePlayer->rollDice(false);

            // placeholder, auto attack for now
            activePlayer->attackEntity(activeEnemy);
        }
        else
        {
            cout << activeEnemy->getName() << " Turns!" << endl;
            activeEnemy->enemyRoll();

            activeEnemy->enemyTurn(activePlayer);
        }

        if (current->isAlive())
        {
            turnQueue.enqueue(current);
        }
    }
    if (!activeEnemy->isAlive())
    {
        // scenario if player win
        winnerDisplay(activePlayer->getFullAttributes(), activeEnemy->getFullAttributes());

        activePlayer->setHP(playerTemp);

        cout<<"Restored Player HP back to "<<activePlayer->getHealth()<<endl;
    } else {
        // scenario if enemy win
        winnerDisplay(activeEnemy->getFullAttributes(), activePlayer->getFullAttributes());
    }
}

class gameBoard
{
private:
    player *currentPlayer;
    int currentStage;
    bool activeGame;

public:
    gameBoard() : currentPlayer(), currentStage(1), activeGame(true) {}

    player getPlayerProfile() { return *currentPlayer; };

    bool isRunning() { return activeGame; };

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
            activeGame = false;
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

    void startTutorial()
    {
        enemy *tutorialEnemy = createPapadumSoldier();

        runCombat(currentPlayer, tutorialEnemy);
    }

    void endGame()
    {
        player progress = *currentPlayer;

        saveProgress(progress);
        this->activeGame = false;
    }
};
