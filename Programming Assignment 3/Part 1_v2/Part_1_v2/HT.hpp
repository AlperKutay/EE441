#include "Matrix.hpp"
using namespace std;
class HT_Item
{
    public :
        Matrix key;
        long value;
};

class HashTable
{
    public:
        HT_Item* root;
        BST(void);
        long search(Matrix A,long detA);
        void insert(Matrix A);
        long key_exists(Matrix A);

};
HashTable::HashTable(void)
{
    root = new HT_Item;
    ş

}
