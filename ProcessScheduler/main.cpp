#include <iostream>
#include <fstream>
#include "Job.h"
#include "LinkList.h"
#include "FCFS.h"
#include "SJF.h"
#include "HPF.h"
using namespace std;

int main() {
    ifstream file("data.txt", ios::in);
    if(!file.is_open()) {
        cout << "data.txt can't open for read!" << endl;
        system("pause");
        exit(1);
    }
    char str[45];
    //将首行读出
    file.getline(str, 45);

    //作业表
    NodeList<Job> jobs;
    jobs.SetCompareFunction(jobSortArrivalTime);

    Job job;
    while(file >> job.jobId) {
        file >> job.arrivalTime;
        file >> job.executionTime;
        file >> job.priority;
        jobs.Insert(jobs.GetLength(), job, true);
    }
    file.close();

    //先来先服务
    cout << "******************* 开始模拟 FCFS 先来先服务 ********************\n\n";
    FCFS fcfs(jobs);
    fcfs.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";

    //短作业优先
    cout << "******************** 开始模拟 SJF 短作业优先 ********************\n\n";
    SJF sjf(jobs);
    sjf.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";

    //优先权高者优先
    cout << "****************** 开始模拟 HPF 优先权高者优先 ******************\n\n";
    HPF hpf(jobs);
    hpf.execute(cout);
    cout << '\n';
    cout << "*****************************************************************\n";
    system("pause");
    return 0;
}
