#include "Matrix.hpp"
using namespace std;
class BST_Node
{
    public :
        BST_Node* left;
        BST_Node* right; // Determinant of key matrix is value
        Matrix key;
        long value;
};
class BST
{
    public:
        BST_Node* root= new BST_Node{nullptr,nullptr};
        int element(int row,int column);
        long search(Matrix A);
        void insert(Matrix A,long detA);
        bool key_exists(Matrix A);
        long counter; // It counts number of BST node that are created.
};
bool BST::key_exists(Matrix A)
{
    BST_Node *current_node= root;
    if(root == nullptr)
    {
        return false;
    }

    else if(root->key == A)
    {
        return true;
    }

    while(current_node!=nullptr)
    {

        if((A==current_node->key))
        {

            return true;
        }
        else if(!(A<current_node->key))
        {

            current_node=current_node->right;
        }
        else if((A<current_node->key))
        {

            current_node=current_node->left;
        }
    }
    return false;
}
long BST::search(Matrix A)
{
    BST_Node *current_node= root;
    if(root == nullptr)
    {
        return false;
    }

    else if(root->key == A)
    {
        return root->value;
    }

    while(current_node!=nullptr)
    {

        if((A==current_node->key))
        {

            return current_node->value;
        }
        else if(!(A<current_node->key))
        {

            current_node=current_node->right;
        }
        else if((A<current_node->key))
        {

            current_node=current_node->left;
        }
    }
    return false;

}
void BST::insert(Matrix A,long detA)
{
    BST_Node *current_node= new BST_Node;
    current_node = root;

    if(root->value == 0)
    {

        root->key=A;
        root->value=detA;
        counter++;

    }
    if(key_exists(A))
        return;
    else
    {
        while(1)
        {

            if((A==current_node->key))
            {
                return;

            }
            else if((A<current_node->key))
            {
                if(current_node->left==nullptr)
                {
                    current_node->left= new BST_Node{nullptr,nullptr};
                    current_node->left->value= detA;
                    current_node->left->key= A;
                    counter++;
                    return;

                }
                else
                {
                    current_node=current_node->left;
                }
            }
            else if(!(A<current_node->key) )
            {
               if(current_node->right==nullptr)
                {
                    current_node->right= new BST_Node{nullptr,nullptr};
                    current_node->right->value= detA;
                    current_node->right->key= A;
                    counter++;
                    return;
                }
                else
                    current_node=current_node->right;
            }
        }
    }
}
