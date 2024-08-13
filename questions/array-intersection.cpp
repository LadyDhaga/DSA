#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {

        int s1;
        cin >> s1;
        vector<int> vec1(s1);
        unordered_set<int> set1;
        for (int i = 0; i < s1; i++)
        {
            int p;
            cin >> p;
            vec1[i] = p;
            set1.insert(p);
        }

        int s2;
        cin >> s2;
        vector<int> ans;
        for (int i = 0; i < s2; i++)
        {
            int s;
            cin >> s;
            if (set1.count(s))
                ans.push_back(s);
        }

        cout << endl;
        for (auto i : ans)
        {
            cout << i;
        }
        cout << endl;
        cout << endl;
    }
}