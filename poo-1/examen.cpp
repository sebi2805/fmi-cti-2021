#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;
struct node
{
    int value;
    node *left, *right;
};
typedef node *BinaryTree;
bool isInOrder(const vector<int> &v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
            return false;
    }
    return true;
};
int biggestSearchTree(BinaryTree &T)
{
    if (T == NULL)
        return 0;
    queue<BinaryTree> q;
    q.push(T);
    int max = 0;
    while (!q.empty())
    {
        BinaryTree curr = q.front();
        q.pop();
        vector<int> v;
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
        while (curr != NULL)
        {
            v.push_back(curr->value);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
            curr = curr->left;
        }
        if (isInOrder(v))
        {
            if (v.size() > max)
                max = v.size();
        }
    }
    return max;
}
int longestMonotonicPath(BinaryTree &T)
{

    if (T->left == NULL && T->right == NULL)
        return 1;
    int max = 0, left, right;
    cout << T->value << endl;
    if (T->left != NULL)
    {
        cout << T->left->value << endl;
        if (T->left->value > T->value)
        {
            left = longestMonotonicPath(T->left);
            if (left > max)
                max = left + 1;
        }
    }
    if (T->right != NULL)
    {
        if (T->right->value > T->value)
        {
            right = longestMonotonicPath(T->right);
            if (right > max)
                max = right + 1;
        }
    }

    return max;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<int> prod;
    prod.push_back(1);
    for (int i = 1; i < v.size(); i++)
    {
        prod.push_back(v[i] * prod[i - 1]);
    }
    for (auto i : prod)
        cout << i << " ";
    while (1)
    {
        int i, j;
        cin >> i >> j;
        cout << endl
             << prod[j] / prod[i] * v[i] << endl;
    }
    return 0;
}