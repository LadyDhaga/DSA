#include <bits/stdc++.h>
using namespace std;

int maxLoot(vector<int> &houses, vector<int> &dp, int i = 0)
{
    int n = houses.size();
    if (i == n - 1)
        return dp[i] = houses[i];
    if (i >= n)
        return 0;

    if (dp[i] != -1)
        return dp[i];
    int a = houses[i] + maxLoot(houses, dp, i + 2);
    int b = maxLoot(houses, dp, i + 1);

    return dp[i] = max(a, b);
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        vector<int> houses(m, -1);
        for (int i = 0; i < m; i++)
            cin >> houses[i];
        vector<int> dp(m, -1);
        cout << maxLoot(houses, dp) << endl;
    }
}