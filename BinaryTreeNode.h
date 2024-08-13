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
        this->khabba = nullptr;
        this->sajja = nullptr;
    }
    ~BinaryTreeNode()
    {
        delete khabba;
        delete sajja;
    }
};
