#include "Job.h"
//按到达时间排序函数
int jobSortArrivalTime(Job& left, Job& right) {
    return left.arrivalTime < right.arrivalTime ? -1 : 1;
}
