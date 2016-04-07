#pragma once
#include <iostream>
struct Job {
    //作业ID
    unsigned int jobId;
    //到达时间
    unsigned int arrivalTime;
    //执行时间
    unsigned int executionTime;
    //优先权
    unsigned int priority;
};

//输出流重载
std::ostream& operator<<(std::ostream &, Job&);

//按到达时间排序函数
int jobSortArrivalTime(Job&, Job&);

//按执行时间长短排序函数
int jobSortExecutionTime(Job&, Job&);
