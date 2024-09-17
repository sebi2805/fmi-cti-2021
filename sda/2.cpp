#include <iostream>
#include <vector>

using namespace std;

typedef struct BinaryTree {
    int value;
    struct BinaryTree *tata;
    struct BinaryTree *stanga;
    struct BinaryTree *dreapta;
} BinaryTree;

BinaryTree* addNode(int data)
{
    BinaryTree* node = new BinaryTree;
    node->value = data;
    node->stanga = NULL;
    node->dreapta = NULL;

    return (node);
}

void constructVector(BinaryTree* T, vector<BinaryTree*>& sol)
{
    if (T == NULL)
        return;
    sol.push_back(T);
    constructVector(T->stanga, sol);
    constructVector(T->dreapta, sol);
}

bool isBalanced(BinaryTree *T, int &height)
{
    int leftheight = 0, rightheight = 0;
    bool leftbalanced = 0;
    bool rightbalanced = 0;
    if (T == NULL) {
        height = 0;
        return 1;
    }
    leftbalanced = isBalanced(T->stanga, leftheight);
    rightbalanced = isBalanced(T->dreapta, rightheight);
    /// o solutie mai optima ar fi fost sa am calculata inaltimea
    /// la adaugarea urmatorului nod, fara sa mai fiu nevoit sa mai calculez
    /// eu recursiv pentru fiecare.
    height = (leftheight > rightheight ? leftheight : rightheight) + 1;
    if (abs(leftheight - rightheight) >= 2)
        return 0;
    else
        return leftbalanced && rightbalanced;
}

vector<bool> balancedSubtree(BinaryTree *T){
    vector<bool> bal;
    vector<BinaryTree*> listOfNodes;
    constructVector(T, listOfNodes);
    for(auto elem : listOfNodes){
        int height = 0;
        bal.push_back(isBalanced(elem,height));
    }
    return bal;
}

int sumOfInterval(BinaryTree *T, int x, int y, vector<bool>& bal){

    vector<BinaryTree*> sol;
    constructVector(T, sol);
    int nr = 0;
    for(int i = 0 ; i < sol.size() ; i++)
        if(bal[i] == true && sol[i]->value > x && sol[i]->value < y)
            nr++;
    return nr;
}

int main(){
    BinaryTree* root = addNode(1);
    root->stanga = addNode(2);
    root->dreapta = addNode(3);
    root->stanga->stanga = addNode(4);
    root->stanga->dreapta = addNode(5);
    root->dreapta->stanga = addNode(6);
    root->stanga->stanga->stanga = addNode(7);
    vector<bool> bal = balancedSubtree(root);
    cout << sumOfInterval(root, 1,4, bal);
    return 0;
}
