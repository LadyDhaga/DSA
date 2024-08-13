/*
    Overall T.C. of this silution is O(n^2) which can be further reduced to O((E+N)logN) by using the
    priority queue and adjacency list for storing the weights and neighbours respectively
                                                                                                        */

#include <iostream>
#include <climits>
using namespace std;

int findMinVertex(int *weights, bool *visited, int n)
{
    int minVertex = -1;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && (minVertex == -1 || weights[i] < weights[minVertex]))
        {
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(int **edges, int n, int e)
{
    int *parent = new int[n];
    bool *visited = new bool[n];
    int *weight = new int[n];

    for (int i = 0; i < n; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
    }
    parent[0] = -1;
    weight[0] = 0;
    for (int i = 0; i < n - 1; i++) // we are running this loop to only n-1 times coz when we will arrive at the last vertex, its all the neighbours will already be visited.
    {
        // find minimum vertex
        int minVertex = findMinVertex(weight, visited, n); // we can use priority queue here to reduce this parts T.C. from O(n) to O(logn), coz to add or delete an element from a priority queue it takes logarithmic time.
        visited[minVertex] = true;
        // explore unvisited neighbours
        for (int j = 0; j < n; j++) // here also we can reduce time complexity from O(n) to O(E) by using the adjacency list.
        {
            if (edges[minVertex][j] != 0 && !visited[j])
            {
                if (edges[minVertex][j] < weight[j])
                {
                    weight[j] = edges[minVertex][j]; // if we were to use the priority queue to find minVertex then this part would have been slightly difficult.
                    parent[j] = minVertex;
                }
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (parent[i] < i)
        {
            cout << parent[i] << " " << i << " " << weight[i] << "\n";
        }
        else
        {
            cout << i << " " << parent[i] << " " << weight[i] << "\n";
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[f][s] = w;
        edges[s][f] = w;
    }
    prims(edges, n, e);
}