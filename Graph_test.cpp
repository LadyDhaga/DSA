#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

vector<int> MST(int **edges, int n, int e)
{
    vector<vector<int>> newedges;
    for (int i = 0; i < e; i++)
    {
        newedges.push_back({edges[i][2], edges[i][0], edges[i][1]});
    }
    sort(newedges.begin(), newedges.end());
}

bool isConnected(int **edges, int n)
{
    bool *visited = new bool[n];
    queue<int> bus;
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    bus.push(0);
    visited[0] = true;
    while (!bus.empty())
    {
        auto top = bus.front();
        bus.pop();
        for (int i = 0; i < n; i++)
        {
            if (i == top)
            {
                continue;
            }
            if (edges[top][i] == 1 && !visited[i])
            {
                visited[i] = true;
                bus.push(i);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}

vector<int> getPathBFS(int **edges, int n, int s1, int s2)
{
    if (s1 == s2)
    {
        return {s1};
    }
    if (edges[s1][s2])
    {
        return {s1, s2};
    }
    vector<int> ans;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    visited[s1] = true;
    unordered_map<int, int> umap;
    queue<int> bus;
    bus.push(s1);
    int cur = -1;

    while (!bus.empty())
    {
        auto top = bus.front();
        bus.pop();
        if (top == s2)
        {
            cur = s2;
        }
        for (int i = 0; i < n; i++)
        {
            if (i == top)
            {
                continue;
            }
            if (edges[top][i] == 1 && !visited[i])
            {
                visited[i] = true;
                umap[i] = top;
            }
        }
    }
    if (cur == -1)
        return {};
    ans.push_back(s2);
    while (s2 != s1)
    {
        ans.push_back(umap[s2]);
        s2 = umap[s2];
    }
    for (auto &i : ans)
    {
        cout << i << " ";
    }
}

vector<int> help1(int **edges, int n, int s1, int s2, bool *visited)
{
    if (s1 == s2)
    {
        return {s1};
    }
    vector<int> cur;
    visited[s1] = true;
    for (int i = 0; i < n; i++)
    {
        if (i == s1)
            continue;
        if (edges[s1][i] == 1 && !visited[i])
        {
            visited[i] = true;
            cur = help1(edges, n, i, s2, visited);
            if (!cur.empty())
            {
                cur.insert(cur.begin(), s1);
                return cur;
            }
        }
    }
    return {};
}

void getPathDFS(int **edges, int n, int s1, int s2)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    vector<int> temp = help1(edges, n, s1, s2, visited);
    for (auto &i : temp)
    {
        cout << i << " ";
    }
}

bool hasPath(int **edges, int n, int s1, int s2) // TC = O(V+E), E=V^2 in worst case
{
    if (edges[s1][s2] == 1)
        return true;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    visited[s1] = true;
    queue<int> bus;
    bus.push(s1);
    while (!bus.empty())
    {
        auto top = bus.front();
        bus.pop();
        if (top == s2)
            return true;
        for (int i = 0; i < n; i++)
        {
            if (i == top)
                continue;
            if (edges[top][i] == 1 && visited[i] == false)
            {
                bus.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
}

void print(int **edges, int n, int ind, bool *visited)
{
    cout << ind << " ";
    visited[ind] = 1;
    for (int i = 0; i < n; i++)
    {
        if (i == ind)
            continue;
        if (edges[ind][i] == 1 && visited[i] == 0)
        {
            print(edges, n, i, visited);
        }
    }
}

void allConnectedComponents(int **edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            print(edges, n, i, visited);
        }
        cout << "\n";
    }
}

void printbfs(int **edges, int n, int ind)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    queue<int> bus;
    bus.push(ind);
    visited[ind] = true;
    while (!bus.empty())
    {
        auto top = bus.front();
        bus.pop();
        cout << top << "\n";
        for (int i = 0; i < n; i++)
        {
            if (i == top)
                continue;
            if (edges[top][i] == 1 && visited[i] == false)
            {
                bus.push(i);
                visited[i] = true;
            }
        }
    }
}

int main()
{

    vector<int> ans = MST(edges, n);
}
