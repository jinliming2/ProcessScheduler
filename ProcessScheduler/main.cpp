#include <iostream>
#include <fstream>
#include "Job.h"
#include "LinkList.h"
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
    Job job;
    while(file >> job.jobId) {
        file >> job.arrivalTime;
        file >> job.executionTime;
        file >> job.priority;
    }
    file.close();
    system("pause");
    return 0;
}
