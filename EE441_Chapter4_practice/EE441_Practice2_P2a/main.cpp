#include <iostream>
#include "queue.h"
#include "stack.h"

using namespace std;

int main()
{
    Stack<char> S;
    S.Push('6');
    S.Push('0');
    S.Push(' ');
    S.Push('9');
    S.Push('8');
    S.Push(' ');
    S.Push('7');
    S.Push('6');
    S.Push('5');
    S.Push(' ');
    S.Push('4');
    S.Push('3');
    S.Push('2');
    S.Push('1');
    Queue<char> Q;
    Q.QInsert('+');
    Q.QInsert('-');
    Q.QInsert('%');
    Q.QInsert('*');
    Q.QInsert('/');
    Q.QInsert('x');
    Q.QInsert('y');
    Q.QInsert('z');
    // Program
    Stack<char> S1;
    char c;
    while (!S.StackEmpty()){
        while(!S.StackEmpty() && !(S.Peek() == ' ') ){
            S1.Push(S.Pop());
        }
        if(!S.StackEmpty())
            c=S.Pop();
        if (!Q.QEmpty() && !S.StackEmpty() )
            S1.Push(Q.QDelete());
    }
    while (!S1.StackEmpty())
        cout << S1.Pop() << "\t";
    return 0;
}
