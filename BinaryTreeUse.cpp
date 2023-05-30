#include <iostream>
#include <queue>
#include "BinaryTreeNode.h"
#include <bits/stdc++.h>
#include <unordered_map>
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

// simplifying function

BinaryTreeNode<int> *majdoorFunction(vector<int> pre, vector<int> ino, int ins, int ine, int ps, int pe)
{
    if (ins > ine || ps > pe)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(pre[ps]);
    int rootIndex = -1;
    for (int i = ins; i <= ine; i++)
    {
        if (ino[i] == pre[ps])
        {
            rootIndex = i;
            break;
        }
    }
    int linS = ins;
    int linE = rootIndex - 1;
    int lprS = ps + 1;
    int lprE = linE - linS + lprS;
    int rinS = rootIndex + 1;
    int rinE = ine;
    int rprS = lprE + 1;
    int rprE = pe;
    root->khabba = majdoorFunction(pre, ino, linS, linE, lprS, lprE);
    root->sajja = majdoorFunction(pre, ino, rinS, rinE, rprS, rprE);
    return root;
}

BinaryTreeNode<int> *majboorfunction(vector<int> inorder, vector<int> postorder, int ins, int ine, int ps, int pe, unordered_map<int, int> umap)
{
    if (ins > ine || ps > pe)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[pe]);
    int rootIndex = umap[postorder[pe]];
    int rinS = rootIndex + 1;
    int rinE = ine;
    int rpE = pe - 1;
    int rpS = rpE - rinE + rinS;
    int linS = ins;
    int linE = rootIndex - 1;
    int lpS = ps;
    int lpE = rpS - 1;
    root->khabba = majboorfunction(inorder, postorder, linS, linE, lpS, lpE, umap);
    root->sajja = majboorfunction(inorder, postorder, rinS, rinE, rpS, rpE, umap);
    return root;
}

BinaryTreeNode<int> *constructFromPreorderInorder()
{
    int n;
    cin >> n;
    vector<int> inOrder(n);
    vector<int> preOrder(n);
    for (int i = 0; i < n; i++)
    {
        cin >> inOrder[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> preOrder[i];
    }
    BinaryTreeNode<int> *root = majdoorFunction(preOrder, inOrder, 0, inOrder.size() - 1, 0, preOrder.size() - 1);
    return root;
}
BinaryTreeNode<int> *constructFromPostorderInorder()
{
    int n;
    cin >> n;
    unordered_map<int, int> umap;
    vector<int> inorder(n);
    vector<int> postorder(n);
    for (int i = 0; i < n; i++)
        cin >> postorder[i];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        umap[inorder[i]] = i;
    }
    BinaryTreeNode<int> *root = majboorfunction(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1, umap);
    return root;
}

pair<int, int> minmax(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        return make_pair(INT_MIN, INT_MAX);
    }
    auto p1 = minmax(root->khabba);
    auto p2 = minmax(root->sajja);
    auto p3 = make_pair(max(root->data, max(p1.first, p2.first)), min(root->data, min(p1.second, p2.second)));
    return p3;
}

pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (!root)
        return make_pair(0, 0);
    auto p1 = heightDiameter(root->khabba);
    auto p2 = heightDiameter(root->sajja);
    return make_pair(1 + max(p1.first, p2.first), max(p1.first + p2.first, max(p1.second, p2.second)));
}

bool balanced(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return abs(binaryheight(root->khabba) - binaryheight(root->sajja)) <= 1 ? true : false;
}

int main()
{
    // BinaryTreeNode<int> *jadd = new BinaryTreeNode<int>(1);
    // BinaryTreeNode<int> *node1 = new BinaryTreeNode<int>(2);
    // BinaryTreeNode<int> *node2 = new BinaryTreeNode<int>(3);
    // jadd->khabba = node1;
    // jadd->sajja = node2;
    // BinaryTreeNode<int> *jadd = takeInputLevel();
    // printTreeLevel(jadd);
    // cout << endl;
    // cout << nodeFrequency(jadd);
    // cout << xPresentOrNot(jadd, 4);
    // cout << binaryheight(jadd);
    // mirrorTree(jadd);
    // cout << "preOrder: ";
    // preOrder(jadd);
    // // postOrder(jadd);
    // cout << endl;
    // cout << "inOrder: ";
    // inOrder(jadd);

    // BinaryTreeNode<int> *jadd = constructFromPostorderInorder();
    // cout << endl;
    // cout << "Maximum: " << minmax(jadd).first << endl;
    // cout << "Minimum: " << minmax(jadd).second << endl;
    // auto p1 = heightDiameter(jadd);
    // printTreeLevel(jadd);
    // cout << endl;
    // cout << p1.first;
    // cout << endl;
    // cout << p1.second;
    // cout << balanced(jadd) << endl;
    BinaryTreeNode<int> *jadd = takeInputLevel();
    // 1 2 3 -1 -1 -1 -1
    delete jadd;
}