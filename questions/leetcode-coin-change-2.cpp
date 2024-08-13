#include <bits/stdc++.h>
using namespace std;

int memo(vector<int> &coins, int target, int ind, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (target % coins[ind] == 0);
    }

    if (dp[ind][target] != -1)
        return dp[ind][target];

    int a = memo(coins, target, ind - 1, dp);
    int b = 0;
    if (target >= coins[ind])
        b = memo(coins, target - coins[ind], ind, dp);

    return dp[ind][target] = a + b;
}

int dpSol(vector<int> &coins, int target)
{
    int n = coins.size();
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= target; i++)
        if (i % coins[0] == 0)
            dp[0][i] = 1;

    for (int i = 1; i < n; i++)
    {
        for (int T = ; T <= target; T++)
        {
            int a = dp[i - 1][T];
            int b = 0;
            if (T >= coins[i])
                b = dp[i][T - coins[i]];
            dp[i][T] = a + b;
        }
    }

    return dp[coins.size() - 1][target];
}

int main()
{
    int n, target;
    cin >> n;
    cin >> target;
    vector<int> coins;
    while (n--)
    {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    cout << dpSol(coins, target) << endl;
}