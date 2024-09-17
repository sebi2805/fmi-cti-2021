#include <iostream>
#include <string>
#include <ostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
#include <set>
using namespace std;
class Node
{
public:
    int val, size;
    bool isBST;
    int longestMOnotonicPath;
    Node *left;
    Node *right;
    Node *next;
    Node() : val(0), left(nullptr), right(nullptr), next(nullptr), isBST(false), longestMOnotonicPath(1) {}
    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr), isBST(false), longestMOnotonicPath(1) {}
    Node(int _val, Node *_left, Node *_right, Node *_next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
Node *addNode(int val)
{
    Node *newNode = new Node(val);
    return newNode;
}
void preComputeBST(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        root->isBST = true;
    }
    else if (root->left == NULL)
    {
        preComputeBST(root->right);
        root->isBST = root->right->isBST && root->right->val > root->val;
    }
    else if (root->right == NULL)
    {
        preComputeBST(root->left);
        root->isBST = root->left->isBST && root->left->val < root->val;
    }
    else
    {
        preComputeBST(root->right);
        preComputeBST(root->left);
        root->isBST = root->left->isBST && root->right->isBST && root->left->val < root->val && root->right->val > root->val;
    }
    return;
}

void precomputeSize(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        root->size = 1;
    }
    else if (root->left == NULL)
    {
        precomputeSize(root->right);
        root->size = root->right->size + 1;
    }
    else if (root->right == NULL)
    {
        precomputeSize(root->left);
        root->size = root->left->size + 1;
    }
    else
    {
        precomputeSize(root->left);
        precomputeSize(root->right);
        root->size = root->left->size + root->right->size + 1;
    }
    return;
}

int biggestSearchTree(Node *root)
{
    preComputeBST(root);
    precomputeSize(root);
    if (root == NULL)
        return 0;
    int left = biggestSearchTree(root->left);
    int right = biggestSearchTree(root->right);
    if (root->isBST)
    {
        return root->size;
    }
    else
    {
        cout << left << " " << right << endl;
        return max(left, right);
    }
}

class Sebi
{
    set<int> s;

public:
    void add(int i)
    {
        s.insert(i);
    }
    int size()
    {
        return s.size();
    }
    int max()
    {
        return *s.rbegin();
    }
    int min()
    {
        return *s.begin();
    }
    void deleteX(int i)
    {
        s.erase(s.find(i));
    }
};

void longestMonotonicPath(Node *root)
{
    cout << root->val;
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
        if (root->val <= root->left->val && root->val <= root->right->val)
        {
            longestMonotonicPath(root->left);
            longestMonotonicPath(root->right);
            root->longestMOnotonicPath = max(root->left != nullptr
                                                 ? root->left->longestMOnotonicPath
                                                 : 0,
                                             root->right != nullptr ? root->right->longestMOnotonicPath : 0) +
                                         1;
        }

        else if (root->val <= root->left->val)
        {
            longestMonotonicPath(root->left);

            root->longestMOnotonicPath = root->left != nullptr ? root->left->longestMOnotonicPath + 1 : 1;
        }
        else if (root->val <= root->right->val)
        {
            longestMonotonicPath(root->right);
            root->longestMOnotonicPath = root->right != nullptr ? root->right->longestMOnotonicPath + 1 : 1;
        }

        else
        {
            cout << "here" << root->val << endl;
            if (root->left != nullptr && root->right != nullptr)
            {
                longestMonotonicPath(root->right);
                longestMonotonicPath(root->left);
            }
            root->longestMOnotonicPath = 1;
        }
}

