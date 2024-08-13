#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

class Edge
{
public:
    int source;
    int dest;
    int weight;
};

bool mycomp(Edge e1, Edge e2)
{
    return e1.weight < e2.weight;
}

int minDisVertex(bool *visited, int *distance, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

int minDis(int source, int dest, Edge *edges, int n, int e)
{
    bool *visited = new bool[n];
    int *distance = new int[n];
    sort(edges, edges + e, mycomp);
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        distance[i] = INT_MAX;
    }
    distance[source] = 0;

    for (int i = 1; i < n - 1; i++) // n-1 times
    {
        int u = minDisVertex(visited, distance, n); // n times. we can use priority queue here
        visited[u] = true;
        for (int j = 0; j < e; j++) // adjacency list here
        {
            auto curEdge = edges[j]; 
            if (curEdge.source == u && !visited[curEdge.dest])
            {
                distance[curEdge.dest] = min(distance[curEdge.dest], distance[u] + curEdge.weight); // if we use priority queue then we have to take special care of this step.
            }
        }
    }
    return distance[dest];
}

int main()
{
    int n, e;
    cin >> n >> e;
    Edge *input = new Edge[e];

    for (int i = 0; i < e; i++)
    {
        int d, s, w;
        cin >> s >> d >> w;
        input[i].dest = d;
        input[i].source = s;
        input[i].weight = w;
    }

    for (int i = 1; i < n; i++)
    {
        cout << i << " " << minDis(0, i, input, n, e) << "\n";
    }
}