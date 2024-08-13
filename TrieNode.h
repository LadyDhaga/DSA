class TrieNode
{
public:
    char data;
    TrieNode **Children;
    bool isTerminal;
    TrieNode(char data)
    {
        this->data = data;
        Children = new TrieNode *[26];
        for (int i = 0; i < 26; i++)
        {
            Children[i] = nullptr;
        }
        isTerminal = false;
    }
};