#include <iostream>
using namespace std;

class GraphMatrix
{
    int **array;
    int size;

public:
    GraphMatrix(int size)
    {
        this->size = size;
        array = new int *[size];

        for (int i = 0; i < size; i++)
        {
            array[i] = new int[size];
            for (int j = 0; j < size; j++)
            {
                array[i][j] = 0;
            }
        }
    }

    void addEdge(int x, int y, int val)
    {
        array[x][y] = val;
        array[y][x] = val;
    }

    void addVertex()
    {
        int **temp = new int *[size + 1];

        for (int i = 0; i < size + 1; i++)
        {
            temp[i] = new int[size + 1];

            for (int k = 0; k < size + 1; k++)
            {
                temp[i][k] = 0;
            }
        }

        for (int i = 0; i < size; i++)
        {

            for (int k = 0; k < size; k++)
            {
                temp[i][k] = array[i][k];
            }
        }

        delete[] array;
        array = temp;
        size++;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << array[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
};

class Vertex
{
public:
    int data;
    int *neighbors;
    int size;
    Vertex *next;

    Vertex() : data(0), size(0), neighbors(NULL), next(NULL) {}
    Vertex(int data) : data(data), size(1), neighbors(NULL), next(NULL) {}

    // void addNeighbor(int index)
    // {
    //     int* new
    // }
};

class GraphList
{
    Vertex **array;
    int size;

public:
    GraphList(int size) : size(size)
    {
        array = new Vertex *[size];
        for (int i = 0; i < size; i++)
        {
            array[i] = NULL;
        }
    }

    void addEdge(int from, int to)
    {
        Vertex *nn = new Vertex(to);

        if (!array[from])
        {
            array[from] = nn;
        }
        else
        {
            Vertex *temp = array[from];

            while (temp->next)
                temp = temp->next;

            temp->next = nn;
        }
    }

    void addVertex()
    {
        Vertex **temp = new Vertex *[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = array[i];
        }
        temp[size] = NULL;
        delete[] array;
        array = temp;
        size++;
    }

    void display()
    {
        Vertex *temp = NULL;

        for (int i = 0; i < size; i++)
        {
            temp = array[i];
            cout << i << " : ";

            while (temp)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main()
{
    // GraphMatrix g(4);
    // g.display();
    // g.addEdge(1, 1, 5);
    // g.addVertex();
    // g.display();

    GraphList g(4);
    g.addEdge(1, 1);
    g.addEdge(1, 2);
    g.addEdge(0, 1);
    g.addVertex();
    g.display();
    // g.addVertex();
    // g.display();

    return 0;
}