#include "BinarySearchTree.h"
#include <iostream>
#include <queue>
// #include "BinaryTreeNode.h"
#include <bits/stdc++.h>
#include "ListNode.cpp"
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
bool leafornot(BinaryTreeNode<int> *root)
{
    if (!root)
        return 0;
    return !root->khabba && !root->sajja;
}
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (!root)
        return NULL;
    if (leafornot(root->khabba))
        root->khabba = NULL;
    if (leafornot(root->sajja))
        root->sajja = NULL;
}

bool search(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return 0;
    if (root->data == k)
        return true;
    if (root->data < k)
        return search(root->sajja, k);
    return search(root->khabba, k);
}

void inRange(BinaryTreeNode<int> *root, vector<int> &v, int r1, int r2)
{
    if (!root)
        return;
    if (root->data < r1)
    {
        // v.push_back(root->data);
        inRange(root->sajja, v, r1, r2);
        return;
    }
    if (root->data > r2)
    {
        // v.push_back(root->data);
        inRange(root->khabba, v, r1, r2);
        return;
    }
    inRange(root->khabba, v, r1, r2);
    v.emplace_back(root->data);
    inRange(root->sajja, v, r1, r2);
    return;
}

int maximum(BinaryTreeNode<int> *root)
{
    if (!root)
        return INT_MIN;
    return max(root->data, max(maximum(root->khabba), maximum(root->sajja)));
}
int minimum(BinaryTreeNode<int> *root)
{
    if (!root)
        return INT_MAX;
    return min(root->data, min(minimum(root->khabba), minimum(root->sajja)));
}

bool validBST(BinaryTreeNode<int> *root)
{
    if (!root)
        return true;
    auto l = maximum(root->khabba);
    auto m = minimum(root->sajja);
    bool output = (root->data > l) && (root->data <= m) && (validBST(root->khabba)) && (validBST(root->sajja));
    return output;
}
pair<bool, pair<int, int>> isBST(BinaryTreeNode<int> *root)
{
    if (!root)
    {
        auto p = make_pair(true, make_pair(INT_MIN, INT_MAX));
        return p;
    }
    auto p = isBST(root->khabba);
    auto q = isBST(root->sajja);
    bool n = p.first && q.first && (root->data > p.second.first) && (root->data <= q.second.second);
    auto m = make_pair(n, make_pair(max(root->data, max(p.second.first, q.second.first)), min(root->data, min(p.second.second, q.second.second))));
    return m;
}

BinaryTreeNode<int> *constructBstFromSortedArray(vector<int> &v, int m, int n)
{
    if (m > n)
        return NULL;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(v[(m + n) / 2]);
    root->khabba = constructBstFromSortedArray(v, m, ((m + n) / 2) - 1);
    root->sajja = constructBstFromSortedArray(v, (m + n) / 2 + 1, n);
    return root;
}

void levelLinkedListHelper(queue<BinaryTreeNode<int> *> &bus, vector<ListNode<int> *> &v)
{
    if (bus.empty())
        return;
    auto front = bus.front();
    bus.pop();
    ListNode<int> *head = new ListNode<int>(front->data);
    int n = bus.size();
    while (n--)
    {
        auto newfront = bus.front();
        bus.pop();
        head->next = new ListNode<int>(newfront->data);
        if (newfront->khabba)
            bus.push(newfront->khabba);
        if (newfront->sajja)
            bus.push(newfront->sajja);
    }
    v.push_back(head);
    levelLinkedListHelper(bus, v);
}
vector<ListNode<int> *> levelLinkedList(BinaryTreeNode<int> *root)
{
    if (!root)
        return {};
    queue<BinaryTreeNode<int> *> bus;
    bus.push(root);
    vector<ListNode<int> *> v;
    levelLinkedListHelper(bus, v);
    return v;
}

void noSiblings(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (!root)
        return;
    if (root->khabba && root->sajja)
    {
        noSiblings(root->khabba, v);
        noSiblings(root->sajja, v);
        return;
    }
    if (root->khabba)
    {
        v.emplace_back(root->khabba->data);
        noSiblings(root->khabba, v);
    }
    if (root->sajja)
    {
        v.emplace_back(root->sajja->data);
        noSiblings(root->sajja, v);
    }
    return;
}

