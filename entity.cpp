#include <iostream>
#include "math.cpp"
#include "header.hpp"
using namespace std;
using namespace mathSystem;
using namespace algorithmLib;

// entity class here
entity::entity(entityStat stat)
{
    this->attributes = stat;
}

entityStat entity::getFullAttributes() { return this->attributes; };
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

void entity::resetDice()
{
    this->attributes.entityDice = 0;
}

void entity::setHP(int amount)
{
    this->attributes.entityHealth = amount;
}

int entity::gainHP(int amount)
{
    this->attributes.entityHealth += amount;
    return amount;
}

int entity::attackEntity(entity *target)
{
    int attackDamage = damageCalc(this->getDamage(), this->getDice());

    resetDice();

    if (attackDamage == 0)
    {
        return attackDamage;
    }
    else
    {
        int damageDealt = target->receiveDamage(attackDamage);
        return damageDealt;
    }
};

// player class here
player::player(entityStat eStat, playerStat pStat) : entity(eStat)
{
    this->playerAttribute = pStat;
}

int player::getCoins()
{
    return this->playerAttribute.coins;
}

void player::addCoins(int amount)
{
    this->playerAttribute.coins += amount;
};

void player::setCoins(int amount)
{
    this->playerAttribute.coins = amount;
}

void player::removeCoins(int amount)
{
    this->playerAttribute.coins -= amount;
}

int player::checkStage()
{
    return this->playerAttribute.currentStage;
}

string player::getInventoryIndex(int index)
{
    if (index < 0 || index >= maxInventory)
    {
        throw logic_error("Invalid Capacity.");
    };

    if (playerAttribute.inventory[index] == "" || playerAttribute.inventory[index] == "Empty")
    {
        return "Empty";
    }
    else
    {
        return this->playerAttribute.inventory[index];
    };
};

string player::getFullInventory()
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

int player::searchInventory(string target)
{
    return sequentialSearch(this->playerAttribute.inventory, target);
};


bool player::addItems(string items)
{
    bool isItemAdded = false;
    for (int i = 0; i < maxInventory; i++)
    {
        if (playerAttribute.inventory[i] == "Empty")
        {
            playerAttribute.inventory[i] = items;
            isItemAdded = true;
            return isItemAdded;
        }
    }
    if (!isItemAdded)
    {
        cout << "No slot available for items " << items << " !" << endl;
        return isItemAdded;
    }
};

void player::removeItems(int index)
{
    playerAttribute.inventory[index] = "Empty";
};

void player::useItems(string target)
{
    // check if exist first
    int index = searchInventory(target);
    ItemType item = stringToItem(this->playerAttribute.inventory[index]);

    if (index != -1)
    {
        // more item soon
        switch (item)
        {
        case STRAWBERRY_MILK:
            gainHP(20);
            break;
        case BANANA_MILK:
            gainHP(25);
            break;
        default:
            break;
        }
        removeItems(index);
    }
};

// enemy class here

enemy::enemy(entityStat stat) : entity(stat) {};

void enemy::enemyRoll()
{
    rollDice(false);
}
int enemy::enemyTurn(entity *target)
{
    return attackEntity(target);
}

// can create enemy here
// {name, hp, damage, defense, startingDice}
namespace enemyList
{
    enemy *createPapadumSoldier()
    {
        entityStat stats = {"Papadum Soldier", 100, 10, 5, 0};
        return new enemy(stats);
    }
}