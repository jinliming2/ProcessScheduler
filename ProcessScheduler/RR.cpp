#include "RR.h"
//执行
void RR::execute(std::ostream & output) {
    if(list.GetLength() == 0) {
        output << "任务表为空！\n";
        return;
    }
    Job job;
    NodeList<JobPack> arrived;
    JobPack jp;
    //当前时间，总数
    unsigned int now = 0, total = 0;
    //总等待时间，总周转时间，总带权周转时间
    double totalWait = 0, totalTurnover = 0, totalRightTurnover = 0;
    while(list.GetLength() > 0 || arrived.GetLength() > 0) {
        while(list.GetLength() > 0) {
            list.Find(0, job);
            if(job.arrivalTime <= now) {
                //已到达的列表，不排序
                arrived.Insert(arrived.GetLength(), { job, 0 });
                list.Delete(0);
                continue;
            }
            break;
        }
        if(now != 0 && jp.job.executionTime > jp.operated) {
            arrived.Insert(arrived.GetLength(), jp);
        }
        if(now < job.arrivalTime && arrived.GetLength() == 0) {
            now = job.arrivalTime;
            arrived.Insert(arrived.GetLength(), { job, 0 });
            list.Delete(0);
        }
        arrived.Find(0, jp);
        arrived.Delete(0);
        job = jp.job;
        if(job.executionTime - jp.operated < slice) {
            now += job.executionTime - jp.operated;
            output << job.jobId << " 号作业执行了 " << (job.executionTime - jp.operated) << "\n";
            jp.operated = job.executionTime;
        } else {
            now += slice;
            output << job.jobId << " 号作业执行了 " << slice << "\n";
            jp.operated += slice;
        }
        if(job.executionTime == jp.operated) {
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
    }
    output << "\n平均等待时间：" << (totalWait / total)
        << "\t平均周转时间：" << (totalTurnover / total)
        << "\t平均带权周转时间：" << (totalRightTurnover / total)
        << "\n";
}
