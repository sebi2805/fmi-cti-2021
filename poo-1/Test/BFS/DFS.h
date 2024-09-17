#include <iostream>
#include <stack>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node
{
    int sum;
    bool visited = false;
    int key;
    Node *left, *father, *right;
};
Node *addNode(int key)
{
    Node *temp = new Node;
    temp->key = key;

    temp->left = temp->right = NULL;
    return temp;
};
void computeSums(Node *root)
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr)
    {

        root->sum = root->key;
        return;
    }
    else if (root->left == nullptr)
    {
        computeSums(root->right);
        root->sum = root->key + root->right->sum;
        return;
    }
    else if (root->right == nullptr)
    {
        computeSums(root->left);
        root->sum = root->key + root->left->sum;
        return;
    }
    else
    {
        computeSums(root->left);
        computeSums(root->right);

        root->sum = root->key + root->left->sum + root->right->sum;
        return;
    }
}
void BFS(Node *root)
{
    queue<Node *> temp;
    temp.push(root);
    while (temp.empty() == false)
    {
        cout << temp.front()->key << " ";
        if (temp.front()->left != nullptr)
            temp.push(temp.front()->left);
        if (temp.front()->right != nullptr)
            temp.push(temp.front()->right);
        temp.pop();
    }
}
void DFS(Node *root)
{
    cout << root->key << " ";
    if (root->left != nullptr && root->left->visited == false)
    {
        root->left->visited = true;
        DFS(root->left);
        cout << root->key << " ";
    }
    if (root->right != nullptr && root->right->visited == false)
    {
        root->right->visited = true;
        DFS(root->right);
        cout << root->key << " ";
    }
    if (root->left == nullptr && root->right == nullptr)
        return;
}
int main()
{
    Node *roote = addNode(1);
    roote->left = addNode(2);
    roote->right = addNode(3);
    roote->left->left = addNode(4);
    roote->left->right = addNode(5);
    // computeSums(roote);
    DFS(roote);
}