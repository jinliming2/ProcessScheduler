#include <iostream>
#include <fstream>
#include "Job.h"
#include "LinkList.cpp"  //模板类，需要包含源文件cpp，包含头文件h会不通过
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
    jobs.Print(cout);
    system("pause");
    return 0;
}
