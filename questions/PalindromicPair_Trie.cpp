#include "../Trie.h"
#include <bits/stdc++.h>
using namespace std;

bool checKPalindrome(string &s)
{
    int n = s.size();

    if (n <= 1)
        return true;

    for (int i = 0; i < n; i++)
    {
        if (s[i] != s[n - i - 1])
        {
            return false;
        }
    }

    return true;
}

int main()
{

    int n;
    cin >> n;

    Trie t;
    bool flag = true;

    for (int i = 0; i < n; i++)
    {

        string s;
        cin >> s;

        t.insertWord(s);
        reverse(s.begin(), s.end());

        if (t.searchWord(s))
        {
            cout << "True" << "\n";
            flag = false;

            break;
        }
    }

    if (flag)
        cout << "False" << "\n";
}