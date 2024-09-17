#include <iostream>
#include <stack>
using namespace std;

typedef struct dlList {
    int _value;
    struct dlList *pred;
    struct dlList *urm;
}my_list;


class colocviu{

private:
    dlList *first;
    dlList *last;
    stack<dlList*> elem_min;
    int nr;
public:
    colocviu(){
        first = nullptr;
        last = nullptr;
        nr = 0;
    }
    bool even(){
        if(nr % 2 == 0)
            return true;
        return false;
    }

    void add(int v){
        dlList *newNode = new dlList;
        newNode->_value = v;
        newNode->pred = nullptr;
        newNode->urm = nullptr;
        if(first == nullptr)
        {
            first = newNode;
            last = newNode;
            elem_min.push(newNode);
        }
        else if(first == last){
            first->urm = newNode;
            newNode->pred = first;
            last = newNode;
        }
        else{
            if (nr % 2 == 0) {
                /// ca sa ajung pana la elementul din mijloc calculez minimul odata la doi pasi
                if (elem_min.top()->_value > elem_min.top()->urm->_value)
                    elem_min.push(elem_min.top()->urm);
            }
            last->urm = newNode;
            newNode->pred = last;
            last = newNode;
        }
        nr++;
    }

    void afis_mid () {
        cout << elem_min.top()->_value << "\n";
    }

    int next(){
        int ret_val = elem_min.top()->_value;
        dlList *aux = elem_min.top()->pred;
        elem_min.top()-> pred -> urm = elem_min.top() -> urm;
        elem_min.top() -> urm -> pred  = aux;
        elem_min.pop();
        return ret_val;

    }

};

int main(){
    colocviu c;
    c.add(4123);
    c.afis_mid();
    c.add(19);
    c.afis_mid();
    c.add(6);
    c.afis_mid();
    c.add(7);
    c.add(1);
    c.add(5);
    c.add(712);
    c.add(712);
    c.afis_mid();

    c.next();
    c.afis_mid();
    return 0;
}