void findPathHelper(BinaryTreeNode<int> *root, int k, vector<int> &v)
{
    if (!root)
        return;
    if (root->data < k)
    {
        findPathHelper(root->sajja, k, v);
        v.emplace_back(root->data);
        return;
    }
    if (root->data > k)
    {
        findPathHelper(root->khabba, k, v);
        v.emplace_back(root->data);
        return;
    }
    v.emplace_back(k);
    return;
}

vector<int> findPath(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return {};
    vector<int> v;
    findPathHelper(root, k, v);
    return v;
}

void insertDuplicates(BinaryTreeNode<int> *node)
{
    if (!node)
        return;
    auto newNode = node->khabba;
    auto anotherNode = new BinaryTreeNode<int>(node->data);
    node->khabba = anotherNode;
    anotherNode->khabba = newNode;
    insertDuplicates(newNode);
    insertDuplicates(node->sajja);
    return;
}

void pairSumBinaryTreeHelper(BinaryTreeNode<int> *root, unordered_set<int> &umap, int &s)
{
    if (!root)
        return;
    if (umap.find(s - root->data) != umap.end())
    {
        if (s - root->data >= root->data)
        {
            cout << root->data << " " << s - root->data << endl;
        }
        else
            cout << s - root->data << " " << root->data << endl;
    }
    umap.insert(root->data);
    pairSumBinaryTreeHelper(root->khabba, umap, s);
    pairSumBinaryTreeHelper(root->sajja, umap, s);
    return;
}

BinaryTreeNode<int> *finder(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return NULL;
    if (root->data == k)
        return root;
    auto p = finder(root->khabba, k);
    auto q = finder(root->sajja, k);
    return p ? p : q;
}

bool find(BinaryTreeNode<int> *root, int k)
{
    if (!root)
        return false;
    if (root->data == k)
        return true;
    return find(root->khabba, k) || find(root->sajja, k);
}

void printPairs(BinaryTreeNode<int> *cRoot, int k, BinaryTreeNode<int> *root)
{
    if (!cRoot)
        return;
    printPairs(cRoot->sajja, k, root);
    printPairs(cRoot->khabba, k, root);
    if (cRoot->data != INT_MIN)
    {
        auto newNode = finder(root, k - cRoot->data);
        if (newNode)
        {
            if (cRoot->data < k - cRoot->data)
            {
                cout << cRoot->data << " " << k - cRoot->data << endl;
            }
            else
                cout << k - cRoot->data << " " << cRoot->data << endl;
            newNode->data = INT_MIN;
            return;
        }
        return;
    }
    return;
}

void pairSumBinaryTree_withHashmap(BinaryTreeNode<int> *root, int &s)
{
    if (!root)
        return;
    unordered_set<int> umap;
    umap.insert(root->data);
    pairSumBinaryTreeHelper(root, umap, s);
    return;
}

BinaryTreeNode<int> *LCA(BinaryTreeNode<int> *root, int k, int l)
{
    if (!root)
        return NULL;
    if (find(root->khabba, k) && find(root->khabba, l))
    {
        return LCA(root->khabba, k, l);
    }
    if (find(root->sajja, k) && find(root->sajja, l))
    {
        return LCA(root->sajja, k, l);
    }
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
    // int k;
    // cin >> k;
    // cout << search(jadd, k) << endl;
    // int x, y;
    // cin >> x;
    // cin >> y;
    // vector<int> v;
    // inRange(jadd, v, x, y);
    // 1 2 3 -1 -1 -1 -1
    // 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    // cout << validBST(jadd) << endl;
    // cout << validBST(jadd) << endl;
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> v[i];
    // }
    // BinaryTreeNode<int> *jadd = constructBstFromSortedArray(v, 0, n - 1);
    // noSiblings(jadd, v);
    // cout << endl;
    // int k;
    // cin >> k;
    // vector<int> v = findPath(jadd, k);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    // printTreeLevel(jadd);
    // insertDuplicates(jadd);
    BinaryTreeNode<int> *jadd = takeInputLevel();
    int k;
    cin >> k;
    cout << endl;
    printPairs(jadd, k, jadd);
    // printTree(jadd);
}