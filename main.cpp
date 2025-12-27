#include <iostream>
#include "math.cpp"
using namespace std;

int main(){
    int dmg = entitySystem::damageCalc(4, 3);

    cout<<dmg<<endl;

    return 0;
}