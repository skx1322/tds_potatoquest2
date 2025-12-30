#include <iostream>
#include "math.cpp"
#include "header.hpp"
using namespace std;
using namespace mathSystem;

entity::entity(entityStat stat)
{
    this->attributes = stat;
}

string entity::getName() { return this->attributes.entityName; };
int entity::getHealth() { return this->attributes.entityHealth; };
int entity::getDamage() { return this->attributes.entityDamage; };
int entity::getDefense() { return this->attributes.entityDefense; };
int entity::getDice() { return this->attributes.entityDice; };

bool entity::isAlive()
{
    return this->attributes.entityHealth > 0;
};

int entity::receiveDamage(int amount)
{
    int fullDamage = amount - this->getDefense();
    if (fullDamage < 0)
        fullDamage = 0;

    this->attributes.entityHealth -= fullDamage;
    return fullDamage;
};

void entity::rollDice(bool pity)
{
    int newRoll = diceRoll(pity);
    this->attributes.entityDice = newRoll;
};

int entity::gainHP(int amount)
{
    this->attributes.entityHealth += amount;
    return amount;
}

int entity::attackEntity(entity *target)
{
    int attackDamage = damageCalc(this->getHealth(), this->getDice());

    if (attackDamage == 0)
    {
        return attackDamage;
    }
    else
    {
        int damageDealt = target->receiveDamage(attackDamage);
        return attackDamage;
    }
};

class player : public entity
{
private:
    playerStat playerAttribute;

public:
    player(entityStat eStat, playerStat pStat) : entity(eStat)
    {
        this->playerAttribute = pStat;
    }

    int getCoins()
    {
        return this->playerAttribute.coins;
    }

    int checkStage()
    {
        return this->playerAttribute.currentStage;
    }

    string getInventoryIndex(int index)
    {
        if (index < 0 || index >= maxInventory)
        {
            throw logic_error("Invalid Capacity.");
        };

        if (this->playerAttribute.inventory[index].empty())
        {
            return "Empty";
        }
        else
        {
            return this->playerAttribute.inventory[index];
        };
    };

    string getFullInventory()
    {
        string tempString = "";
        for (int i = 0; i < maxInventory; i++)
        {
            tempString += getInventoryIndex(i);
            if (i < maxInventory - 1)
            {
                tempString += ", ";
            }
        }

        return tempString;
    }
};

class enemy : public entity
{
public:
    enemy(entityStat stat) : entity(stat) {};

    void enemyRoll()
    {
        rollDice(false);
    }
    int enemyTurn(entity *target)
    {
        this->enemyRoll();

        return attackEntity(target);
    }
};

namespace enemyList
{
    enemy *createPapadumSoldier()
    {
        entityStat stats = {"Papadum Soldier", 100, 10, 5, 0};
        return new enemy(stats);
    }
}