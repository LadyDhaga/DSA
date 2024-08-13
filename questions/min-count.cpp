#include <bits/stdc++.h>
using namespace std;

int minCount(int n)
{
    if (n <= 2)
        return 1;

    int ans = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (i * i == n)
            return 1;
        int curr = minCount(n - i) + minCount(i);
        ans = min(ans, curr);
    }

    return ans;
}

int minCountMem_helper(int n, vector<int> &dp)
{
    if (n <= 2)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;
    for (int i = 1; i < n; i++)
    {
        if (i * i == n)
            return 1;
        if (i * i > n)
            break;
        int curr = minCountMem_helper(n - i * i, dp) + 1;
        ans = min(ans, curr);
    }

    return dp[n] = ans;
}

int minCountMem(int n)
{
    vector<int> dp(n + 1, -1);
    return minCountMem_helper(n, dp);
}

int minCountDp(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        int curr = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            curr = min(curr, 1 + dp[i - j * j]);
        }
        dp[i] = curr;
    }

    return dp[n];
}

int main()
{
    cout << minCountDp(12) << endl;
}