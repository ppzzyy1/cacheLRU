#ifndef cacheLRU_H_
#define cacheLRU_H_

#include <exception>

using namespace std;


template<typename Key,typename Value>
class cacheLRU
{
    public:
        cacheLRU(int capacity):cap(capacity){n=0;time_del=0;}
        ~cacheLRU(){}
        void put(const std::pair<const Key,Value>& keyValuePair)
        {
            if(n==cap)
            {
                //这里capacity已经达到上线了
                //删除最远的leaf
                n--;
                time_del++;
            }
            //插入新值
            n++;
        }
        std::pair<const Key,Value> get(const Key& key)
        {
            //查找key,找不到
            if(it==SplayTree<Key,Value>::end())//找不到就扔logic_error
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
