#pragma once
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

//按到达时间排序函数
int jobSortArrivalTime(Job&, Job&);
