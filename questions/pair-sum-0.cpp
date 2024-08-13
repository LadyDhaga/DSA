#include <Bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_set<int> s;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        if (s.count(-1 * v[i]))
            ans++;
        s.insert(v[i]);
    }
    cout << endl;
    cout << ans;
}