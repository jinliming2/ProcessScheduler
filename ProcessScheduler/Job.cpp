#include "Job.h"
std::ostream & operator<<(std::ostream &output, Job &job) {
    output << "JobID:" << job.jobId
        << "\tArrivalTime:" << job.arrivalTime
        << "\tExecutionTime:" << job.executionTime
        << "\tPriority:" << job.priority;
    return output;
}
//按到达时间排序函数
int jobSortArrivalTime(Job& left, Job& right) {
    return left.arrivalTime < right.arrivalTime ? -1 : 1;
}
