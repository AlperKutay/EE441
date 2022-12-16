#include <iostream>

using namespace std;
#define type ByPointer

#if type == ByValue
// Call by value
void swap(int a, int b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}

#elif type == BYRef
// Call by reference
void swap(int &a, int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}
#endif

// Call by pointer
void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}



int main(){
#if type != ByPointer
    int i = 10;
    int j = 20;
    cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
    swap(i,j);
    cout << "After swap(): i:   "<<i<<" j: "<<j<<endl;
#else
    int i = 10;
    int j = 20;
    cout << "Before swap(): i: "<<i<<" j: "<<j<<endl;
    swap(&i,&j);
    cout << "After swap(): i: "<<i<<" j: "<<j<<endl;
#endif
}
