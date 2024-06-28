#include <iostream>
#include <queue>

class Graph
{
private:
    static const int MAX_V = 100; // Adjust the maximum number of vertices as needed
    int V;                        // Number of vertices
    int adjList[MAX_V][MAX_V];    // Adjacency list

public:
    Graph(int vertices) : V(vertices)
    {
        for (int i = 0; i < MAX_V; ++i)
        {
            for (int j = 0; j < MAX_V; ++j)
            {
                adjList[i][j] = 0;
            }
        }
    }

    void addEdge(int v, int w)
    {
        adjList[v][w] = 1;
        adjList[w][v] = 1; // Uncomment this line for an undirected graph
    }

    void shortestPath(int start, int end)
    {
        int parent[MAX_V];
        bool visited[MAX_V] = {false};

        std::queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty())
        {
            int current = q.front();
            q.pop();

            for (int neighbor = 0; neighbor < V; ++neighbor)
            {
                if (adjList[current][neighbor] == 1 && !visited[neighbor])
                {
                    q.push(neighbor);
                    visited[neighbor] = true;
                    parent[neighbor] = current;
                }
            }
        }

        // Reconstruct the path from end to start
        int current = end;
        while (current != start)
        {
            std::cout << current << " ";
            current = parent[current];
        }
        std::cout << start << std::endl;
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    int startVertex = 0;
    int endVertex = 5;

    std::cout << "Shortest Path from " << startVertex << " to " << endVertex << ": ";
    graph.shortestPath(startVertex, endVertex);

    return 0;
}
