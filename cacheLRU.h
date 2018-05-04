#ifndef cacheLRU_H_
#define cacheLRU_H_

#include "splayTree.h"
#include <exception>

using namespace std;


template<typename Key,typename Value>
class cacheLRU:public SplayTree<Key,Value>
{
    public:
        cacheLRU(int capacity):cap(capacity){n=0;time_del=0;}
        ~cacheLRU(){}
        void put(const std::pair<const Key,Value>& keyValuePair)
        {
            if(n==cap)
            {
                SplayTree<Key,Value>::deleteMinLeaf();
                n--;
                time_del++;
            }
            SplayTree<Key,Value>::insert(keyValuePair);
            n++;
        }
        std::pair<const Key,Value> get(const Key& key)
        {
            typename SplayTree<Key,Value>::iterator it=SplayTree<Key,Value>::find(key);
            if(it==SplayTree<Key,Value>::end())
            {
                throw logic_error("Not found");
                //throw logic_error exception
                return make_pair((Key)0,(Value)0);
            }
            return *it;
        }
    private:
        int cap;
        int n;
    protected:
};


#endif
