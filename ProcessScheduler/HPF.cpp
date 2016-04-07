#include "HPF.h"
//执行
void HPF::execute(std::ostream & output) {
    if(list.GetLength() == 0) {
        output << "任务表为空！\n";
        return;
    }
    Job job;
    NodeList<Job> arrived;
    arrived.SetCompareFunction(jobSortPriority);
    //当前时间，总数
    unsigned int now = 0, total = 0;
    //总等待时间，总周转时间，总带权周转时间
    double totalWait = 0, totalTurnover = 0, totalRightTurnover = 0;
    while(list.GetLength() > 0 || arrived.GetLength() > 0) {
        while(list.GetLength() > 0) {
            list.Find(0, job);
            if(job.arrivalTime <= now) {
                //已到达的列表，按执行时间长短排序
                arrived.Insert(arrived.GetLength(), job, true);
                list.Delete(0);
                continue;
            }
            break;
        }
        if(now < job.arrivalTime && arrived.GetLength() == 0) {
            now = job.arrivalTime;
            list.Delete(0);
        } else {
            arrived.Find(0, job);
            arrived.Delete(0);
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
    }
    output << "\n平均等待时间：" << (totalWait / total)
        << "\t平均周转时间：" << (totalTurnover / total)
        << "\t平均带权周转时间：" << (totalRightTurnover / total)
        << "\n";
}
