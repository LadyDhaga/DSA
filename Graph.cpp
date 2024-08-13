#include <bits/stdc++.h>
using namespace std;

void print(int **edges, int n, int sv, bool *visited)
{
    cout << sv << " ";
    visited[sv] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1)
        {
            if (visited[i])
            {
                continue;
            }
            print(edges, n, i, visited);
        }
    }
}

void printBFS(int **edges, int n, int sv)
{
    queue<int> bus;
    bool *visited = new bool[n];

    for (int i = 0; i < n; i++)
    {
        visited[i] = 0;
    }
    bus.push(sv);

    while (bus.size())
    {
        auto top = bus.front();
        bus.pop();
        visited[top] = 1;
        cout << top << " ";
        for (int i = 0; i < n; i++)
        {
            if (i == top)
            {
                continue;
            }
            if (edges[top][i] && !visited[i])
            {
                bus.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int sv = 0; sv < n; sv++)
    {
        if (visited[sv] == false)
        {
            queue<int> bus;
            bus.push(sv);

            while (bus.size())
            {
                auto top = bus.front();
                bus.pop();
                visited[top] = true;
                cout << top << " ";
                for (int i = 0; i < n; i++)
                {
                    if (i == top)
                    {
                        continue;
                    }
                    if (edges[top][i] && !visited[i])
                    {
                        bus.push(i);
                        visited[i] = true;
                    }
                }
            }
        }
    }
    delete[] visited;
}

void DFS(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            print(edges, n, i, visited);
        }
    }
    delete[] visited;
}

bool hasPath(int **edges, int n, int x, int y)
{
    if (x == y)
    {
        return true;
    }

    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> bus;
    bus.push(x);
    while (bus.size())
    {
        auto top = bus.front();
        bus.pop();
        if (top == y)
        {
            return true;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != top && visited[i] == false && edges[top][i] == 1)
            {
                bus.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

void hasPathDfs(int **edges, int n, int x, int y, vector<int> &ans, bool *visited)
{
    if (x == y)
    {
        ans.push_back(x);
        return;
    }
    if (hasPath(edges, n, x, y) == false)
    {
        ans.clear();
        return;
    }
    ans.push_back(x);
    visited[x] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != x && edges[x][i] == 1 && visited[i] == false && hasPath(edges, n, i, y) == true)
        {
            visited[i] = true;
            // ans.push_back(i);
            hasPathDfs(edges, n, i, y, ans, visited);
            return;
        }
    }
    return;
}

vector<int> getPathBfs(int **edges, int n, int x, int y)
{
    if (!hasPath(edges, n, x, y))
    {
        return {};
    }
    if (x == y)
    {
        return {x};
    }
    vector<int> ans;
    queue<int> bus;
    bus.push(x);
    vector<bool> visited(n, false);
    visited[x] = true;
    unordered_map<int, int> umap;
    while (!bus.empty())
    {
        auto top = bus.front();
        bus.pop();
        if (top == y)
        {
            break;
        }
        for (int i = 0; i < n; i++)
        {
            if (i != x && edges[top][i] == 1 && !visited[i])
            {
                umap[i] = top;
                bus.push(i);
                visited[i] = true;
            }
        }
    }
    // int p = -1;
    int q = y;
    while (q != x)
    {
        ans.push_back(q);
        q = umap[q];
    }
    ans.push_back(x);
    return ans;
}

void isConHelper(int **edges, int n, int x, bool *visited)
{
    visited[x] = true;
    for (int i = 0; i < n; i++)
    {
        if (i != x && edges[x][i] == 1 && visited[i] == false)
        {
            isConHelper(edges, n, i, visited);
        }
    }
    return;
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    isConHelper(edges, n, 0, visited);
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            return false;
        }
    }
    return true;
}

void connectedComponents(int **edges, int n, int x, bool *visited)
{
    visited[x] = true;
    cout << x << " ";
    for (int i = 0; i < n; i++)
    {
        if (i != x && edges[x][i] == 1 && visited[i] == false)
        {
            connectedComponents(edges, n, i, visited);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            cout << endl;
            connectedComponents(edges, n, i, visited);
        }
    }
    return;
}

int islands(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == false)
        {
            count++;
            isConHelper(edges, n, i, visited);
        }
    }
    return count;
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
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    cout << islands(edges, n) << endl;

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}