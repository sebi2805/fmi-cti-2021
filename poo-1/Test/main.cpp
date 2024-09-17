// #include <iostream>
// using namespace std;
// #include "Interface.h"
// int main()
// {
//     Interface menu;
//     menu.start();
// }
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

// using namespace std;

// const int N = 100;
// int a[N];

// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// };

// // Build Cartesian tree from given sequence of numbers
// TreeNode *buildTree(int *a, int n)
// {
//     stack<TreeNode *> st;
//     for (int i = 0; i < n; i++)
//     {
//         TreeNode *node = new TreeNode(a[i]);

//         if (st.size() == 0)
//         {
//             st.push(node);
//             continue;
//         }
//         while (st.size() >= 1 && st.top()->val > node->val)
//         {
//             st.push(node);
//             st.pop();
//             node->left = st.top();
//         }

//         if (st.size() > 1)
//         {
//             st.push(node);
//             st.top()->right = node;
//             // st.pop();
//         }
//         cout << st.size() << endl;
//     }
//     cout << "root" << st.top()->val << endl;
//     return st.size() == 1 ? st.top() : nullptr;
// }

// int main()
// {
//     // Initialize sequence of numbers
//     for (int i = 0; i < N; i++)
//         a[i] = i;
//     // Build Cartesian tree
//     TreeNode *root = buildTree(a, N);
//     // Print pre-order traversal of tree to verify that it is correct
//     queue<TreeNode *> st;
//     st.push(root);
//     cout << "root" << root->right->val << endl;
//     // while (!st.empty())
//     // {
//     //     TreeNode *node = st.front();
//     //     st.pop();
//     //     cout << node->val << " ";
//     //     if (node->right)
//     //         st.push(node->right);
//     //     if (node->left)
//     //         st.push(node->left);
//     // }
//     cout << endl;
//     return 0;
// }
#include <map>
// typedef struct BinaryTree
// {
//     int value;
//     struct BinaryTree *tata;
//     struct BinaryTree *stinga;
//     struct BinaryTree *dreapta;
// } BinaryTree;

// void getNodes(BinaryTree *T, vector<BinaryTree *> &nodes)
// {
//     nodes.push_back(T);
//     if (T->stinga != NULL)
//         getNodes(T->stinga, nodes);
//     if (T->dreapta != NULL)
//         getNodes(T->dreapta, nodes);
// }

// BinaryTree *createNode(int value)
// {
//     BinaryTree *node = new BinaryTree;
//     node->value = value;
//     node->tata = NULL;
//     node->stinga = NULL;
//     node->dreapta = NULL;
//     return node;
// }
// void computeHeights(BinaryTree *T, map<BinaryTree *, int> &heights)
// {
//     if (T->stinga == NULL && T->dreapta == NULL)
//     {
//         heights[T] = 0;
//         return;
//     }
//     else
//     {
//         if (T->stinga != NULL)
//             computeHeights(T->stinga, heights);
//         if (T->dreapta != NULL)
//             computeHeights(T->dreapta, heights);
//         heights[T] = max(heights[T->stinga], heights[T->dreapta]) + 1;
//     }
// }
// map<BinaryTree *, int> heights;
// vector<bool> balancedSubtree(BinaryTree *T)
// {
//     vector<bool> aux;
//     vector<BinaryTree *> nodes;
//     getNodes(T, nodes);

//     for (auto i : nodes)
//         if (abs(heights[i->stinga] - heights[i->dreapta]) <= 1)
//             aux.push_back(true);
//         else
//             aux.push_back(false);
//     return aux;
// }
// int sumOfInterval(BinaryTree *T, int x, int y, vector<int> &bal)
// {
//     static int i = 0;
//     if (x <=)
//         if (T->value <= y && T->value >= x && bal[i] == 1)
//             return T->value + sumOfInterval(T->stinga, x, y, bal) + sumOfInterval(T->stinga, x, y, bal);
// }
// int main()
// {
//     BinaryTree *root = createNode(1);
//     root->stinga = createNode(2);
//     root->stinga->tata = root;
//     root->dreapta = createNode(3);
//     root->dreapta->tata = root;
//     root->stinga->stinga = createNode(4);
//     root->stinga->stinga->tata = root->stinga;
//     root->stinga->stinga->stinga = createNode(4);
//     root->stinga->stinga->stinga->tata = root->stinga;
//     vector<BinaryTree *> nodes;

//     computeHeights(root, heights);

//     for (auto i : balancedSubtree(root))
//         cout << i << endl;
// }
// class B
// { protected: static int x;
//  int i;
//  public: B() { x++; i=1; }
//  ~B() { x--; i--;}
//  static int get_x() { return x; }
//  int get_i() { return i; } };
// int B::x;
// class D: public B
// { public: D() { x++;}
//  ~D() { x--;}
//  int f1(B o){return 5+o.get_i();} };
// int f(B *q)
// { return (q->get_x())+1; }
// int main()
// { B *p=new B[10];
//  cout<<f(p);
//  delete[] p;
//  p=new D;
//  cout<<p->f1(p);
//  delete p;
//  cout<<D::get_x();
//  return 0;
// }
// struct Node
// {
//     int data;
//     Node *left, *right;
// };

// vector<int> buildCartesianTree(vector<int> &v)
// {

//     vector<int> left(v.size(), -1);
//     vector<int> right(v.size(), -1);
//     stack<int> st;
//     stack<int> dr;
//     for (int i = 0; i < v.size(); i++)
//     {
//         if (st.empty())
//             st.push(i);
//         else
//         {
//             while (st.empty() && v[i] < st.top())
//             {

//                 st.pop();
//             }
//             left[i] = st.top();
//             st.push(i);
//         }
//     }

//     for (int i = v.size() - 1; i > 0; i--)
//     {
//         if (dr.empty())
//             dr.push(i);
//         else
//         {
//             while (dr.empty() && v[i] < dr.top())
//             {
//                 dr.pop();
//             }
//             right[i] = dr.top();
//             dr.push(i);
//         }
//     }
//     vector<int> father(v.size(), -1);
//     for (int i = 0; i < father.size(); i++)
//         father[i] = left[i] < right[i] ? left[i] : right[i];
//     return father;
// };
// int main()
// {

//     vector<int> v = {9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5};
//     vector<int> cartesian = buildCartesianTree(v);
//     for (auto i : cartesian)
//         cout << i << " ";
// }
