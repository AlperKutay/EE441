#include "iostream"
#include<math.h>
#include "BST.hpp"

int main()
{
    Matrix Mat;
    Mat.input_N(5);

    Matrix Mat1;
    Mat1.input_N(7);

    Matrix Mat2;
    Mat2.input_N(8);

    Matrix Mat3;
    Mat3.input_N(6);

     Matrix Mat4;
    Mat4.input_N(9);

    BST tree;
    tree.insert(Mat);
    tree.insert(Mat1);
    tree.insert(Mat2);
    tree.insert(Mat3);
    tree.insert(Mat4);
    cout<<tree.key_exists(Mat)<<endl;
}
