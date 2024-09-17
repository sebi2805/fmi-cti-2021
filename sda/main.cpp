#include <iostream>
#include <vector>

using namespace std;

struct nod_lista_simplu_inlantuita
{
    int info;
    nod_lista_simplu_inlantuita *urm;
};

/// nod_lista_simplu_inlantuita *root = new nod_lista_simplu_inlantuita

struct nod_lista_dublu_inlantuita
{
    int info;
    nod_lista_dublu_inlantuita *pred;
    nod_lista_dublu_inlantuita *urm;
};

/// nod_lista_dublu_inlantuita *root = new nod_lista_dublu_inlantuita

/// stiva din STL -> stack <int> s;    sus #include <stack>
/// empty() – Returns whether the stack is empty – Time Complexity : O(1)
/// size() – Returns the size of the stack – Time Complexity : O(1)
/// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1)
/// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1)
/// pop() – Deletes the top most element of the stack – Time Complexity : O(1)

/// se poate simula si stackul
struct nod
{
    int info;
    nod *next;
};

class stack
{
public:
    int count;
    nod* root;
    stack()
    {
        count = 0;
        root = new nod;
        root = nullptr;
    }
    ~stack()
    {
        count = 0;
        delete root;
    }

    bool empty()
    {
        if(root == nullptr)
            return 1;
        return 0;
    }
    int size()
    {
        return count;
    }
    int top()
    {
        return root->info;
    }
    int push(int g)
    {
        count++;
        nod* new_element = new nod;
        new_element -> info = g;
        new_element -> next = root;
        root = new_element;
    }
    void pop()
    {
        if(root)
        {
            count--;
            nod *aux = new nod;
            aux = root;
            root = root->next;
            delete aux;
        }
    }
};

/// restul din STL, se pot implementa pe stilul de mai sus
/// ggwp

int main()
{
}