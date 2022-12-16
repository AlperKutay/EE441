#include <iostream>

using namespace std;

const int maxSize = 20;

template <class T>
class Array{
    private:
        T mArray[maxSize];
    public:
        Array(void);
        T GetVal(int pos) const;
        void SetVal(T val, int pos);
        void Display(void) const;
};


template <class T>
Array<T>::Array(void) : mArray() {} // Create array with default values of the template parameter type

template <class T>
void Array<T>::Display(void) const{
    for(int i = 0; i < maxSize; i++)
        cout << mArray[i] << " "; // this part assumes that cout recognizes the template parameter type
    cout << endl;
}

template <class T>
void Array<T>::SetVal(T val, int pos){
    if(pos >= 0 && pos < maxSize) // check if pos is in range
        mArray[pos] = val;
    else
        cout << "out of range" << endl;
}

template <class T>
T Array<T>::GetVal(int pos) const{
    if(pos >= 0 && pos < maxSize) // check if pos is in range
        return mArray[pos];
    else
        cout << "out of range" << endl;
}

int main()
{
    // Create objects for different template parameters
    Array<char> myCharArray; // Array with default char content
    myCharArray.Display();

    Array<int> myIntArray; // Array with default int content
    myIntArray.Display();

    Array<double> myDoubleArray; // Array with default double content
    myDoubleArray.Display();

    // Some modifications of the arrays
    myCharArray.SetVal('x',10);
    myCharArray.SetVal('y',15);
    myCharArray.Display();
    myCharArray.GetVal(25);

    for(int i = 0; i < maxSize; i++)
        myDoubleArray.SetVal(1/(double)(i+1),i);
    myDoubleArray.Display();
    return 0;
}
