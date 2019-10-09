#include <stdexcept>

using namespace std;

template <class T>
class mycontainer {
	private:
	class Node{
		Node* next;
		T val;
		Node(T a, Node *n){
			this->next = n;
			this->val = a;
		}
	};
	Node *root=null;
	int sz = 0;
	public:

	T top(){
		if(!root)
			throw underflow_error("attempted to get top of empty stack");
		return root->val;
	}

	T pop(){
		if(!root)
			throw underflow_error("attempted to get top of empty stack");
		root=root->next;
		sz--;
	}

	void push(T a){
		root = new Node(a, root);
		sz++;
	}

	int size(){
		return sz;
	}

	int empty(){
		return sz==0;
	}
};

int main(){
	stack<string>S;
	for(int i=0; i<5; i++){
		S.push(stoi(i));
	}
	cout<<S.top()<<endl;
	S.pop();
	cout<<S.top()<<endl;
	cout<<S.size()<<endl;
	S.pop();
	S.pop();
	S.pop();
	S.pop();
	cout<<S.size()<<endl;
	S.pop();
}