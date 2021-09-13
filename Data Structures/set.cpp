#include <stdexcept>
#include <iostream>

using namespace std;

template <class T>
class Set {
private:
    class Node{
    public:
        Node *l, *r;
        T val;
        Node(T a, Node *n){
            this->l = n;
            this->r = n;
            this->val = a;
        }
    };
    Node *root=nullptr, *back=nullptr;
    int sz = 0;
public:
    void insert(T el){
        
    }
    int depth(){

    }
    T nthElement(int n){

    }
    bool empty(){

    }
    bool delete(T el){

    }
    // T more(T el){

    // }
    // T less(T el){

    // }
    // T lesseq(T el){

    // }
    // T moreeq(T el){

    // }

};

int main(){

}