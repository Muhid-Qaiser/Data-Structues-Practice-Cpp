#include <iostream>
using namespace std;

class Graph
{
private:
    int V;           // Number of vertices
    int **adjMatrix; // Adjacency matrix to store edges

public:
    // Constructor
    Graph(int vertices) : V(vertices)
    {
        // Allocate memory for the adjacency matrix
        adjMatrix = new int *[V];
        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i] = new int[V];
            // Initialize all elements to 0
            for (int j = 0; j < V; ++j)
            {
                adjMatrix[i][j] = 0;
            }
        }
    }

    // Add an edge to the graph
    void addEdge(int v, int w)
    {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1; // Uncomment this line for an undirected graph
    }

    // Add a new vertex to the graph
    void addVertex()
    {
        // Create a new adjacency matrix with increased size
        int **newAdjMatrix = new int *[V + 1];
        for (int i = 0; i < V + 1; ++i)
        {
            newAdjMatrix[i] = new int[V + 1];
            // Initialize all elements to 0
            for (int j = 0; j < V + 1; ++j)
            {
                newAdjMatrix[i][j] = 0;
            }
        }

        // Copy the existing adjacency matrix to the new matrix
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                newAdjMatrix[i][j] = adjMatrix[i][j];
            }
        }

        // Delete the old adjacency matrix
        for (int i = 0; i < V; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

        // Update the pointer to the new adjacency matrix
        adjMatrix = newAdjMatrix;

        // Increment the number of vertices
        ++V;
    }

    // Print the graph
    void printGraph()
    {
        std::cout << "\t\t\t      ";
        for (int i = 0; i < V; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < V; ++i)
        {
            std::cout << "Adjacency matrix of vertex " << i << ": ";
            for (int j = 0; j < V; ++j)
            {
                std::cout << adjMatrix[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Destructor to free the allocated memory
    ~Graph()
    {
        for (int i = 0; i < V; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;
    }

    int countEdges()
    {
        float count = 0.0;

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                count += adjMatrix[i][j];
            }
        }

        count /= 2;

        if (count > int(count))
            count += 1;

        return count;
    }
};

int main()
{
    // Create a graph with 5 vertices
    Graph graph(5);

    // Add edges
    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);
    // graph.addEdge(4, 4);

    // Add a new vertex
    graph.addVertex();

    // Print the updated graph
    graph.printGraph();

    cout << "\nEdges: " << graph.countEdges() << endl;

    return 0;
}
