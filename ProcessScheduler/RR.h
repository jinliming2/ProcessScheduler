#pragma once
#include "LinkList.h"
#include "Job.h"
struct JobPack {
    Job job;
    unsigned int operated;
};
class RR {
public:
    //构造函数
    RR(NodeList<Job> jobs, unsigned int slice) : list(jobs), slice(slice) {
        list.SetCompareFunction(jobSortArrivalTime);
        list.Sort();
    }
    //执行
    void execute(std::ostream&);
private:
    NodeList<Job> list;
    //时间片
    unsigned int slice;
};
