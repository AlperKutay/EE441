#include "iostream"
#include  <math.h>
#include "BST.hpp"
#include "take_file.hpp"
long determinant(Matrix M, BST *storage);
int main()
{
   BST* storage=new BST();

    Matrix M;
    int size=11;
    M.init_matrix(size);
    take_file_matrix(M,size,"matrices/11/0.txt");

    M.print_matrix();
    long det = determinant(M, storage);

    cout << "The determinant of the 1.matrix is: " << det <<endl;

    /*take_file_matrix(M,size,"matrices/15/1.txt");
    M.print_matrix();
    det = determinant(M, storage);

    cout << "The determinant of the 2.matrix is: " << det <<endl;

    take_file_matrix(M,size,"matrices/15/2.txt");
    M.print_matrix();
    det = determinant(M, storage);

    cout << "The determinant of the 3.matrix is: " << det <<endl;
    take_file_matrix(M,size,"matrices/15/2.txt");
    M.print_matrix();
    det = determinant(M, storage);

    cout << "The determinant of the 4.matrix is: " << det <<endl;
    take_file_matrix(M,size,"matrices/15/4.txt");
    M.print_matrix();
    det = determinant(M, storage);

    cout << "The determinant of the 5.matrix is: " << det <<endl;*/
    cout<<endl;
    cout<<endl;
    cout<<endl;
    int rambyte = storage->counter*sizeof(BST_Node);
    double ramkbyte = rambyte/1048576;
    cout<<"Used Ram size is "<<storage->counter<<" MegaByte."<<endl;
}
long determinant(Matrix M, BST* storage) {

  if (storage->key_exists(M)) {
    return storage->search(M);
  }
  long det = 0;
  if (M.N == 3) {
    det = M.get_element(0,0)*(M.get_element(1, 1)*M.get_element(2,2))-(M.get_element(1,2)*M.get_element(2,1));//a*(e*k-f*h)
    det -=M.get_element(0,1)*(M.get_element(1, 0)*M.get_element(2,2))-(M.get_element(1,2)*M.get_element(2,0));//-b*(d*k-f*g)
    det +=M.get_element(0,2)*(M.get_element(1, 0)*M.get_element(2,1))-(M.get_element(1,1)*M.get_element(2,0));//c*(d*h-e*g)*/
    return det;
  } else {
    for (int i = 0; i < M.N; i++) {
      Matrix cofactor_matrix = M.get_cofactor(i, 0);
      long cofactor = determinant(cofactor_matrix, storage);
      storage->insert(cofactor_matrix, cofactor);

      det += M.get_element(i, 0) * cofactor * ((i % 2 == 0) ? 1 : -1);
    }
  }
  return det;

}
