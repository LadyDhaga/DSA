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

int height(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return 0;
    return 1 + max(height(jadd->khabba), height(jadd->sajja));
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
    return abs(height(root->khabba) - height(root->sajja)) <= 1 ? true : false;
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
    if (root->data == k)
    {
        return root;
    }
    if (root->data == l)
    {
        return root;
    }
    auto a = LCA(root->khabba, k, l);
    auto b = LCA(root->sajja, k, l);
    if (!a)
        return b;
    if (!b)
        return a;
    return root;
}

int largestBST(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
        return 0;
    if (validBST(jadd))
        return height(jadd);
    return max(largestBST(jadd->khabba), largestBST(jadd->sajja));
}

class myClass
{
public:
    int min;
    int max;
    bool isBst;
    int height;

    myClass()
    {
        this->min = INT_MAX;
        this->max = INT_MIN;
        this->isBst = true;
        this->height = 0;
    }
};

myClass largestBstGood(BinaryTreeNode<int> *jadd)
{
    if (!jadd)
    {
        myClass newClass;
        newClass.height = 0;
        newClass.isBst = true;
        newClass.max = INT_MIN;
        newClass.min = INT_MAX;
        return newClass;
    }
    myClass leftAns = largestBstGood(jadd->khabba);
    myClass rightAns = largestBstGood(jadd->sajja);
    myClass obj;
    if (leftAns.isBst && rightAns.isBst)
    {
        if (jadd->data > leftAns.max && jadd->data < rightAns.min)
        {
            obj.height = 1 + max(leftAns.height, rightAns.height);
        }
    }
    obj.height = max(leftAns.height, rightAns.height);
    obj.isBst = false;
    obj.max = max(jadd->data, max(leftAns.max, rightAns.max));
    obj.min = min(jadd->data, min(leftAns.min, rightAns.min));
    return obj;
}

void pathSumToLeaf(BinaryTreeNode<int> *jadd, vector<vector<int>> &v, vector<int> &p, int &k, int ans = 0)
{
    if (!jadd)
        return;
    ans += jadd->data;
    if (!jadd->khabba && !jadd->sajja)
    {
        if (ans == k)
        {
            p.push_back(jadd->data);
            v.push_back(p);
            return;
        }
    }
    p.push_back(jadd->data);
    int j = p.size();
    pathSumToLeaf(jadd->khabba, v, p, k, ans);
    if (j < p.size())
    {
        int m = p.size() - j;
        while (m--)
            p.pop_back();
    }
    pathSumToLeaf(jadd->sajja, v, p, k, ans);
    return;
}

pair<bool, int> finderLc(BinaryTreeNode<int> *root, int k)
{
    if (!root)
    {
        auto k = make_pair(false, 0);
        return k;
    }
    if (root->data == k)
    {
        auto j = make_pair(true, 0);
        return j;
    }
    auto m = finderLc(root->khabba, k);
    if (m.first)
    {
        return make_pair(true, 1 + m.second);
    }
    auto n = finderLc(root->sajja, k);
    if (n.first)
    {
        return make_pair(true, 1 + n.second);
    }
    return make_pair(false, 0);
}
vector<int> distanceK(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target, int k)
{
    // to use
    // auto jadd = takeInputLevel();
    // int x, y;
    // cin >> x;
    // cin >> y;
    // cout << endl;
    // vector<int> v = distanceK(jadd, finder(jadd, x), y);
    // for (auto i : v)
    // {
    //     cout << i << " ";
    // }
    if (!root)
        return {};
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> umap;
    queue<BinaryTreeNode<int> *> bus;
    bus.push(root);
    while (!bus.empty())
    {
        auto front = bus.front();
        bus.pop();
        if (front->khabba)
        {
            umap[front->khabba] = front;
            bus.push(front->khabba);
        }
        if (front->sajja)
        {
            umap[front->sajja] = front;
            bus.push(front->sajja);
        }
    }
    vector<int> result;
    unordered_set<BinaryTreeNode<int> *> visited;
    visited.insert(target);
    int dist = 0;
    bus.push(target);
    while (!bus.empty())
    {
        int levelSize = bus.size();
        if (dist++ == k)
        {
            while (!bus.empty())
            {
                auto front = bus.front();
                bus.pop();
                result.push_back(front->data);
            }
            return result;
        }
        while (levelSize--)
        {
            auto front = bus.front();
            bus.pop();
            if (front->khabba && visited.find(front->khabba) == visited.end())
            {
                bus.push(front->khabba);
                visited.insert(front->khabba);
            }
            if (front->sajja && visited.find(front->sajja) == visited.end())
            {
                bus.push(front->sajja);
                visited.insert(front->sajja);
            }
            if (umap.find(front) != umap.end() && visited.find(umap[front]) == visited.end())
            {
                bus.push(umap[front]);
                visited.insert(umap[front]);
            }
        }
    }
    return result;
}

int main()
{
    auto jadd = takeInputLevel();
    int x;
    cin >> x;
    pairSumBinaryTree_withHashmap(jadd, x);
}