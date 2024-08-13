#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

static bool mycomp(vector<int> &p1, vector<int> &p2)
{
    return p1[0] <= p2[0];
}

int find(int x, vector<int> &link)
{
    while (x != link[x])
        x = link[x];
    return x;
}

bool same(int a, int b, vector<int> &link)
{
    return find(a, link) == find(b, link);
}

void unite(int a, int b, vector<int> &link, vector<int> &size)
{
    a = find(a, link);
    b = find(b, link);
    if (size[a] <= size[b])
        swap(a, b);
    size[a] += size[b];
    link[b] = a;
}

vector<vector<int>> MST(int **edges, int n, int e)
{
    vector<vector<int>> newedges;

    for (int i = 0; i < e; i++)
    {
        newedges.push_back({edges[i][2], edges[i][0], edges[i][1]});
    }

    sort(newedges.begin(), newedges.end(), mycomp); // sort the input array on the basis of their weights.
    vector<int> link(n, 0), size(n, 1);
    for (int i = 0; i < n; i++)
        link[i] = i; // keeping the track of the parents
    vector<vector<int>> ans;
    int i = 0;
    while (ans.size() != n - 1)
    {
        auto cur = newedges[i];
        if (!same(cur[1], cur[2], link)) // check if we can add the current edge in the mst or not.
        {
            ans.push_back(newedges[i]);
            unite(cur[1], cur[2], link, size);
        }
        i++;
    }
    return ans;
}

int main()
{
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[3];
        for (int j = 0; j < 3; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s, w;
        cin >> f >> s >> w;
        edges[i][0] = f;
        edges[i][1] = s;
        edges[i][2] = w;
    }

    vector<vector<int>> ans = MST(edges, n, e);
    for (auto &i : ans)
    {
        cout << i[1] << " " << i[2] << " " << i[0] << "\n";
    }
}
