#include <bits/stdc++.h>
using namespace std;

class LRUCache {
    struct node{
//         next is set on initialization, and only becomes null when it is the last element
//         prev is set on initialization of new start element
//         val is set on initialization
        node *prev, *next;
        int val, key;
        node(node* n, int key, int val){
            if(n)n->prev = this;
            prev = 0;
            next = n;
            this->val = val;
            this->key = key;
        }
        node(){}
    };
//     initialized in constructor
    int cap;
//     These 2 implement a doubly-linked queue
//     push to the back of the queue, remove from front of queue
//     both become initialized during first insertion and should never become uninitialized
    node* queue_front, *queue_back;
//     stores all the nodes corresponding to keys
    unordered_map<int, node*> Node;
    
    void move_to_back(node* n){
//             If it is already at the back, no need to do anything
            if(n == queue_back)return;
//             If we are moving from the back, make sure to update the last element (there are guaranteed at least 2 elements, since queue_back is a different node)
            if(n == queue_front)queue_front = queue_front->prev;
            
//             Update neighbours of n
            if(n->next)n->next->prev = n->prev;
            if(n->prev)n->prev->next = n->next;
            
//             update queue back. This is fine since n and queue_back are distinct
            n->next = queue_back;
            n->prev = 0;
            queue_back->prev = n;
            queue_back = n;        
    }
    void remove_last_node(){
        node* to_delete = queue_front;
//                 update queue back
        queue_front = queue_front->prev;
        queue_front->next = 0;
//                 erase node from map
        // cerr<<"Removing node "<<to_delete->val<<endl;
        // cerr<<"node size before removal: "<<Node.size()<<endl;
        Node.erase(to_delete->key);
        // cerr<<"node size after removal: "<<Node.size()<<endl;
//                 free up memory
        delete(to_delete);
    }
public:
    LRUCache(int capacity) {
        cap = capacity;
        queue_front = 0;
        queue_back = 0;
    }
    
    int get(int key) {
        // cerr<<Node.size()<<endl;
        if(Node.count(key)){
            node *n = Node[key];
            move_to_back(n);
            return n->val;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(Node.count(key)){
            node *n = Node[key];
            n->val = value;
            move_to_back(n);
        }
        else{
//             insert value into the queue
            queue_back = new node(queue_back, key, value);
            if(!queue_front)queue_front = queue_back;
//             add the node to the map
            Node[key] = queue_back;
            
//             Remove a node from the back if necessary
            if(Node.size() > cap){
                
                remove_last_node();
                
            }
        }
    }
};

int main(){
    auto c = LRUCache(1);
    c.put(2, 1);
    cout<<c.get(2)<<endl;
    c.put(3, 2);
    cout<<c.get(2)<<endl;
}