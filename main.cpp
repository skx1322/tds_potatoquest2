#include <iostream>
#include "game.cpp"

using namespace std;

int main()
{
    gameBoard activeGame;

    while (activeGame.isRunning())
    {
        activeGame.startGame();

        activeGame.startTutorial();

        activeGame.endGame();
    }
    return 0;
}