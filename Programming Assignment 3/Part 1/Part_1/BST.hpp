#include "Matrix.hpp"
using namespace std;
class BST_Node
{
    public :
        BST_Node* left;
        BST_Node* right; // Determinant of key matrix is value
        bool filled;
        Matrix key;
        long value;
};
class BST
{
    public:
        BST_Node* root;
        BST(void);
        int is_equal_Bst(BST_Node A, BST_Node B) const;
        int is_equal_Matrix(Matrix A, Matrix B) const;
        int is_smaller_Bst(BST_Node A, BST_Node B) const;
        int is_smaller_Matrix(Matrix A, Matrix B) const;
        int element(int row,int column);
        long search(Matrix A);
        void insert(Matrix A);
        long key_exists(Matrix A);
        void create_left_right(BST_Node* node);
        void print_nodes();
};
BST::BST(void)
{
    root = new BST_Node;
    root->left = new BST_Node;
    root->right = new BST_Node;
    root->filled = false;

}
void BST::create_left_right(BST_Node* node)
{
    node->left = new BST_Node;
    node->left->filled = false;
    node->right = new BST_Node;
    node->right->filled = false;
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
                if(A.get_func(row,column)==B.get_func(row,column))
                    continue;
                else if(A.get_func(row,column)>B.get_func(row,column))
                    return false;
                else if(A.get_func(row,column)<B.get_func(row,column))
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
            if(A.get_func(row,column)!=B.get_func(row,column))
                 return false;
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
        cout<<current_node->key.N<<endl;
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
}
long BST::search(Matrix A)
{
    if(key_exists(A))
    {
        return A.determinant(A);
    }

}
void BST::insert(Matrix A)
{
    BST_Node *current_node= new BST_Node;
    current_node = root;

    if(root->filled==false)
    {
        root->key=A;
        root->value=A.determinant(A);
        root->filled=true;
    }
    else
    {
        while(current_node->filled!=false)
        {
            if(is_equal_Matrix(A,current_node->key))
            {
                current_node->value=A.determinant(A);
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
        current_node->key=A;
        current_node->value=A.determinant(A);
        current_node->filled=true;
        create_left_right(current_node);
    }
}
