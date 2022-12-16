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
    Stack<char> S1, S2;
    Queue<char> Q1;
    char c;
    while (!S.StackEmpty() )
        S1.Push(S.Pop());
    while (!S1.StackEmpty()){
        while (!S1.StackEmpty() && !(S1.Peek()==' ') )
            S2.Push(S1.Pop());
        if (!S1.StackEmpty())
            c=S1.Pop();
        if (!Q.QEmpty() )
            S2.Push(Q.QDelete());
        while (!S2.StackEmpty()&&!(S2.Peek()==' ') )
            Q1.QInsert(S2.Pop());
    }
    while (!Q1.QEmpty() )
        cout << Q1.QDelete() << "\t";
    return 0;
}
