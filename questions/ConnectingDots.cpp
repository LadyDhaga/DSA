#include <bits/stdc++.h>
using namespace std;

set<pair<int, int>> s1;
vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool helper(vector<string> &grid, int i, int j, int k)
{
    if (k >= 4)
    {
        for (auto &m : dir)
        {
            int temp1 = i + m.first;
            int temp2 = j + m.second;
            if (s1.count({temp1, temp2}))
            {
                return true;
            }
        }
    }
    bool ans = false;
    for (auto &m : dir)
    {
        int temp1 = i + m.first;
        int temp2 = j + m.second;
        if (temp1 >= 0 && temp2 >= 0 && temp1 < grid.size() && temp2 < grid[0].length() && !s1.count({temp1, temp2}) && grid[i][j] == grid[temp1][temp2])
        {
            s1.insert({temp1, temp2});
            ans = ans || helper(grid, temp1, temp2, k + 1);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return ans;
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid;
    for (int i = 0; i < n; i++)
    {
        string p;
        cin >> p;
        grid.push_back(p);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (helper(grid, i, j, 1))
            {
                s1.clear();
                s1.insert({i, j});
                cout << "True" << endl;
                return 0;
            }
        }
    }
    cout << "False" << endl;
    return 0;
}