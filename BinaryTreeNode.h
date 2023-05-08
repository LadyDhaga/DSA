template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode *khabba;
    BinaryTreeNode *sajja;
    BinaryTreeNode(T data)
    {
        this->data = data;
        this->khabba = NULL;
        this->sajja = NULL;
    }
    ~BinaryTreeNode()
    {
        delete khabba;
        delete sajja;
    }
};
