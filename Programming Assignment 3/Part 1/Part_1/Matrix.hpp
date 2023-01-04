using namespace std;
class Matrix
{
    public:
        long **data;
        int N;
        Matrix(void);
        void print_matrix(void)const;
        int get_func(int value1 , int value2)const;
        void set_func(int value1 , int value2, int value3);
        void input_N(int input);
        void identity_matrix(void);
        long determinant(Matrix mat);


};
Matrix::Matrix(void)
{
    N=0;
    input_N(N);
}
void Matrix::identity_matrix(void)
{

    int row,column;
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
void Matrix::input_N(int input)
{
    N=input;
    data = new long*[N];
    for(int i=0;i<N;i++)
    {
        data[i]=new long[N];
    }
    identity_matrix();
}
int Matrix::get_func(int value1 , int value2)const
{
        if(value1<=N && value2<=N)
        {
            return data[value1][value2];
        }
        else
            cout<<"Please enter valid values"<<endl;
}
void Matrix::set_func(int value1 , int value2, int value3)
{
    if(value1<=N && value2<=N)
    {
        data[value1][value2]=value3;
    }
    else
        cout<<"Please enter valid values"<<endl;

}
void Matrix::print_matrix(void)const
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
long Matrix::determinant(Matrix mat)
{
    int num1, num2, det = 1, index,
                    total = 1; // Initialize result

    // temporary array for storing row
    int temp[N + 1];

    // loop for traversing the diagonal elements
    for (int i = 0; i < N; i++)
    {
        index = i; // initialize the index

        // finding the index which has non zero value
        while (index < N && mat.data[index][i] == 0)
        {
            index++;
        }
        if (index == N) // if there is non zero element
        {
            // the determinant of matrix as zero
            continue;
        }
        if (index != i)
        {
            // loop for swapping the diagonal element row and
            // index row
            for (int j = 0; j < N; j++)
            {
                swap(mat.data[index][j], mat.data[i][j]);
            }
            // determinant sign changes when we shift rows
            // go through determinant properties
            det = det * pow(-1, index - i);
        }

        // storing the values of diagonal row elements
        for (int j = 0; j < N; j++)
        {
            temp[j] = mat.data[i][j];
        }
        // traversing every row below the diagonal element
        for (int j = i + 1; j < N; j++)
        {
            num1 = temp[i]; // value of diagonal element
            num2 = mat.data[j][i]; // value of next row element

            // traversing every column of row
            // and multiplying to every row
            for (int k = 0; k < N; k++)
            {
                // multiplying to make the diagonal
                // element and next row element equal
                mat.data[j][k]
                    = (num1 * mat.data[j][k]) - (num2 * temp[k]);
            }
            total = total * num1; // Det(kA)=kDet(A);
        }
    }

    // multiplying the diagonal elements to get determinant
    for (int i = 0; i < N; i++)
    {
        det = det * mat.data[i][i];
    }
    return (det / total); // Det(kA)/k=Det(A);
}
