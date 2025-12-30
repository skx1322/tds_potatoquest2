#include <iostream>
#include <cmath>
using namespace std;

namespace mathSystem
{
    int damageCalc(int dmg, int dice)
    {
        if (4 > dice)
        {
            return 0;
        }
        else
        {
            return floor(dmg * ((dice / 100) + 1));
        }
    };

    int diceRoll(bool pity)
    {
        const int randomNum = (rand() % 20) + 1;
        return randomNum;
    }
};

namespace dataStrucutre
{
    class combatQueue
    {
    private:
        Node *front;
        Node *back;

    public:
        combatQueue()
        {
            front = nullptr;
            back = nullptr;
        };

        void enqueue(entity *ent)
        {
            Node *newNode = new Node(ent);
            if (back == nullptr)
            {
                front = back = newNode;
                return;
            }

            back->next = newNode;
            back = newNode;
        };

        entity *dequeue()
        {
            if (front == nullptr)
            {
                return nullptr;
            }

            Node *temp = front;
            entity *ent = temp->data;
            front = front->next;

            if (front == nullptr)
            {
                back = nullptr;
            }
            delete temp;
            return ent;
        }

        bool isEmpty()
        {
            return front == nullptr;
        }

        ~combatQueue()
        {
            while (!isEmpty())
            {
                dequeue();
            }
        }
    };
};

namespace algorithmLib
{
    int binarySearch(string *inv, string target)
    {
        int first = 0;
        int last = inv->size(); // to find array size/length
        while (first <= last)
        {
            int center = first + (last - first) / 2;
            if (inv[center] == target)
            {
                return center;
            }
            else if (inv[center] < target)
            {
                first = center + 1;
            }
            else
            {
                last = center - 1;
            }
        }
        return -1;
    }
}