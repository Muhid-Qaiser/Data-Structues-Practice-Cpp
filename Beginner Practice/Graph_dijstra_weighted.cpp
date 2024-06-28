#include <iostream>
#include <queue>

class Graph
{
private:
    static const int MAX_V = 100; // Adjust the maximum number of vertices as needed
    int V;                        // Number of vertices
    int adjList[MAX_V][MAX_V];    // Adjacency list (vertex, weight)

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

    void addEdge(int v, int w, int weight)
    {
        adjList[v][w] = weight;
        adjList[w][v] = weight; // Uncomment this line for an undirected graph
    }

    void dijkstra(int start)
    {
        int distance[MAX_V];
        bool visited[MAX_V] = {false};

        for (int i = 0; i < V; ++i)
        {
            distance[i] = INT_MAX;
        }
        distance[start] = 0;

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
        pq.push({0, start});

        while (!pq.empty())
        {
            int current = pq.top().second;
            int currentDistance = pq.top().first;
            pq.pop();

            if (currentDistance > distance[current])
            {
                continue;
            }

            for (int neighbor = 0; neighbor < V; ++neighbor)
            {
                if (adjList[current][neighbor] > 0)
                {
                    int newDistance = currentDistance + adjList[current][neighbor];
                    if (newDistance < distance[neighbor])
                    {
                        distance[neighbor] = newDistance;
                        pq.push({newDistance, neighbor});
                    }
                }
            }
        }

        std::cout << "Shortest Distances from vertex " << start << ":\n";
        for (int i = 0; i < V; ++i)
        {
            std::cout << "To vertex " << i << ": " << distance[i] << "\n";
        }
    }
};

int main()
{
    Graph graph(6);

    graph.addEdge(0, 1, 2);
    graph.addEdge(0, 2, 4);
    graph.addEdge(1, 3, 1);
    graph.addEdge(2, 4, 3);
    graph.addEdge(3, 5, 5);
    graph.addEdge(4, 5, 1);

    int startVertex = 0;

    graph.dijkstra(startVertex);

    return 0;
}
