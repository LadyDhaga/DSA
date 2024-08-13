#include <bits/stdc++.h>
using namespace std;

string p = "CODINGNINJA";
int len = 11;
vector<pair<int, int>> dir = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
set<pair<int, int>> s1;
bool helper(vector<string> &grid, int i, int j, int k)
{
    if (k >= len)
    {
        return true;
    }
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].length())
    {
        return false;
    }
    bool ans = false;
    for (auto &m : dir)
    {
        int temp1 = i + m.first;
        int temp2 = j + m.second;
        if (temp1 >= 0 && temp1 < grid.size() && temp2 >= 0 && temp2 < grid[0].length() && !s1.count({temp1, temp2}) && grid[temp1][temp2] == p[k])
        {
            s1.insert({i, j});
            ans = ans || helper(grid, temp1, temp2, k + 1);
        }
    }
    return ans;
}

int main()
{
    int n;
    int m;
    cin >> n >> m;
    vector<string> grid;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        grid.push_back(temp);
    }
    // vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'C')
            {
                // visited[i][j] = true;
                s1.clear();
                s1.insert({i, j});
                if (helper(grid, i, j, 1))
                {
                    cout << "1" << endl;
                    return 0;
                }
            }
        }
    }

    cout << "0" << endl;
}