#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace chrono_literals;

// made this namespace solely for flexiblity/cross platform because the current system command might not work in some OS
namespace systemConsole
{
    void clearConsole()
    {
        if (_WIN32)
        {
            system("cls");
        }
        else
        {
            system("clear");
        }
    };

    void stopProgram(){
        system("pause");
    }
}

// this is for time system to add delay/etc.
namespace chronoConsole{
    void delayOutputHalf(){
        this_thread::sleep_for(500ms);
    }
}