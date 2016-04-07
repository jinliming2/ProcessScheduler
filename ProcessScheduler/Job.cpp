#include "Job.h"
std::ostream & operator<<(std::ostream &output, Job &job) {
    output << "JobID:" << job.jobId
        << "\tArrivalTime:" << job.arrivalTime
        << "\t ExecutionTime:" << job.executionTime
        << "\tPriority:" << job.priority;
    return output;
}
//按到达时间排序函数
int jobSortArrivalTime(Job& left, Job& right) {
    int x = left.arrivalTime - right.arrivalTime;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
//按执行时间长短排序函数
int jobSortExecutionTime(Job& left, Job& right) {
    int x = left.executionTime - right.executionTime;
    return x < 0 ? -1 : x > 0 ? 1 : 0;
}
