#include "iostream"
#include<math.h>
using namespace std;
template <int N>
class Matrix
{
    private:
        double data[N][N];

    public:
        Matrix(void);
        int const SIZE = N;
        void print_matrix(void)const;
        void get_func(int value1 , int value2)const;
        void set_func(int value1 , int value2, int value3);
        Matrix add(Matrix m)const;
        Matrix subs(Matrix m)const;
        Matrix multp(Matrix m)const;
        double determinant(Matrix ARR,int n) const;


};
template<int N>
Matrix<N>::Matrix(void)
{

    int row,column;
    row=N;
    column=N;
    for(row=0;row<N;row++)
    {
        for(column=0;column<N;column++)
        {
            if(row==column)
                data[row][column]=1;
            else
                data[row][column]=0;
        }
    }
}
template<int N>
void Matrix<N>::print_matrix(void)const
{

    int row,column;
    row=N;
    column=N;
    for(row=0;row<N;row++)
    {
        for(column=0;column<N;column++)
        {
            cout<<data[row][column] <<ends;
        }
        cout<<endl;
    }
}
template<int N>
void Matrix<N>::get_func(int value1 , int value2)const
{
        if(value1<=N && value2<=N)
        {
            cout<<data[value1][value2]<<endl;
        }
        else
            cout<<"Please enter valid values"<<endl;
}
template<int N>
void Matrix<N>::set_func(int value1 , int value2, int value3)
{
    if(value1<=N && value2<=N)
    {
        data[value1][value2]=value3;
    }
    else
        cout<<"Please enter valid values"<<endl;

}
template<int N>
Matrix<N> Matrix<N>::add(Matrix m) const
{
     Matrix new_matrix;
     int temp;
     for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
         {
             temp=data[i][j]+m.data[i][j];
             new_matrix.set_func(i,j,temp);
         }
     }
        return new_matrix;


}
template<int N>
Matrix<N> Matrix<N>::subs(Matrix m) const
{
     Matrix new_matrix;
     int temp;
     for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
         {
             temp=data[i][j]-m.data[i][j];
             new_matrix.set_func(i,j,temp);
         }
     }
        return new_matrix;


}
template<int N>
Matrix<N> Matrix<N>::multp(Matrix m) const
{
     Matrix new_matrix;
     int temp=0;
     for(int i=0;i<N;i++)
     {
         for(int j=0;j<N;j++)
         {

             for(int k=0;k<N;k++)
             {
                temp+=data[i][k]*m.data[k][j];

             }
             new_matrix.set_func(i,j,temp);
             temp=0;
         }
     }
        return new_matrix;


}
template<int N>
double Matrix<N>::determinant(Matrix ARR,int n) const
{
     // Initialize result
    int D = 0,p=0;

    //  Base case : if matrix contains
    // single element
    if (n == 1)
        return ARR.data[0][0];

    // To store cofactors
    Matrix<N>temp;

    // To store sign multiplier
    int sign = 1;

    // Iterate for each element of
    // first row
    for (int f = 0; f < n; f++)
    {
        // Getting Cofactor of mat[0][f]
            int i = 0, j = 0;

        // Looping for each element of the matrix
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                // Copying into temporary matrix
                // only those element which are
                // not in given row and column
                if (row != p && col != f)
                {
                    temp.set_func(i,j++,ARR.data[row][col]);

                    // Row is filled, so increase row
                    // index and reset col index
                    if (j == n - 1)
                    {
                        j = 0;
                        i++;
                    }
                }
            }
        }
        D += sign * ARR.data[0][f]
             * temp.determinant(temp, n - 1);

        // Terms are to be added with alternate sign
        sign = -sign;
    }

    return D;


}
int main()
{
    Matrix<15> Mat;
    Matrix<15> Mat1;
    /*cout<<"N=3 : "<<endl;
    Mat.print_matrix();
    cout<<"N=7 : "<<endl;
    Mat1.print_matrix*/
    cout<<"MATRIX_0=>"<<endl;
    Mat.set_func(2,0,7);
    Mat.set_func(0,2,8);
    Mat.print_matrix();
    //cout<<"Determinant is "<<Mat.determinant(Mat,3)<<endl;
    cout<<"MATRIX_1=>"<<endl;
    Mat1.set_func(2,1,5);
    Mat1.set_func(1,2,5);
    Mat1.set_func(0,2,7);
    Mat1.print_matrix();
    //cout<<"Determinant is "<<Mat1.determinant(Mat1,3)<<endl;
    Matrix<15>Mat2=Mat.add(Mat1);
    cout<<"MATRIX_0+MATRIX_1=MATRIX_2"<<endl;
    Mat2.print_matrix();
    Matrix<15>Mat3=Mat2.multp(Mat1);
    cout<<"MATRIX_2*MATRIX_1=MATRIX_3"<<endl;
    Mat3.print_matrix();
    Matrix<15>Mat4=Mat3.subs(Mat1);
    cout<<"MATRIX_3-MATRIX_1=MATRIX_4"<<endl;
    Mat4.print_matrix();
    /*cout<<"Matrix 2:"<<endl;
    Mat2.print_matrix();*/
    cout<<endl;
    cout<<"Determinant of MATRIX_0 is  "<<Mat.determinant(Mat,15)<<endl;
    cout<<"Determinant of MATRIX_1 is  "<<Mat1.determinant(Mat1,15)<<endl;
    cout<<"Determinant of MATRIX_2 is  "<<Mat2.determinant(Mat2,15)<<endl;
    cout<<"Determinant of MATRIX_3 is  "<<Mat3.determinant(Mat3,15)<<endl;
    cout<<"Determinant of MATRIX_4 is  "<<Mat4.determinant(Mat4,15)<<endl;


    return 0;
}
