#include "Date.hpp"
#include "Polygon.hpp"

using namespace std;

long factorial(const int n)
{
    long f = 1;
    for (int i=1; i<=n; ++i)
        f *= i;
    return f;
}

int main()
{
    // C++ Operations on Arrays
    char C[20];
    const int ArraySize = 50;
    float A[ArraySize]; //const variable cannot be changed runtime
    long X[ArraySize+10];
    Date Calendar[365];

    float z = 23.0;
    int i = 22;
    long t;
    A[i] = z;
    t = X[i];
    X[i] = X[i+1] = t;
    /*this is equivalent to x[i+1]=t; x[i]=x[i+1];i.e., right to left*/

    // Initialization
    int facs[10];
	for (int i = 0; i < 10; i++)
		facs[i] = factorial(i);
	for (int i = 0; i < 10; i++)
    	cout << "factorial(" << i << ") is " << facs[i] << endl;

    // Indexing
    int V = 20;
    int B[20]; /*  index range is 0-19  */
    B[V] = 0; /* index is out of range, but most C++ compilers don’t check this */

    // Two Dimensional Arrays
    cout << endl;
    int T[3][4] = {{20,5,-3,0},{-85,35,-1,2},{15,3,-2,-6}};
    for(unsigned int i = 0; i < 3; i++){
        for(unsigned int j = 0; j < 4; j++)
            cout << T[i][j] << "\t";
        cout << endl;
    }

    // Arrays of Objects
    // constructor  is  called  for room[0] ..room[99];  
    Rectangle room1[100];

    Rectangle room2[3] = {Rectangle(10,15), Rectangle(5,8), Rectangle(2,30)};

    // Variables: Examples
    char mychar ='C';
    cout << "Memory: " << sizeof(char) << endl;

    // Pointers: Accessing Data
    int x=50, y=100;
    int *px = &x;
    int *py = &y;
    cout << "x: " << x << " y: " << y << endl;
    *px = *py + 2;
    cout << "x: " << x << " y: " << y << endl;
    *py = *py + 1;
    cout << "x: " << x << " y: " << y << endl;
    py = px;
    cout << "*px: " << *px << " *py: " << *py << endl;
    cout << "px: " << px << " py: " << py << endl;
    *py = 5;
    cout << "x: " << x << " y: " << y << endl;
    cout << "px: " << px << " py: " << py << endl;

    return 0;
}
