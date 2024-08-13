#include <bits/stdc++.h>
using namespace std;

int helper(int n, vector<int> &dp)
{
    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    int a = helper(n - 1, dp);
    int b = helper(n - 2, dp);

    return dp[n] = a * a + 2 * a * b;
}

int balancedBT(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;
    return helper(n, dp);
}

int main()
{
    cout << balancedBT(4) << endl;
}