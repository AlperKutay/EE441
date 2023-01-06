 #include <fstream>
void take_file_matrix(Matrix &Mat,int row_column,char* file_name)
{
     fstream input_file(file_name);
     int a;
     for(int i=0; i<row_column; ++i)
    {
        for(int j=0; j<row_column; ++j)
        {
            input_file >> a;
           Mat.set_element(i,j,a);
        }
    }

}
