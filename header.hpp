#ifndef ENTITY_HPP
#define ENTITY_HPP

using namespace std;

const int maxInventory = 12;

const string itemsTemplate[] = {"Health Potion", "Trinket", "Bread"};
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

class player : public entity{
    private: 
        playerStat playerAttribute;
    public: 
        player(entityStat eStat, playerStat pStat);
        int getCoins();
        int checkStage();
        string getInventoryIndex(int index);
        string getFullInventory();
};

class enemy : public entity {
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