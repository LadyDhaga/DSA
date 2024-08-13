#include "../Trie.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{

    // add all the suffixes of the input words to the trie, in this way you will be able to search of any pattern
    int n;
    cin >> n;

    Trie t;

    for (int i = 0; i < n; i++)
    {

        string s;
        cin >> s;

        string temp;

        for (int j = 0; j < s.size(); j++)
        {
            temp = s;

            t.insertWord(temp.substr(j));
        }
    }

    string pattern;
    cin >> pattern;
    cout << "\n"
         << t.searchWord(pattern) << "\n";
}
