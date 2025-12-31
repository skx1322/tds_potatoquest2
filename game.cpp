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
    if (activeEnemy->isAlive())
    {
        cout<<activeEnemy->getName()<<" has been defeated!"<<endl;
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

    void startTutorial()
    {
        enemy *tutorialEnemy = createPapadumSoldier();

        runCombat(currentPlayer, tutorialEnemy);
    }
};
