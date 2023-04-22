#include <iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int> *takeInputLevelWise()
{
    int rootData;
    // cout << "Enter root data" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    queue<TreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        TreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        // cout << "Enter num of children of" << front->data << endl;
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            // cout << "Enter " << i << "th child of " << front->data << endl;
            TreeNode<int> *child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

TreeNode<int> *takeInput()
{
    int rootData;
    cout << "EnterData" << endl;
    cin >> rootData;
    TreeNode<int> *root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter the number of children of " << rootData << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *child = takeInputLevelWise();
        root->children.push_back(child);
    }
    return root;
}

void printTree(TreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
        printTree(root->children[i]);
}

int numNodes(TreeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += numNodes(root->children[i]);
    }
    return ans;
}

TreeNode<int> *takeInputAndPrintTreeLevelWise()
{
    int x;
    cin >> x;
    queue<TreeNode<int> *> q;
    TreeNode<int> *root = new TreeNode<int>(x);
    q.push(root);
    while (!q.empty())
    {
        int y;
        cin >> y;
        auto temp = q.front();
        q.pop();
        // TreeNode<int> *newNode = new TreeNode<int>(y) ;
        for (int i = 0; i < y; i++)
        {
            int z;
            cin >> z;
            TreeNode<int> *newNode = new TreeNode<int>(z);
            temp->children.push_back(newNode);
            q.push(newNode);
        }
    }
    // printTree(root) ;
    return root;
}

// counting sum of all nodes
int countSum(TreeNode<int> *root)
{
    if (root->children.size() == 0)
        return root->data;
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countSum(root->children[i]);
    }
    return ans;
}

// ndoe with largest data

TreeNode<int> *largestDataNode(TreeNode<int> *root)
{
    if (!root)
        return NULL;
    if (root->children.size() == 0)
        return root;

    auto temp = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        auto curr = largestDataNode(root->children[i]);
        if (curr && temp->data < curr->data)
            temp = curr;
    }
    return temp;
}

// finding height
int height(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        if (height(root->children[i]) >= ans)
            ans += height(root->children[i]);
    }
    return ans;
}

// number of leaf nodes
int countLeaf(TreeNode<int> *root)
{
    if (!root)
        return 0;
    if (root->children.size() == 0)
        return 1;
    int ans = 0;

    for (int i = 0; i < root->children.size(); i++)
    {
        ans += countLeaf(root->children[i]);
    }
    return ans;
}

// data greater than x
int greaterThanX(TreeNode<int> *root, int x)
{
    if (!root)
        return 0;
    int ans = 0;
    if (root->data > x)
        ans++;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += greaterThanX(root->children[i], x);
    }
    return ans;
}

// largest node sum
// helper for nodeWithMaxChildSum
int nodeSum(TreeNode<int> *root)
{
    if (!root)
        return 0;
    int ans = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans += root->children[i]->data;
    }
    return ans;
}

TreeNode<int> *nodeWithMaxChildSum(TreeNode<int> *root)
{
    if (!root)
        return NULL;
    int ans = nodeSum(root);
    auto temp = root;
    for (int i = 0; i < root->children.size(); i++)
    {
        auto temp1 = nodeWithMaxChildSum(root->children[i]);
        if (ans < nodeSum(temp1))
            temp = temp1;
    }
    return temp;
}

// if it contains x
bool containsX(TreeNode<int> *root, int x)
{
    if (!root)
        return 0;
    if (root->data == x)
        return true;
    bool ans = false;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = containsX(root->children[i], x);
    }
    return ans;
}

// if trees are identical or not
bool equalOrNot(TreeNode<int> *root1, TreeNode<int> *root2)
{
    if (!root1)
    {
        if (!root2)
            return true;
        else
            return false;
    }
    if (!root2)
    {
        if (!root1)
            return true;
        else
            return false;
    }
    if (root1->children.size() != root2->children.size())
        return false;
    if (root1->data != root2->data)
        return false;
    for (int i = 0; i < root1->children.size(); i++)
    {
        if (!equalOrNot(root1->children[i], root2->children[i]))
            return false;
    }
    return true;
}

// just greater than int x
TreeNode<int> *justGreaterThanX(TreeNode<int> *root, int x)
{
    if (!root)
        return NULL;
    if (root->children.size() == 0)
    {
        if (root->data > x)
            return root;
        return NULL;
    }
    TreeNode<int> *temp = (root->data > x) ? root : NULL;
    for (int i = 0; i < root->children.size(); i++)
    {
        TreeNode<int> *temp1 = justGreaterThanX(root->children[i], x);
        if (!temp1)
            continue;
        if (!temp || temp1->data < temp->data)
            temp = temp1;
    }
    return temp;
}

// second largest node in tree using queue
void secondLargestElementHelper(TreeNode<int> *root, priority_queue<pair<int, TreeNode<int> *>> &pq)
{
    if (!root)
        return;
    for (int i = 0; i < root->children.size(); i++)
    {
        auto x = root->children[i];
        auto y = x->data;
        pq.push(make_pair(y, x));
        secondLargestElementHelper(root->children[i], pq);
    }
    return;
}
TreeNode<int> *secondLargestElement(TreeNode<int> *root)
{
    priority_queue<pair<int, TreeNode<int> *>> pq; // using extra space
    secondLargestElementHelper(root, pq);
    pq.pop();
    auto y = pq.top();
    return y.second;
}
// second largest without priority queue
TreeNode<int> *secondLargestElementBestApproach(TreeNode<int> *r)
{
}

// main
int main()
{
    // TreeNode<int> *root = new TreeNode<int>(1);
    // TreeNode<int> *node1 = new TreeNode<int>(2);
    // TreeNode<int> *ndoe2 = new TreeNode<int>(3);
    // root->children.push_back(node1);
    // root->children.push_back(ndoe2);
    // printTree(root);
    // TreeNode<int> *root = takeInputLevelWise();
    // printTree(root);
    // cout << numNodes(root) << endl;
    auto root = takeInputAndPrintTreeLevelWise();
    cout << secondLargestElement(root)->data << endl;
}