#include <bits/stdc++.h>
using namespace std;

int minSteps_helper(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int a = minSteps_helper(n - 1, dp);
    int c = 0, b = 0;
    if (n - 2 >= 0)
        b = minSteps_helper(n - 2, dp);
    if (n - 3 >= 0)
        c = minSteps_helper(n - 3, dp);

    return dp[n] = a + b + c;
}

int minSteps(int n)
{
    vector<int> dp(n + 1, -1);
    return minSteps_helper(n, dp);
}

int minStepsDp(int n)
{
    if (n <= 1)
        return 1;

    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    int i = 3;

    while (i != n + 1)
    {
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        i++;
    }
    return dp[n];
}

int main()
{
    cout << minStepsDp(10) << endl;
}