#include <stdexcept>
#include <iostream>

template <class T>
class Queue {
private:
    class Node{
    public:
        Node* next_in_line=nullptr;
        T val;
        Node(T a){
            this->val = a;
        }
		Node(T a, Node* next){
            this->val = a;
			next_in_line = next;
        }
    };
    Node *head=nullptr, *tail=nullptr;
    int sz = 0;
public:
	// returns the element at the front of the queue
    T front(){
        if(!head)
            throw std::underflow_error("attempted to access front of empty queue");
        return head->val;
    }
	// Pops and returns the element at the front of the queue
    T pop(){
        if(!head)
            throw std::underflow_error("attempted to pop from empty queue");
		T ret = head->val;
        head=head->next_in_line;
        sz--;
        if(sz==0)tail = nullptr;
		return ret;
    }

	// Pushes element to the back of the queue
    void push(T a){
        Node* tmp = new Node(a);
        if(tail)tail->next_in_line = tmp;
        tail = tmp;
        sz++;
        if(sz==1)head = tmp;
    }

    int size(){
        return sz;
    }

    bool empty(){
        return sz==0;
    }
};

int main(){
    Queue<std::string>S;
    for(int i=0; i<5; i++){
        S.push(std::to_string(i));
    }
    std::cout<<S.front()<<std::endl;
    S.pop();
    std::cout<<S.front()<<std::endl;
    std::cout<<S.size()<<std::endl;
    S.pop();
    S.pop();
    S.pop();
    S.pop();
    std::cout<<S.size()<<std::endl;
    S.pop();
}