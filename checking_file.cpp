#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1(4);
    for (int i = 0; i < 4; i++)
    {
        int x;
        cin >> x;
        v1[i] = x;
    }
    for (auto i : v1)
    {
        cout << i << endl;
    }
}