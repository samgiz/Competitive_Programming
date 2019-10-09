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
	Node *root=nullptr, *back=nullptr;
	int sz = 0;
public:

	T front(){
		if(!root)
			throw underflow_error("attempted to access front of empty stack");
		return root->val;
	}

	void pop(){
		if(!root)
			throw underflow_error("attempted to pop from empty queue");
		root=root->prev;
		sz--;
		if(sz==0)back = nullptr;
	}

	void push(T a){
		Node* tmp = new Node(a);
		if(back)back->prev = tmp;
		back = tmp;
		sz++;
		if(sz==1)root = tmp;
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