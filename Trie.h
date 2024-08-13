#include "TrieNode.h"
#include <bits/stdc++.h>
using namespace std;

class Trie
{
    TrieNode *root;

public:
    Trie()
    {
        root = new TrieNode('\0');
    };

    void insertWord(TrieNode *root, string word)
    {
        // base case
        if (word.size() == 0)
        {
            root->isTerminal = true;
            return;
        }

        // small calculation
        int index = word[0] - 'a';
        TrieNode *child;
        if (root->Children[index] != nullptr)
        {
            child = root->Children[index];
        }
        else
        {
            child = new TrieNode(word[0]);
            root->Children[index] = child;
        }

        // recursive call
        insertWord(child, word.substr(1));
        return;
    }

    // for user
    void insertWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return insertWord(root, word);
    }

    bool searchWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            return root->isTerminal;
        }

        int index = word[0] - 'a';
        if (root->Children[index] == nullptr)
        {
            return false;
        }

        return searchWord(root->Children[index], word.substr(1));
    }

    bool searchWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return searchWord(root, word);
    }

    void removeWord(TrieNode *root, string word)
    {
        if (word.size() == 0)
        {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child = root->Children[index];
        if (child == nullptr)
        {
            return;
        }
        removeWord(child, word.substr(1));
        if (!child->isTerminal)
        {
            for (int i = 0; i < 26; i++)
            {
                if (child->Children[i] != nullptr) // checking if all the children of the child are null
                {
                    return;
                }
            }
            delete child;
            root->Children[index] = nullptr;
        }
        return;
    }

    void removeWord(string word)
    {
        transform(word.begin(), word.end(), word.begin(), ::tolower);
        return removeWord(root, word);
    }
};
