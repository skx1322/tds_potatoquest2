#include <iostream>
#include "game.cpp"

using namespace std;

int main(){
    gameBoard activeGame; 

    activeGame.startGame();

    activeGame.startTutorial();
    
    return 0;
}