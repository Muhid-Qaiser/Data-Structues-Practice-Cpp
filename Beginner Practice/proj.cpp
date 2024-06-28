#include <iostream>
#include <queue>
#include <cstring>

#define MAX_CITIES 100
// #define MAX_CITIES 98

using namespace std;

int graph[MAX_CITIES][MAX_CITIES];
int visited[MAX_CITIES];

int bfs(int start, int end, int numCities)
{
    memset(visited, 0, sizeof(visited));

    queue<int> q;
    q.push(start);
    visited[start] = 1;

    int days = 0;
    int citiesCovered = 0;
    int citiesInCurrentDay = 1;
    int citiesInNextDay = 0;

    while (!q.empty())
    {
        int currentCity = q.front();
        q.pop();
        citiesInCurrentDay--;

        if (currentCity == end)
        {
            return days;
        }

        for (int i = 0; i < numCities; i++)
        {
            if (graph[currentCity][i] && !visited[i])
            {
                q.push(i);
                visited[i] = 1;
                citiesInNextDay++;
                citiesCovered++;

                if (citiesCovered % 6 == 0)
                {
                    days++;
                    citiesInCurrentDay = citiesInNextDay;
                    citiesInNextDay = 0;
                }
            }
        }
    }

    return -1; // Destination city not reachable
}

void fun(int graph[][MAX_CITIES], int max)
{

    for (int i = 0; i < max; i++)
    {
        for (int j = 0; j < max; j++)
        {
            if (i + 1 == j)
                graph[i][j] = 6;
        }
    }

    cout << "    ";
    for (int i = 0; i < max; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < max; i++)
    {
        cout << i << " : ";
        for (int j = 0; j < max; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int numTestCases;
    cin >> numTestCases;

    memset(graph, 0, sizeof(graph));

    while (numTestCases--)
    {
        int numCities;
        cin >> numCities;

        fun(graph, numCities);

        int numAerialRoutes;
        cin >> numAerialRoutes;

        for (int i = 0; i < numAerialRoutes; i++)
        {
            int source, destination;
            cin >> source >> destination;
            graph[source][destination] = 1;
        }

        int startCity = 1;
        int endCity = numCities - 1;

        int minDays = bfs(startCity, endCity, numCities);
        cout << minDays << endl;
    }

    return 0;
}
