//PART1
//ALPER KUTAY ÖZBEK
//2375467
#include <iostream>
using namespace std;
const int MaxStackSize=1024;
template <class T>
class StackQueue
{
public:
    //constructor
    T stacklist[MaxStackSize];
    int front, rear, count;
    StackQueue(void); // initialize data members
    void push_front(const T& item);
    void push_rear(const T& item);
    T pop_front(void);
    T pop_rear(void);
    T peek_front(void) const;
    void print_elements(void);
    T peek_rear(void) const;
};
template <class T>
StackQueue<T>::StackQueue(void): front(0), rear (0), count(0)
{}
//Push
template <class T>
void StackQueue<T>::push_rear(const T& item)//
{
    //can not push if stack has exceeded its limits
    if (rear==MaxStackSize-1)
    {
        cout<<"Stack overflow"<<endl;
        exit(1);
    }
    // increment top and copy item into list
    stacklist[rear] = item;
    rear++;
    count++;


}
template <class T>
void StackQueue<T>::push_front(const T& item)//
{
    //can not push if stack has exceeded its limits
    // increment top and copy item into list
    stacklist[front] = item;
}
template <class T>
void StackQueue<T>::print_elements(void)//
{
     cout<<endl;
    cout<<"SQ: ";
    for(int i=front;i<count;i++)
    {
        cout<<stacklist[i];//print all elements one by one
    }
    cout<<endl;
}
template <class T>
T StackQueue<T>::pop_front(void)//
{
    T value=stacklist[front];//pop front element in the stack
    stacklist[front]=' ';//after pop, front element becomes empty
    front++;//front increases
    //count--;//count decreases
    return value;
}
template <class T>
T StackQueue<T>::pop_rear(void)//
{
    T value=stacklist[rear-1];//pop rear element in the stack
    stacklist[rear-1]=' ';//after rear, front element becomes empty
    rear--;//rear decreases
    return value;
}
template <class T>
T StackQueue<T>::peek_front(void) const//
{
    return stacklist[front];//peek front element
}
template <class T>
T StackQueue<T>::peek_rear(void) const//
{
    return stacklist[count-1];//peek rear element
}
