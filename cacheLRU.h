#ifndef cacheLRU_H_
#define cacheLRU_H_

#include <exception>
#inlcude "Splay.h"

using namespace std;


template<typename T0,typename T1>
class cacheLRU
{
    public:
        cacheLRU(int capacity):cap(capacity){n=0;time_del=0;}
        void put(  std::pair<  T0,T1>& keyT1Pair)
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
        std::pair<  T0,T1> get(  T0& key)
        {
            //查找key,找不到
            if(find(key)==NULL))//找不到就扔logic_error
            {
                throw logic_error("Not found");
                //throw logic_error exception
                return make_pair((T0)0,(T1)0);
            }
            return *it;
        }

    private:
        int cap;
        int n;
        int time_del;
    protected:
};


#endif