int maxlongestMonotonicPath(Node *root)
{
    if (root == NULL)
        return 0;

    if (root->left == NULL && root->right == NULL)
        return 0;
    else if (root->left != nullptr)
    {

        int left = maxlongestMonotonicPath(root->left);
        return max(left, root->longestMOnotonicPath);
    }
    else if (root->right != nullptr)
    {
        int right = maxlongestMonotonicPath(root->right);
        return max(right, root->longestMOnotonicPath);
    }
    else
    {
        int left = maxlongestMonotonicPath(root->left);
        int right = maxlongestMonotonicPath(root->right);
        return max(max(left, right), root->longestMOnotonicPath);
    }
}

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;
struct node
{
    int value;
    node *left;
    node *right;
};

bool isMinHeapUtil(node *root)
{
    if (root == nullptr)
        return true;
    if (root->left == nullptr && root->right == nullptr)
        return true;

    if (root->left == nullptr)
        return (root->value <= root->right->value) && isMinHeapUtil(root->right);
    if (root->right == nullptr)
        return (root->value <= root->left->value) && isMinHeapUtil(root->left);

    return (root->value <= root->left->value) && (root->value <= root->right->value) && isMinHeapUtil(root->left) && isMinHeapUtil(root->right);
}

bool isMinHeap(node *root)
{
    return isMinHeapUtil(root);
}

// 1a

int biggestMinHeap(node *root)
{
    if (root == nullptr)
        return 0;

    int left = biggestMinHeap(root->left);
    int right = biggestMinHeap(root->right);

    if (root->left != nullptr && root->value > root->left->value)
        return max(left, right);
    if (root->right != nullptr && root->value > root->right->value)
        return max(left, right);

    return 1 + left + right;
}
// 1b

bool biggestMinBinaryHeap(node *root, int &maxSize)
{
    if (root == nullptr)
        return true;

    bool leftIsMinHeap = biggestMinBinaryHeap(root->left, maxSize);
    bool rightIsMinHeap = biggestMinBinaryHeap(root->right, maxSize);

    if (!leftIsMinHeap || !rightIsMinHeap)
        return false;

    int leftSize = 0;
    int rightSize = 0;
    if (root->left != nullptr)
    {
        if (root->value > root->left->value)
            return false;
        leftSize = 1 + biggestMinBinaryHeap(root->left->left, maxSize) + biggestMinBinaryHeap(root->left->right, maxSize);
    }
    if (root->right != nullptr)
    {
        if (root->value > root->right->value)
            return false;
        rightSize = 1 + biggestMinBinaryHeap(root->right->left, maxSize) + biggestMinBinaryHeap(root->right->right, maxSize);
    }

    int size = 1 + leftSize + rightSize;
    if (size > maxSize)
        maxSize = size;
    return size == (1 << int(log2(size) + 1)) - 1;
}

int biggestMinBinaryHeap(node *root)
{
    int maxSize = 0;
    biggestMinBinaryHeap(root, maxSize);
    return maxSize;
}
// 1c

bool isBoth(node *root, int minValue, int maxValue)
{
    if (root == nullptr)
        return true;

    if (root->value < minValue || root->value > maxValue)
        return false;

    bool leftIsValid = isBoth(root->left, minValue, root->value);
    bool rightIsValid = isBoth(root->right, root->value, maxValue);

    return leftIsValid && rightIsValid;
}

bool isBoth(node *root)
{
    return false; // deoarece un min heap nu poate fi bst
}

// 1d
#include <vector>
int main()
{
    node *root = new node{10, nullptr, nullptr};
    root->left = new node{5, nullptr, nullptr};
    root->right = new node{15, nullptr, nullptr};
    root->left->left = new node{1, nullptr, nullptr};
    root->left->right = new node{7, nullptr, nullptr};
    root->right->left = new node{12, nullptr, nullptr};
    root->right->right = new node{20, nullptr, nullptr};

    if (isBoth(root))
    {
        std::cout << "The binary tree is both a min-heap and a binary search tree." << std::endl;
    }
    else
    {
        std::cout << "The binary tree is not both a min-heap and a binary search tree." << std::endl;
    }

    vector<int> sebi = {1, 2, 3};
    return 0;
}
struct Node
{
    int val;
}