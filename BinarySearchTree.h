#include "BinaryTreeNode.h"
#include <queue>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
class BST
{
private:
    BinaryTreeNode<int> *root;

    bool hasData(int data, BinaryTreeNode<int> *root)
    {
        if (!root)
            return 0;
        if (root->data == data)
            return 1;
        if (data < root->data)
            return hasData(data, root->khabba);
        return hasData(data, root->sajja);
    }

    void insertMine(int data, BinaryTreeNode<int> *root)
    {
        if (!root)
        {
            root = new BinaryTreeNode<int>(data);
            return;
        }
        if (data > root->data)
        {
            if (!root->sajja)
            {
                root->sajja = new BinaryTreeNode<int>(data);
                return;
            }
            insert(data, root->sajja);
            return;
        }
        if (data < root->data)
        {
            if (!root->khabba)
            {
                root->khabba = new BinaryTreeNode<int>(data);
                return;
            }
            insert(data, root->khabba);
            return;
        }
        return;
    }

    BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *node)
    {
        if (!node)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        if (node->data < data)
        {
            node->sajja = insert(data, node->sajja);
            return node;
        }
        node->khabba = insert(data, node->khabba);
        return node;
    }

    void deleteDataMine(int data, BinaryTreeNode<int> *root)
    {
        if (!root)
            return;
        if (root->data == data)
        {
            queue<BinaryTreeNode<int> *> bus;
            bus.push(root);
            vector<int> v;
            while (bus.size())
            {
                int n = bus.size();
                while (n--)
                {
                    auto front = bus.front();
                    v.emplace_back(front->data);
                    bus.pop();
                    if (front->khabba)
                        bus.push(front->khabba);
                    if (front->sajja)
                        bus.push(front->sajja);
                }
            }
            root = NULL;
            for (auto i : v)
            {
                insert(i);
            }
            return;
        }
        if (data > root->data)
        {
            deleteData(data, root->sajja);
            return;
        }
        deleteData(data, root->khabba);
    }

    BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *node)
    {
        if (!node)
            return NULL;
        if (node->data == data)
        {
            if (!node->khabba && !node->sajja)
            {
                delete node;
                return NULL;
            }
            if (node->khabba)
            {
                auto newNode = node->khabba;
                node->khabba = NULL;
                delete node;
                return newNode;
            }
            if (node->sajja)
            {
                auto newNode = node->sajja;
                node->sajja = NULL;
                delete node;
                return newNode;
            }
            auto temp = node->sajja;
            while (temp->khabba)
            {
                temp = temp->khabba;
            }
            int x = temp->data;
            node->data = x;
            node->sajja = deleteData(x, node->sajja);
        }
        if (node->data < data)
        {
            node->sajja = deleteData(data, node->sajja);
            return node;
        }
        node->khabba = deleteData(data, node->khabba);
        return node;
    }

    void printTree(BinaryTreeNode<int> *jadd)
    {
        if (!jadd)
            return;

        cout << jadd->data << ": ";
        if (jadd->khabba)
        {
            cout << "L" << jadd->khabba->data;
        }
        if (jadd->sajja)
        {
            cout << " R" << jadd->sajja->data;
        }
        cout << endl;
        printTree(jadd->khabba);
        printTree(jadd->sajja);
    }

public:
    void printTree()
    {
        printTree(root);
    }
    bool hasData(int data)
    {
        return hasData(data, root);
    }

    void insert(int data)
    {
        this->root = insert(data, this->root);
    }

    void deleteData(int data)
    {
        this->root = deleteData(data, this->root);
    }

    BST()
    {
        root = nullptr;
    }

    ~BST()
    {
        delete root;
    }

};
