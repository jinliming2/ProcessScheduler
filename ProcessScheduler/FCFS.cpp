#include "FCFS.h"
//执行
void FCFS::execute(std::ostream & output) {
    if(list.GetLength() == 0) {
        output << "任务表为空！\n";
        return;
    }
    Job job;
    //当前时间，总数
    unsigned int now = 0, total = 0;
    //总等待时间，总周转时间，总带权周转时间
    double totalWait = 0, totalTurnover = 0, totalRightTurnover = 0;
    while(list.GetLength() > 0) {
        list.Find(0, job);
        if(now < job.arrivalTime) {
            now = job.arrivalTime;
        }
        now += job.executionTime;
        output << "执行完的作业：" << job
            << "\n等待时间：" << (now - job.executionTime - job.arrivalTime)
            << "\t周转时间：" << (now - job.arrivalTime)
            << "\t带权周转时间：" << (double(now - job.arrivalTime) / job.executionTime)
            << "\n";
        total++;
        totalWait += now - job.executionTime - job.arrivalTime;
        totalTurnover += now - job.arrivalTime;
        totalRightTurnover += double(now - job.arrivalTime) / job.executionTime;
        list.Delete(0);
    }
    output << "\n平均等待时间：" << (totalWait / total)
        << "\t平均周转时间：" << (totalTurnover / total)
        << "\t平均带权周转时间：" << (totalRightTurnover / total)
        << "\n";
}
