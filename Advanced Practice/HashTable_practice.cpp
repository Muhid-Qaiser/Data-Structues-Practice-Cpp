#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(NULL) {}
};

struct Pair
{
    int key, value;
    bool isused;

    Pair() : key(0), value(0), isused(false) {}
    Pair(int key, int value) : key(key), value(value), isused(true) {}
};

struct HashTable
{
    Pair *array;
    int size, capacity;

public:
    HashTable(int c)
    {
        capacity = c;
        size = 0;
        array = new Pair[capacity];

        for (int i = 0; i < capacity; i++)
        {
            array[i].isused = false;
        }
    }

    int hash(int key)
    {
        return key % capacity;
    }

    void insert(int value)
    {
        int index = hash(value);

        if (size >= capacity)
        {
            cout << "FUll\n";
            return;
        }

        while (array[index].isused)
        {
            index = (index + 1) % capacity;
        }
        array[index] = Pair(value, value);
        size++;
    }

    void remove(int key)
    {
        int index = hash(key), originalIndex = index;

        while (array[index].isused)
        {

            if (array[index].key == key)
            {
                array[index].value = -1;
                array[index].key = -1;
                array[index].isused = false;
                return;
            }
            index = (index + 1) % capacity;

            if (index == originalIndex)
                break;
        }
        cout << "Not FOund!\n";
    }

    void display()
    {
        for (int i = 0; i < capacity; i++)
        {
            if (array[i].isused)
                cout << array[i].key << " " << array[i].value << endl;
        }
    }
};

int main()
{
    HashTable h(9);

    h.insert(83);
    h.insert(67);
    h.insert(48);
    h.insert(24);
    h.insert(52);
    h.insert(21);
    h.insert(43);
    h.insert(53);
    h.insert(19);

    // cout << h.search(83) << endl;
    // h.display();
    h.remove(19);
    h.display();

    return 0;
}