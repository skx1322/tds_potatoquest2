#include <iostream>
#include "display.cpp"

using namespace std;
using namespace gameDisplay;

int main(){
    // int dice = diceRoll(false);
    string test[16] = {"Fu Hua", "Hua", "Senti", "Kiana", "Seele", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};
    
    int index = displayInventory(test);

    cout<<"Index: "<<test[index]<<endl;
    return 0;
}