#include <iostream>
#include <vector>

class Graph
{
private:
    static const int MAX_V = 100;    // Adjust the maximum number of vertices as needed
    int V;                           // Number of vertices
    std::vector<int> adjList[MAX_V]; // Adjacency list

public:
    Graph(int vertices) : V(vertices) {}

    void addEdge(int v, int w)
    {
        adjList[v].push_back(w);
        adjList[w].push_back(v); // Uncomment this line for an undirected graph
    }

    bool isCyclicUtil(int v, bool visited[], int parent)
    {
        visited[v] = true;

        for (int neighbor : adjList[v])
        {
            if (!visited[neighbor])
            {
                if (isCyclicUtil(neighbor, visited, v))
                    return true;
            }
            else if (neighbor != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool isCyclic()
    {
        bool visited[MAX_V] = {false};

        for (int i = 0; i < V; ++i)
        {
            if (!visited[i])
            {
                if (isCyclicUtil(i, visited, -1))
                    return true;
            }
        }

        return false;
    }
};

int main()
{
    Graph graph(5);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(2, 3);
    graph.addEdge(3, 3);

    if (graph.isCyclic())
    {
        std::cout << "The graph contains a cycle.\n";
    }
    else
    {
        std::cout << "The graph does not contain a cycle.\n";
    }

    return 0;
}
