#include <bits/stdc++.h>
using namespace std;

int reduceToOne(int n)
{
    if (n == 1)
        return 0;

    int a = reduceToOne(n - 1);
    int b = INT_MAX;
    int c = INT_MAX;
    if (n % 2 == 0)
        b = reduceToOne(n / 2);
    else if (n % 3 == 0)
        c = reduceToOne(n / 3);

    return 1 + min({a, b, c});
}

int reduceToOneMem_helper(int n, vector<int> &dp)
{
    if (n <= 1)
        return 1;

    if (dp[n] != -1)
        return dp[n];

    int a = reduceToOne(n - 1);
    int b = INT_MAX;
    int c = INT_MAX;
    if (n % 2 == 0)
        b = reduceToOne(n / 2);
    else if (n % 3 == 0)
        c = reduceToOne(n / 3);

    return dp[n] = 1 + min({a, b, c});
}

int reduceToOneMem(int n)
{
    vector<int> dp(n + 1, -1);
    return reduceToOneMem_helper(n, dp);
}

int reduceToOneDp(int n)
{
    if (n <= 1)
        return 1;

    vector<int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    int i = 3;

    while (i != n + 1)
    {
        int a = dp[i - 1];
        int b = INT_MAX;
        int c = INT_MAX;
        if (i % 2 == 0)
            b = dp[i / 2];
        if (i % 3 == 0)
            c = dp[i / 3];
        dp[i] = 1 + min({a, b, c});
        i++;
    }

    return dp[n];
}

int main()
{
    cout << reduceToOneDp(10) << endl;
}