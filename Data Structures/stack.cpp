#include <stdexcept>
#include <iostream>

template <class T>
class Stack {
private:
    class Node{
    public:
        Node* next;
        T val;
        Node(T a, Node *n){
            this->next = n;
            this->val = a;
        }
    };
    Node *head=nullptr;
    int sz = 0;
public:

    T top(){
        if(!head)
            throw std::underflow_error("attempted to get top of empty stack");
        return head->val;
    }

    T pop(){
        if(!head)
            throw std::underflow_error("attempted to pop from empty stack");
        T ret = head->val;
        head=head->next;
        sz--;
        return ret;
    }

    void push(T a){
        head = new Node(a, head);
        sz++;
    }

    int size(){
        return sz;
    }

    bool empty(){
        return sz==0;
    }
};

int main(){
    Stack<std::string>S;
    for(int i=0; i<5; i++){
        S.push(std::to_string(i));
    }
    std::cout<<S.top()<<std::endl;
    S.pop();
    std::cout<<S.top()<<std::endl;
    std::cout<<S.size()<<std::endl;
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    std::cout<<S.size()<<std::endl;
    S.pop();
}