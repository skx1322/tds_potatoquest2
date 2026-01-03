#include <iostream>
#include "header.hpp"
// #include "system.hpp"
using namespace std;
// using namespace systemConsole;

namespace inventoryDisplay{
    int displayInventory(string inv[]){
        int currentPage = 1, pageItems = 8, input;
        int maxPage = (maxInventory + pageItems - 1) / pageItems;

        while (true)
        {
            cout << "[---- ----- ----- ----- -----]" << endl;
            cout << "1. Previous Page, 2. Next Page, 3. Confirm Search" << endl;
            cout << "[---- ----- ----- ----- -----]" << endl;

            int startIndex = (currentPage - 1) * pageItems;

            for (int i = 0; i < 2; i++)
            {
                cout << "| " << endl;
                for (int j = 0; j < 4; j++)
                {
                    int currentIndex = startIndex + (i * 4 + j);

                    if (currentIndex < maxInventory)
                    {
                        string currentItems = inv[currentIndex];
                        cout << currentIndex + 1 << ". " << inv[currentIndex];
                        cout << " | ";
                    }
                    else
                    {
                        cout << "-                 -";
                    }
                }
                cout << "|" << endl;
            }
            cout << "[---- ----- ----- ----- -----]" << endl;
            cout << "Page: < " << currentPage << " / " << maxPage << " >" << endl;
            cout << "1. Previous Page, 2. Next Page, 3. Confirm Search" << endl;
            cout << "[---- ----- ----- ----- -----]" << endl;

            cin >> input;
            system("cls");

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                continue;
            }

            if (input == 1 && currentPage > 1)
            {
                currentPage--;
            }
            else if (input == 2 && currentPage < maxPage)
            {
                currentPage++;
            }
            else if (input == 2 && currentPage >= maxPage)
            {
                currentPage--;
            }
            else if (input == 1 && currentPage == 1)
            {
                currentPage++;
            }
            else
            {
                int selects;
                cout << "Enter Item Number to Use: ";
                cin >> selects;

                int actualIndex = selects - 1;
                system("cls");
                return actualIndex;
            }
        }
    }
};
