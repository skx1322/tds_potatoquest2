#ifndef ENTITY_HPP
#define ENTITY_HPP

using namespace std;

const int maxInventory = 16;

// exception for snake case usage here
enum ItemType
{
    STRAWBERRY_MILK,
    BANANA_MILK,
    APPLE_JUICE,
    PROTEIN_SHAKE,
    DIVINE_KEY,
};

ItemType stringToItem(string target)
{
    if (target == "Strawberry Milk")
        return STRAWBERRY_MILK;
    if (target == "Banana Milk")
        return BANANA_MILK;
    if (target == "Apple Juice")
        return APPLE_JUICE;
    if (target == "Protein Shake")
        return PROTEIN_SHAKE;
    if (target == "Divine Key")
        return DIVINE_KEY;
    if (target == "Empty")
    {
        return;
    }
    
}

struct entityStat
{
    string entityName;
    int entityHealth;
    int entityDamage;
    int entityDefense;
    int entityDice;
};

struct playerStat
{
    string inventory[maxInventory];
    int coins;
    int currentStage;
};

class entity
{
protected:
    entityStat attributes;

public:
    entity(entityStat stat);
    string getName();
    entityStat getFullAttributes();
    int getHealth();
    int getDamage();
    int getDefense();
    int getDice();

    bool isAlive();
    int receiveDamage(int amount);
    void rollDice(bool pity);
    void resetDice();

    void setHP(int amount);
    int gainHP(int amount);
    int attackEntity(entity *target);
};

class player : public entity
{
private:
    playerStat playerAttribute;

public:
    player(entityStat eStat, playerStat pStat);
    int checkStage();

    int getCoins();
    void addCoins(int amount);
    void setCoins(int amount);
    void removeCoins(int amount);

    string getInventoryIndex(int index);
    string getFullInventory();
    int searchInventory(string target);
    bool addItems(string items);
    void removeItems(int index);
    void useItems(string target);
};

class enemy : public entity
{
public:
    enemy(entityStat stat);
    void enemyRoll();
    int enemyTurn(entity *target);
};

struct Node
{
    entity *data;
    Node *next;

    Node(entity *ent)
    {
        data = ent;
        next = nullptr;
    }
};

#endif