//PART2
//ALPER KUTAY ÖZBEK
//2375467
#include <bits/stdc++.h>
#include <cinttypes>
#include <iostream>
using namespace std;

template <class T>
class Node {
	public :
	    T data;
	Node<T>* xnode;
};


template <class T>
Node<T>* Xor(Node<T>* x, Node<T>* y)
{
	return reinterpret_cast<Node<T>*>(
		reinterpret_cast<uintptr_t>(x)
		^ reinterpret_cast<uintptr_t>(y));
}

template <class T>
void insert(Node<T>* &head_ref, T data)
{

	Node<T>* new_node = new Node<T>();
	new_node -> data = data;


	new_node -> xnode = head_ref;

	if (head_ref != NULL) {
        head_ref-> xnode = Xor(new_node, head_ref -> xnode);
	}
	head_ref = new_node;
}

template <class T>
 void printList(Node<T>* head)
{
	Node<T>* currPtr = head;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	T data[1024];
    int i=0;
    cout<<endl;
    cout<<"SQ: ";
	while (currPtr != NULL) {
		data[i]=currPtr -> data;
		nextPtr = Xor(prevPtr, currPtr -> xnode);
		prevPtr = currPtr;
		currPtr = nextPtr;
		i++;
	}
	i--;
	while(i>-1)//this row prints backwards because original function prints rear to front according to my head node
    {
        if(data[i]==NULL)
        {
            i--;
            continue;
        }
        cout<<data[i];
        i--;
    }
    cout<<endl;
}
template <class T>
void push_r(Node<T>* &head_ref, T data)
{
	Node<T>* new_node = new Node<T>();
	new_node -> data = data;//create a new node which has value of input and head_ref adress
	new_node -> xnode = head_ref;
	if (head_ref != NULL) {//if it is not NULL we define head_ref is the next node
        head_ref-> xnode = Xor(new_node, head_ref -> xnode);
	}
	head_ref = new_node;
}
template <class T>
void push_f(Node<T>* head_ref,T data)
{
    if(head_ref==NULL)//if there is nothing in the linked list head_ref is adjusted in here
    {
        head_ref->data=data;
        insert<T>(head_ref,data);
        return;
    }
	Node<T>* new_node = new Node<T>();
	new_node -> data = data;// create a new node

    Node<T>* last = NULL;
    Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	while (1) {// we are trying to shift the linked list so that we always find current node
		if(Xor(prevPtr, currPtr -> xnode) == NULL)//if loop comes the end we define it is end of the list and break the loop
        {

            currPtr -> xnode = Xor(prevPtr,new_node);//finds current node
            new_node->xnode = Xor(currPtr,last);//make current node is end
            break;
        }
		nextPtr = Xor(prevPtr, currPtr -> xnode);//finds current node
		prevPtr = currPtr;//shifts the list
		currPtr = nextPtr;
        }
	}
template <class T>
T pop_r(Node<T>* &head_ref)
{
    Node<T>* last = NULL;
    Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	T out_data=head_ref->data;// take the data of head
	while (1) {// loop aims to find last node in the list
        if(Xor(prevPtr, currPtr -> xnode)==NULL)//this row aims to adjust if head_ref will NULL after the pop process which means we will in the empty list
        {
            T out_data=currPtr->data;
            currPtr->data=NULL;// since after pop_r node will be empty,we adjust data is NULL in the remain node
            currPtr=NULL;
            return out_data;
        }
		nextPtr = Xor(prevPtr, currPtr -> xnode);

        currPtr->data=nextPtr->data;
        if(Xor(currPtr, nextPtr -> xnode)==NULL)//if we find last node in the loop
        {
            currPtr -> xnode = Xor(prevPtr,last);//last row deleted and prev node becomes last node
            break;
        }
        prevPtr = currPtr;
		currPtr = nextPtr;

	}
    return out_data;
}
template <class T>
T pop_f(Node<T>* &head_ref)
{
    Node<T>* last = NULL;
    Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	T out_data;

	while (1) {// loop aims to find last node in the list
        if(Xor(prevPtr, currPtr -> xnode)==NULL)//this row aims to adjust if head_ref will NULL after the pop process which means we will in the empty list
        {
            T out_data=currPtr->data;// since after pop_f node will be empty,we adjust data is NULL in the remain node
            currPtr->data=NULL;
            currPtr=NULL;
            return out_data;
        }
		nextPtr = Xor(prevPtr, currPtr -> xnode);

        if(Xor(currPtr, nextPtr -> xnode)==NULL)//if we find first node in the loop
        {
            out_data=nextPtr->data;
            currPtr -> xnode = Xor(prevPtr,last);
            break;
        }
        prevPtr = currPtr;
		currPtr = nextPtr;

	}
    return out_data;
}
template <class T>
T peek_f(Node<T>* &head_ref)
{
    return head_ref->data;//peek the front data
}
template <class T>
T empt(Node<T>* &head_ref)//check if node is empty or not
{
    if(head_ref==NULL)
        return true;
    return false;
}
template <class T>
T peek_r(Node<T>* &head_ref)
{
    Node<T>* currPtr = head_ref;
	Node<T>* prevPtr = NULL;
	Node<T>* nextPtr;
	T data[1024];
    int i=0;

	// Till condition holds true
	while (currPtr != NULL) {
		data[i]=currPtr -> data;//we find the rear data

		// get address of next node: curr->xnode is
		// next^prev, so curr->xnode^prev will be
		// next^prev^prev which is next
		nextPtr = Xor(prevPtr, currPtr -> xnode);

		// update prev and curr for next iteration
		prevPtr = currPtr;
		currPtr = nextPtr;
		i++;
	}
	i--;
	return data[0];//we find the last data in the loop
}
// Method 4
// main driver method
template <class T>
class Wrapper_Func{//we defined all function for wrapper functions
 private :
 Node<T>* head_node;

 public :
    Wrapper_Func(void){
    head_node=NULL;}
    void push_front(T data){
    push_f(head_node, data);
    }
    void push_rear(T data){
    push_r(head_node, data);
    }
    T pop_front(void){
    return pop_f(head_node);
    }
    T pop_rear(void){
    return pop_r(head_node);
    }
    T peek_rear(void)
    {
        T temp;
        if(!is_empty())
            temp=peek_f(head_node);
        return temp;
    }
    void print_elements() const
    {
        printList(head_node);
    }
    bool is_empty()
    {
        return empt(head_node);
    }
};
