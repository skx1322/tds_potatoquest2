#include <iostream>
#include <fstream>
#include <sstream>
#include "entity.cpp"
// #include "header.hpp"
using namespace std;

int convertStringToNum(string numString){
    return stoi(numString);
}

void loadInv(string line, string* invArray, int maxSlot){
    stringstream ss(line);
    string item;
    int index = 0;
    
    while (getline(ss, item, ',') && index < maxSlot)
    {
        size_t first = item.find_first_not_of(' ');
        if (first != string::npos)
        {
            item = item.substr(first);
        }
        
        invArray[index] = item;
        index++;
    }  
};

void saveProgress(player playerProgress){
    ofstream saveFile("save.txt");

    if (!saveFile.is_open())
    {
        throw system("File not found.");
    };
    
    saveFile << playerProgress.getName() << endl;
    saveFile << playerProgress.getHealth() << endl;
    saveFile << playerProgress.getDamage() << endl;
    saveFile << playerProgress.getDefense() << endl;
    saveFile << playerProgress.getDice() << endl;
    saveFile << playerProgress.getFullInventory() << endl;
    saveFile << playerProgress.getCoins() << endl;
    saveFile << playerProgress.checkStage() << endl;

    saveFile.close();
};

player* loadSave(){
    ifstream saveFile("save.txt");

    if (!saveFile.is_open())
    {
        cout<<"Save file not found!"<<endl;
        return nullptr;
    }

    entityStat eStat;
    playerStat pStat;
    string temp;

    if (!getline(saveFile, eStat.entityName)) 
    {
        return nullptr;
    };

    getline(saveFile, temp);
    eStat.entityHealth = stoi(temp);
    
    getline(saveFile, temp);
    eStat.entityDamage = stoi(temp);
    
    getline(saveFile, temp);
    eStat.entityDefense = stoi(temp);
    
    getline(saveFile, temp);
    eStat.entityDice = stoi(temp);


    string invLine;
    getline(saveFile, invLine);

    for (int i = 0; i < maxInventory; i++)
    {
        pStat.inventory[i] = "";
    }

    loadInv(invLine, pStat.inventory, maxInventory);

    getline(saveFile, temp);
    pStat.coins = stoi(temp);

    getline(saveFile, temp);
    pStat.currentStage = stoi(temp);

    saveFile.close();

    return new player(eStat, pStat);
}

