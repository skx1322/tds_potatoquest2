#include <iostream>
// #include "math.cpp"
#include "fs.cpp"
using namespace std;

int main(){
    player* hero = loadSave();

    if (hero != nullptr)
    {
        cout<<"Hero Name: "<<hero->getName()<<endl;
        cout<<"Hero Coin: "<<hero->getCoins()<<endl;
    }
    

    return 0;
}