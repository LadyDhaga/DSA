#include "Trie.h"
using namespace std;

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");
    cout << t.searchWord("and") << "\n";
    t.removeWord("and");
    cout << t.searchWord("and") << "\n";
    t.insertWord("And");
    cout << t.searchWord("And") << "\n";
}