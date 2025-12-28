#include <iostream>
#include "entity.cpp"
using namespace std;

class enemy : public entity
{
public:
    void enemyRoll()
    {
        rollDice(false);
    }
    int enemyTurn(entity target)
    {
        this->enemyRoll();

        return attackEntity(target);
    }
};