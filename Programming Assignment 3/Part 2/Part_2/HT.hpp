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
        HT_Item *root[65536];
        long hash(Matrix M);
        HashTable(void);
        int count=0;
        long search(Matrix A);
        void insert(Matrix A,long detA);
        bool key_exists(Matrix A);
        bool is_full();

};
HashTable::HashTable(void)
{
    for(int i=0;i<65536;i++)
    {
        root[i]=nullptr;
    }

}
bool HashTable::is_full()
{
    if(count==65536);
        return true;
    return false;
}
long HashTable::hash(Matrix M){

    long hash_value = M.N;
  for (int i = 0; i < M.N; i++) {
    for (int j = 0; j < M.N; j++) {
      hash_value = (hash_value * 61 + M.get_element(i,j))% 65536;
    }
  }
  return hash_value ;
}
bool HashTable::key_exists(Matrix A)
{
    int hash_value=hash(A),counter=0;
    if(root[hash_value]==nullptr)
    {
        return false;
    }
    if(root[hash_value]->key==A)
    {
        return true;
    }
    while(root[hash_value]!=nullptr)
    {
        if(root[hash_value]->key == A)
        {
            return true;
        }
        counter++;
        hash_value++;
        if(hash_value==65535)
            hash_value=0;
        if(counter==65536)
            return false;
    }
    return false;
}
long HashTable::search(Matrix M)
{
    int hash_value=hash(M),counter=0;
    if(root[hash_value]==nullptr)
    {
        return false;
    }
    if(root[hash_value]->key==M)
    {
        return root[hash_value]->value;
    }

    while(root[hash_value]!=nullptr)
    {
        if(root[hash_value]->key == M)
        {
            return root[hash_value]->value;
        }

        counter++;
        hash_value++;
        if(hash_value==65535)
            hash_value=0;
        if(counter==65536)
            return false;

    }
    return false;
}
void HashTable::insert(Matrix A,long detA)
{
    long hash_value = hash(A),counter=0;
    if(root[hash_value]==nullptr)
    {
        root[hash_value]=new HT_Item{A,detA};
        count++;
        return;
    }
    if(key_exists(A))
        return;
    if(root[hash_value] != nullptr)
    {
        while(root[hash_value]!=nullptr)
        {
            hash_value++;
        }
        root[hash_value]=new HT_Item{A,detA};
        count++;
    }

}
