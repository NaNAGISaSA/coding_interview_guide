#ifndef _CODING_INTERVIEW_GUIDE_OTHER_PROBLEMS_DESIGN_LFU_STRUCT_H_
#define _CODING_INTERVIEW_GUIDE_OTHER_PROBLEMS_DESIGN_LFU_STRUCT_H_

/*
【题目】
一个缓存结构需要实现如下功能。
set(key, value)：将记录(key, value)插入该结构
get(key)：返回key对应的value值
但是缓存结构中最多放K条记录，如果新的第K+1条记录要加入，就需要根据策略删掉一条记录，然后才能把新记录加入。
这个策略为：在缓存结构的K条记录中，哪一个key从进入缓存结构的时刻开始，被调用set或者get的次数最少，就删掉这个key的记录；
如果调用次数最少的key有多个，上次调用发生最早的key被删除。这就是LFU缓存替换算法。
【要求】
set和get方法的时间复杂度为O(1)。
*/

#include <memory>

namespace coding_interview_guide::other_problems::design_lfu_struct {

class LFUCache {
public:
    LFUCache(size_t);
    ~LFUCache();

    void set(int key, int value);
    int get(int key);

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl;
};

}  // namespace coding_interview_guide::other_problems::design_lfu_struct

#endif
