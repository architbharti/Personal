<<<<<<< HEAD
#include <iostream>
using namespace std;

void arrangeByRunTime(int taskID[], int runLength[], int totalTasks) {
    for (int a = 0; a < totalTasks - 1; ++a) {
        for (int b = 0; b < totalTasks - 1 - a; ++b) {
            if (runLength[b] > runLength[b + 1] ||
               (runLength[b] == runLength[b + 1] && taskID[b] > taskID[b + 1])) {
                swap(runLength[b], runLength[b + 1]);
                swap(taskID[b], taskID[b + 1]); }
        }  }  }

void IdleTime(int taskID[], int totalTasks, int runLength[], int idleTime[]) {
    idleTime[0] = 0;
    for (int t = 1; t < totalTasks; t++) {
        idleTime[t] = runLength[t - 1] + idleTime[t - 1];
    } }

void CompletionSpan(int taskID[], int totalTasks, int runLength[], int idleTime[], int cycleSpan[]) {
    for (int t = 0; t < totalTasks; t++) {
        cycleSpan[t] = runLength[t] + idleTime[t];
    }
}

// Driver function to display results
void displayAverageTimes(int taskID[], int totalTasks, int runLength[]) {
    arrangeByRunTime(taskID, runLength, totalTasks);

    int idleTime[100], cycleSpan[100]; 
    int sumIdle = 0, sumCycle = 0;

    IdleTime(taskID, totalTasks, runLength, idleTime);
    CompletionSpan(taskID, totalTasks, runLength, idleTime, cycleSpan);

    cout << "TaskID " << " RunLength "
         << " IdleTime " << " CompletionSpan\n";

    for (int t = 0; t < totalTasks; t++) {
        sumIdle += idleTime[t];
        sumCycle += cycleSpan[t];
        cout << " " << taskID[t] << "\t\t" << runLength[t] << "\t "
             << idleTime[t] << "\t\t " << cycleSpan[t] << "\n";
    }

    cout << "Average Idle (Waiting) Time = "
         << (float)sumIdle / (float)totalTasks;
    cout << "\nAverage Completion (Turnaround) Time = "
         << (float)sumCycle / (float)totalTasks << "\n";
}

int main() {
    int jobList[] = {1, 2, 3};
    int taskCount = sizeof(jobList) / sizeof(jobList[0]);
    int runDuration[] = {10, 5, 8};

    displayAverageTimes(jobList, taskCount, runDuration);
    return 0;
}
=======
#include <iostream>
using namespace std;

void arrangeByRunTime(int taskID[], int runLength[], int totalTasks) {
    for (int a = 0; a < totalTasks - 1; ++a) {
        for (int b = 0; b < totalTasks - 1 - a; ++b) {
            if (runLength[b] > runLength[b + 1] ||
               (runLength[b] == runLength[b + 1] && taskID[b] > taskID[b + 1])) {
                swap(runLength[b], runLength[b + 1]);
                swap(taskID[b], taskID[b + 1]); }
        }  }  }

void IdleTime(int taskID[], int totalTasks, int runLength[], int idleTime[]) {
    idleTime[0] = 0;
    for (int t = 1; t < totalTasks; t++) {
        idleTime[t] = runLength[t - 1] + idleTime[t - 1];
    } }

void CompletionSpan(int taskID[], int totalTasks, int runLength[], int idleTime[], int cycleSpan[]) {
    for (int t = 0; t < totalTasks; t++) {
        cycleSpan[t] = runLength[t] + idleTime[t];
    }
}

// Driver function to display results
void displayAverageTimes(int taskID[], int totalTasks, int runLength[]) {
    arrangeByRunTime(taskID, runLength, totalTasks);

    int idleTime[100], cycleSpan[100]; 
    int sumIdle = 0, sumCycle = 0;

    IdleTime(taskID, totalTasks, runLength, idleTime);
    CompletionSpan(taskID, totalTasks, runLength, idleTime, cycleSpan);

    cout << "TaskID " << " RunLength "
         << " IdleTime " << " CompletionSpan\n";

    for (int t = 0; t < totalTasks; t++) {
        sumIdle += idleTime[t];
        sumCycle += cycleSpan[t];
        cout << " " << taskID[t] << "\t\t" << runLength[t] << "\t "
             << idleTime[t] << "\t\t " << cycleSpan[t] << "\n";
    }

    cout << "Average Idle (Waiting) Time = "
         << (float)sumIdle / (float)totalTasks;
    cout << "\nAverage Completion (Turnaround) Time = "
         << (float)sumCycle / (float)totalTasks << "\n";
}

int main() {
    int jobList[] = {1, 2, 3};
    int taskCount = sizeof(jobList) / sizeof(jobList[0]);
    int runDuration[] = {10, 5, 8};

    displayAverageTimes(jobList, taskCount, runDuration);
    return 0;
}
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
