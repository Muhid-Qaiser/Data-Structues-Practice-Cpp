#include <iostream>

// Node to represent a vertex in the adjacency list
struct Node
{
    int data;
    Node *next;

    Node(int value) : data(value), next(nullptr) {}
};

class Graph
{
private:
    int V;          // Number of vertices
    Node **adjList; // Adjacency list array

public:
    // Constructor
    Graph(int vertices) : V(vertices)
    {
        adjList = new Node *[V];
        for (int i = 0; i < V; ++i)
        {
            adjList[i] = nullptr;
        }
    }

    // Add a directed edge to the graph
    void addEdge(int v, int w)
    {
        Node *newNodeW = new Node(w);
        newNodeW->next = adjList[v];
        adjList[v] = newNodeW;
    }

    // Add a new vertex to the graph
    void addVertex()
    {
        // Create a new adjacency list with increased size
        Node **newAdjList = new Node *[V + 1];
        for (int i = 0; i < V + 1; ++i)
        {
            newAdjList[i] = nullptr;
        }

        // Copy the existing adjacency list to the new list
        for (int i = 0; i < V; ++i)
        {
            Node *current = adjList[i];
            while (current)
            {
                Node *newNode = new Node(current->data);
                newNode->next = newAdjList[i];
                newAdjList[i] = newNode;

                current = current->next;
            }
        }

        // Delete the old adjacency list
        delete[] adjList;

        // Update the pointer to the new adjacency list
        adjList = newAdjList;

        // Increment the number of vertices
        ++V;
    }

    // Print the graph
    void printGraph()
    {
        for (int i = 0; i < V; ++i)
        {
            std::cout << "Adjacency list of vertex " << i << ": ";
            Node *current = adjList[i];
            while (current)
            {
                std::cout << current->data << " ";
                current = current->next;
            }
            std::cout << std::endl;
        }
    }

    // Destructor to free the allocated memory
    ~Graph()
    {
        for (int i = 0; i < V; ++i)
        {
            Node *current = adjList[i];
            while (current)
            {
                Node *temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }
};

int main()
{
    // Create a directed graph with 5 vertices
    Graph graph(5);

    // Add directed edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    // Add a new vertex
    graph.addVertex();

    // Print the updated graph
    graph.printGraph();

    return 0;
}
