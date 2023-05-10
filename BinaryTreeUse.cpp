#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
using namespace std;

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

BinaryTreeNode<int> *takeInput()
{
    int jaddData;
    cout << "Enter Data" << endl;
    cin >> jaddData;
    if (jaddData == -1)
    {
        return NULL;
    }
    BinaryTreeNode<int> *jadd = new BinaryTreeNode<int>(jaddData);
    BinaryTreeNode<int> *khabbaBacha = takeInput();
    BinaryTreeNode<int> *sajjaBacha = takeInput();
    jadd->khabba = khabbaBacha;
    jadd->sajja = sajjaBacha;
    return jadd;
}

BinaryTreeNode<int> *takeInputLevel()
{
    int num;
    cin >> num;
    BinaryTreeNode<int> *jadd = new BinaryTreeNode<int>(num);
    queue<BinaryTreeNode<int> *> bus;
    bus.push(jadd);
    while (!bus.empty())
    {
        auto front = bus.front();
        bus.pop();
        int x;
        cin >> x;
        if (x != -1)
        {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(x);
            front->khabba = newNode;
            bus.push(newNode);
        }
        else
            front->khabba = NULL;
        int y;
        cin >> y;
        if (y != -1)
        {
            BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(y);
            front->sajja = node1;
            bus.push(node1);
        }
        else
            front->sajja = NULL;
    }
    return jadd;
}

void printTreeLevel(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return;
    queue<BinaryTreeNode<int> *> bus;
    bus.push(jadd);
    while (bus.size() != 0)
    {
        auto front = bus.front();
        bus.pop();
        cout << front->data << ":";
        if (front->khabba != NULL)
        {
            cout << "L" << front->khabba->data;
            bus.push(front->khabba);
        }
        if (front->sajja != NULL)
        {
            cout << "R" << front->sajja->data;
            bus.push(front->sajja);
        }
        cout << endl;
    }
}

int nodeFrequency(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return 0;
    return 1 + nodeFrequency(jadd->khabba) + nodeFrequency(jadd->sajja);
}

bool xPresentOrNot(BinaryTreeNode<int> *jadd, int x)
{
    if (!jadd)
        return 0;
    if (jadd->data == x)
        return true;
    return xPresentOrNot(jadd->khabba, x) || xPresentOrNot(jadd->sajja, x);
}

int binaryheight(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return 0;
    return 1 + max(binaryheight(jadd->khabba), binaryheight(jadd->sajja));
}

void mirrorTree(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return;
    auto temp = jadd->khabba;
    jadd->khabba = jadd->sajja;
    jadd->sajja = temp;
    mirrorTree(jadd->khabba);
    mirrorTree(jadd->sajja);
}

void preOrder(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return;
    cout << jadd->data << " ";
    preOrder(jadd->khabba);
    preOrder(jadd->sajja);
}

void postOrder(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return;
    postOrder(jadd->khabba);
    postOrder(jadd->sajja);
    cout << jadd->data << " ";
}

void inOrder(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return;
    inOrder(jadd->khabba);
    cout << jadd->data << " ";
    inOrder(jadd->sajja);
}

// constructing tree
BinaryTreeNode<int> *constructFromPreorderInorder()
{
    int n;
    cin >> n;
    return NULL;
}

int main()
{
    // BinaryTreeNode<int> *jadd = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // jadd->khabba = node1;
    // jadd->sajja = node2;
    BinaryTreeNode<int> *jadd = takeInputLevel();
    printTreeLevel(jadd);
    cout << endl;
    // cout << nodeFrequency(jadd);
    // cout << xPresentOrNot(jadd, 4);
    // cout << binaryheight(jadd);
    // mirrorTree(jadd);
    cout << "preOrder: ";
    preOrder(jadd);
    // postOrder(jadd);
    cout << endl;
    cout << "inOrder: ";
    inOrder(jadd);

    delete jadd;
}