#include <iostream>
#include "math.cpp"
#include "header.hpp"
using namespace std;

class entity
{
private:
    entityStat attributes;

public:
    entity(entityStat stat)
    {
        this->attributes = stat;
    }

    string getName() { return this->attributes.entityName; };
    int getHealth() { return this->attributes.entityHealth; };
    int getDamage() { return this->attributes.entityDamage; };
    int getDefense() { return this->attributes.entityDefense; };
    int getDice() { return this->attributes.entityDice; };

    bool isAlive()
    {
        return this->attributes.entityHealth > 0;
    };

    int receiveDamage(int amount)
    {
        int fullDamage = amount - this->getDefense();
        if (fullDamage < 0)
            fullDamage = 0;

        this->attributes.entityHealth -= fullDamage;
        return fullDamage;
    };

    void rollDice(bool pity)
    {
        int newRoll = entitySystem::diceRoll(pity);
        this->attributes.entityDice = newRoll;
    };

    int attackEntity(entity target)
    {
        int attackDamage = entitySystem::damageCalc(this->getHealth(), this->getDice());

        if (attackDamage == 0)
        {
            return attackDamage;
        }
        else
        {
            int damageDealt = target.receiveDamage(attackDamage);
            return attackDamage;
        }
    };
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

    int getCoins(){
        return this->playerAttribute.coins;
    } 

    string getInventoryIndex(int index)
    {
        if (index > this->playerAttribute.inventory->size())
        {
            return "Empty";
        }
        else
        {
            return this->playerAttribute.inventory[index];
        };
    };
};
