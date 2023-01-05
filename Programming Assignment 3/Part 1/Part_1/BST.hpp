#include "Matrix.hpp"
using namespace std;
class BST_Node
{
    public :
        BST_Node* left;
        BST_Node* right; // Determinant of key matrix is value
        int filled;
        Matrix key;
        long value;
};
int inser_counter=0;
class BST
{
    public:
        BST_Node* root;
        BST(void);
        int is_equal_Matrix(Matrix A, Matrix B) const;
        int is_smaller_Matrix(Matrix A, Matrix B) const;
        int element(int row,int column);
        long search(Matrix A);
        int insert(Matrix A,long detA);
        long key_exists(Matrix A);
        void create_left_right(BST_Node* node);
};
BST::BST(void)
{
    root = new BST_Node;
    root->left = new BST_Node;
    root->left->filled = 0;
    root->right = new BST_Node;
    root->right->filled = 0;
    root->filled = 0;

}
void BST::create_left_right(BST_Node* node)
{
    node->left = new BST_Node;
    node->left->filled = 0;
    node->left->value=0;
    node->right = new BST_Node;
    node->right->filled = 0;
    node->right->value=0;
}
int BST::is_smaller_Matrix(Matrix A, Matrix B) const
{
    if(A.N < B.N)
        return true;
    else if(A.N == B.N)
    {
        for(int row=0;row<A.N;row++)
        {
            for(int column=0;column<A.N;column++)
            {
                if(A.get_element(row,column)==B.get_element(row,column))
                    continue;
                else if(A.get_element(row,column)>B.get_element(row,column))
                    return false;
                else if(A.get_element(row,column)<B.get_element(row,column))
                    return true;
            }
        }
        return false;
    }
    else
        return false;

}
int BST::is_equal_Matrix(Matrix A, Matrix B)const
{
    if(A.N!=B.N)
        return false;
    for(int row=0;row<A.N;row++)
    {
        for(int column=0;column<A.N;column++)
        {
            if(A.get_element(row,column)!=B.get_element(row,column))
            {

                return false;
            }

        }
    }
    return true;
}
long BST::key_exists(Matrix A)
{
    BST_Node *current_node= new BST_Node;
    current_node = root;

    while(current_node->filled!=false)
    {

        if(is_equal_Matrix(A,current_node->key))
        {
            return current_node->value;
        }
        else if(!is_smaller_Matrix(A,current_node->key))
        {

            current_node=current_node->right;
        }
        else if(is_smaller_Matrix(A,current_node->key))
        {

            current_node=current_node->left;
        }
    }
    //return false;
}
long BST::search(Matrix A)
{
    return key_exists(A);

}
int BST::insert(Matrix A,long detA)
{
    BST_Node *current_node= new BST_Node;
    current_node = root;

    if(root->filled==0)
    {
        root->key=A;
        root->value=detA;
        root->filled=1;
    }
    else
    {
        while(current_node->filled!=0)
        {

            if(is_equal_Matrix(A,current_node->key))
            {
                return 0;

            }
            else if(is_smaller_Matrix(A,current_node->key))
            {
                current_node=current_node->left;
            }
            else if(!is_smaller_Matrix(A,current_node->key) )
            {
                current_node=current_node->right;
            }
        }
        current_node->key=A;
        current_node->value=detA;
        current_node->filled=1;
        create_left_right(current_node);
        return 0;
    }
}
