using namespace std;
class Matrix
{
    public:
        long data[20][20];
        int N;
        Matrix();
        void print_matrix(void)const;
        int get_element(int value1 , int value2)const;
        void set_element(int value1 , int value2, int value3);
        void copy_constructer(Matrix Mat);
        void init_matrix(int size);
        void clear_matrix();
        int get_size();
        bool operator==(Matrix &Mat);
        Matrix get_cofactor(int row,int column);
        bool operator<(Matrix &Mat);


};
Matrix::Matrix()
{
    N=0;
    init_matrix(N);
}
Matrix Matrix::get_cofactor(int row, int col) {

      Matrix cofactor_matrix;
      cofactor_matrix.init_matrix(N-1);
      int row_offset = 0;
      for (int i = 0; i < N; i++) {
        if (i == row) {
          row_offset = 1;
          continue;
        }
        int col_offset = 0;
        for (int j = 0; j < N; j++) {
          if (j == col) {
            col_offset = 1;
            continue;
          }
          cofactor_matrix.set_element(i - row_offset, j - col_offset, data[i][j]);
        }
      }
      return cofactor_matrix;
}

void Matrix::init_matrix(int size)
{
    N=size;
    int row,column;
    for(row=0;row<size;row++)
    {
        for(column=0;column<size;column++)
        {
            if(row==column)
                data[row][column]=1;
            else
                data[row][column]=0;
        }
    }
}
void Matrix::copy_constructer(Matrix Mat)
{
    int row,column;
    for(row=0;row<N;row++)
    {
        for(column=0;column<N;column++)
        {
                data[row][column]=Mat.data[row][column];
        }
    }
}
int Matrix::get_size()
{
    return N;
}
void Matrix::clear_matrix()
{
    int row,column;
    for(row=0;row<N;row++)
    {
        for(column=0;column<N;column++)
        {
                data[row][column]=0;
        }
    }
}
int Matrix::get_element(int value1 , int value2)const
{
        if(value1<=N && value2<=N)
        {
            return data[value1][value2];
        }
        else
            cout<<"Please enter valid values"<<endl;
}
void Matrix::set_element(int value1 , int value2, int value3)
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
    cout<<"MATRIX: "<<endl;
    for(row=0;row<N;row++)
    {
        cout<<"  ";
        for(column=0;column<N;column++)
        {
            cout<<data[row][column]<<" "<<ends;
        }
        cout<<endl;
    }
}
bool Matrix::operator==(Matrix &Mat)
{
    if(N!=Mat.N)
        return false;
    for(int row=0;row<N;row++)
    {
        for(int column=0;column<N;column++)
        {
            if(get_element(row,column)!=Mat.get_element(row,column))
            {

                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator<(Matrix &Mat)
{
    if(N < Mat.N)
        return true;
    else if(N == Mat.N)
    {

        for(int row=0;row<Mat.N;row++)
        {
            for(int column=0;column<Mat.N;column++)
            {
                if(get_element(row,column)==Mat.get_element(row,column))
                    continue;
                else if(get_element(row,column)>Mat.get_element(row,column))
                    return false;
                else if(get_element(row,column)<Mat.get_element(row,column))
                    return true;
            }
        }
        return false;
    }
    else
        return false;
}
