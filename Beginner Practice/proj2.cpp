#include <iostream>
#include <queue>
#include <cstring>

#define MAX_CITIES 100

using namespace std;

int graph[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];

int bfs(int start, int end, int numCities)
{
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (!q.empty())
    {
        int city = q.front().first;
        int days = q.front().second;
        q.pop();

        if (city == end)
        {
            return days;
        }

        for (int i = 0; i < numCities; i++)
        {
            if (graph[city][i] && !visited[i])
            {
                if (days % 6 == 0 && graph[i][0])
                {
                    continue;
                }
                q.push({i, days + 1});
                visited[i] = 1;
            }
        }
    }

    return -1;
}

int main()
{
    int numCases;
    cin >> numCases;

    while (numCases--)
    {
        int numCities, numAerialRoutes;
        cin >> numCities >> numAerialRoutes;

        memset(graph, 0, sizeof(graph));

        for (int i = 0; i < numAerialRoutes; i++)
        {
            int src, dest;
            cin >> src >> dest;
            graph[src][dest] = 1;
        }

        int minDays = bfs(1, numCities - 1, numCities);
        cout << minDays << endl;
    }

    return 0;
}
