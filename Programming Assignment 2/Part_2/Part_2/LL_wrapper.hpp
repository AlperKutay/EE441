#include <iostream>
using namespace std;

template <class T>
class Node {
	public :
	    T data;
	// Xor of next node and previous node
	Node<T>* xnode;
};

template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y)
{
	return reinterpret_cast<Node<T>*>(
		reinterpret_cast<uintptr_t>(x)
		^ reinterpret_cast<uintptr_t>(y));
}

// Method 2
// Insert a node at the start of the Xored LinkedList and
// mark the newly inserted node as head
template <class T>
void push_f(Node<T>* &head_ref,Node<T>* &tail_ref, T data)
{
	// Allocate memory for new node
	Node<T>* new_node = new Node<T>();
	new_node -> data = data;

	// Since new node is inserted at the
	// start , xnode of new node will always be
	// Xor of current head and NULL
	new_node -> xnode = head_ref;

	// If linkedlist is not empty, then xnode of
	// present head node will be Xor of new node
	// and node next to current head */
	if (head_ref != NULL) {
		// *(head_ref)->xnode is Xor of (NULL and next).
		// If we Xor Null with next we get next
        head_ref-> xnode = Xor(new_node, head_ref -> xnode);
	}

	// Change head
	if(tail_ref == NULL){
        tail_ref=new_node;
	}
	head_ref = new_node;

}

template <class T>
void push_r(Node<T>* &head_ref,Node<T>* &tail_ref, T data)
{
	// Allocate memory for new node
	Node<T>* new_node = new Node<T>();
	new_node -> data = data;

	// Since new node is inserted at the
	// start , xnode of new node will always be
	// Xor of current head and NULL
	new_node -> xnode = tail_ref;

	// If linkedlist is not empty, then xnode of
	// present head node will be Xor of new node
	// and node next to current head */
	if (tail_ref != NULL) {
		// *(head_ref)->xnode is Xor of (NULL and next).
		// If we Xor Null with next we get next
        tail_ref-> xnode = Xor(new_node, tail_ref -> xnode);
	}

	// Change head
	if(head_ref == NULL){
        head_ref=new_node;
	}
	tail_ref = new_node;

}

template <class T>
Node<T>* peek_f(Node<T>* head){

return head;
}

template <class T>
Node<T>* pop_f(Node<T>* &head_ref,Node<T>* &tail_ref){
    Node<T>* temp;
    temp=head_ref;
    if  (head_ref == NULL){
   // cout << "bosssfront"<<endl;
    return NULL;

    }
    else  {
		// *(head_ref)->xnode is Xor of (NULL and next).
		// If we Xor Null with next we get next
        head_ref=head_ref-> xnode;
            if(head_ref==NULL){
          //  cout << "son"<<endl;
            tail_ref=NULL;
            return temp;
            }
        head_ref-> xnode=Xor(temp, head_ref -> xnode);
	}

	return temp;


}

template <class T>
Node<T>* pop_r(Node<T>* &head_ref,Node<T>* &tail_ref){
    Node<T>* temp;
    temp=tail_ref;
    if  (tail_ref == NULL){
    //cout << "bosssrear"<<endl;

    return NULL;

    }
    else  {
		// *(head_ref)->xnode is Xor of (NULL and next).
		// If we Xor Null with next we get next
        tail_ref=tail_ref-> xnode;
            if(tail_ref==NULL){
             //   cout << "son"<<endl;
                head_ref=NULL;
                return temp;
            }
        tail_ref-> xnode=Xor(temp, tail_ref -> xnode);
	}
	return temp;


}


// Method 3
// It simply prints contents of doubly linked
// list in forward direction
template <class T>
 void printList(Node<T>* head)
{
	Node<T>* currPtr = head;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;

	cout << "The nodes of Linked List are: \n";

	// Till condition holds true
	while (currPtr != NULL) {
		// print current node
		cout << currPtr -> data<<" ";

		// get address of next node: curr->xnode is
		// next^prev, so curr->xnode^prev will be
		// next^prev^prev which is next
		nextPtr = Xor(prevPtr, currPtr -> xnode);

		// update prev and curr for next iteration
		prevPtr = currPtr;
		currPtr = nextPtr;
	}
	cout<<endl;
}

template <class T>
bool empt(Node<T>* head,Node<T>* tail){
    if(head==NULL && tail==NULL)
        return 1;
    return 0;


}



template <class T>
class LL_wrapper{
 private :
 Node<T>* head_node;
 Node<T>* tail_node;

 public :
    LL_wrapper(void){
    head_node=NULL;
    tail_node=NULL;}
    void push_front(T data){
    push_f(head_node,tail_node, data);
    }
    void push_rear(T data){
    push_r(head_node,tail_node, data);
    }
    T pop_front(void){
    return pop_f(head_node,tail_node)->data;
    }
    T pop_rear(void){
    return pop_r(head_node,tail_node)->data;
    }
    T peek_front(void) const{
    T temp;
    if(!is_empty())
        temp=peek_f(head_node)->data;
    return temp;
    }
    void print_elements() const{
    printList(tail_node);
    }
    bool is_empty() const{
    return empt(head_node,tail_node);
    }
};

