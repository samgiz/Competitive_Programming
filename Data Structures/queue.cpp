#include <stdexcept>
#include <iostream>

using namespace std;

template <class T>
class Queue {
private:
	class Node{
	public:
		Node* prev=nullptr;
		T val;
		Node(T a){
			this->val = a;
		}
	};
	Node *head=nullptr, *tail=nullptr;
	int sz = 0;
public:

	T front(){
		if(!head)
			throw underflow_error("attempted to access front of empty queue");
		return head->val;
	}

	void pop(){
		if(!head)
			throw underflow_error("attempted to pop from empty queue");
		head=head->prev;
		sz--;
		if(sz==0)tail = nullptr;
	}

	void push(T a){
		Node* tmp = new Node(a);
		if(tail)tail->prev = tmp;
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
	Queue<string>S;
	for(int i=0; i<5; i++){
		S.push(to_string(i));
	}
	cout<<S.front()<<endl;
	S.pop();
	cout<<S.front()<<endl;
	cout<<S.size()<<endl;
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	cout<<S.size()<<endl;
	S.pop();
}