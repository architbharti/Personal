<<<<<<< HEAD
#include <iostream>
#include <climits>
using namespace std;

// Compute queue delays using SRJF (preemptive SJF)
void computeQueueDelaySRJF(int jobList[], int jobCount, int execTime[], int entryTime[], int waitList[]) {
    int remaining[100]; // remaining execution time
    for (int i = 0; i < jobCount; ++i) remaining[i] = execTime[i];

    int completed = 0, tick = 0, current = -1;
    int smallest = INT_MAX;
    bool available = false;

    int endTime[100] = {0}; // finish times

    while (completed != jobCount) {
        // Find job with minimum remaining time among arrived ones
        smallest = INT_MAX;
        available = false;

        for (int j = 0; j < jobCount; ++j) {
            if (entryTime[j] <= tick && remaining[j] > 0) {
                if (remaining[j] < smallest || 
                   (remaining[j] == smallest && jobList[j] < jobList[current])) {
                    smallest = remaining[j];
                    current = j;
                    available = true;
                }
            }
        }

        if (!available) { tick++; continue; }

        remaining[current]--;

        if (remaining[current] == 0) {
            completed++;
            endTime[current] = tick + 1;
            // Waiting = finish - execution - arrival
            waitList[current] = endTime[current] - execTime[current] - entryTime[current];
            if (waitList[current] < 0) waitList[current] = 0; // guard against negatives
        }
        tick++;
    }
}

void computeLifeSpan(int jobList[], int jobCount, int execTime[], int waitList[], int lifeSpan[]) {
    for (int i = 0; i < jobCount; i++)
        lifeSpan[i] = execTime[i] + waitList[i];
}

void showAverageStatsSRJF(int jobList[], int jobCount, int execTime[], int entryTime[]) {
    int waitList[100], lifeSpan[100];
    long long totalWait = 0, totalSpan = 0;

    computeQueueDelaySRJF(jobList, jobCount, execTime, entryTime, waitList);
    computeLifeSpan(jobList, jobCount, execTime, waitList, lifeSpan);

    cout << "JobID " << " ArrTime " << " RunTime "
         << " Wait " << " TurnAround\n";

    for (int i = 0; i < jobCount; i++) {
        totalWait += waitList[i];
        totalSpan += lifeSpan[i];
        cout << " " << jobList[i]
             << "\t " << entryTime[i]
             << "\t " << execTime[i]
             << "\t " << waitList[i]
             << "\t " << lifeSpan[i] << "\n";
    }

    cout << "Average Waiting Time = " << (double)totalWait / jobCount << "\n";
    cout << "Average Turnaround Time = " << (double)totalSpan / jobCount << "\n";
}

int main() {
    int jobList[] = {1, 2, 3};
    int jobCount = sizeof(jobList) / sizeof(jobList[0]);
    int runDurations[] = {6, 2, 8};
    int entryTimes[] = {0, 1, 2};

    showAverageStatsSRJF(jobList, jobCount, runDurations, entryTimes);
    return 0;
}
=======
#include <iostream>
#include <climits>
using namespace std;

// Compute queue delays using SRJF (preemptive SJF)
void computeQueueDelaySRJF(int jobList[], int jobCount, int execTime[], int entryTime[], int waitList[]) {
    int remaining[100]; // remaining execution time
    for (int i = 0; i < jobCount; ++i) remaining[i] = execTime[i];

    int completed = 0, tick = 0, current = -1;
    int smallest = INT_MAX;
    bool available = false;

    int endTime[100] = {0}; // finish times

    while (completed != jobCount) {
        // Find job with minimum remaining time among arrived ones
        smallest = INT_MAX;
        available = false;

        for (int j = 0; j < jobCount; ++j) {
            if (entryTime[j] <= tick && remaining[j] > 0) {
                if (remaining[j] < smallest || 
                   (remaining[j] == smallest && jobList[j] < jobList[current])) {
                    smallest = remaining[j];
                    current = j;
                    available = true;
                }
            }
        }

        if (!available) { tick++; continue; }

        remaining[current]--;

        if (remaining[current] == 0) {
            completed++;
            endTime[current] = tick + 1;
            // Waiting = finish - execution - arrival
            waitList[current] = endTime[current] - execTime[current] - entryTime[current];
            if (waitList[current] < 0) waitList[current] = 0; // guard against negatives
        }
        tick++;
    }
}

void computeLifeSpan(int jobList[], int jobCount, int execTime[], int waitList[], int lifeSpan[]) {
    for (int i = 0; i < jobCount; i++)
        lifeSpan[i] = execTime[i] + waitList[i];
}

void showAverageStatsSRJF(int jobList[], int jobCount, int execTime[], int entryTime[]) {
    int waitList[100], lifeSpan[100];
    long long totalWait = 0, totalSpan = 0;

    computeQueueDelaySRJF(jobList, jobCount, execTime, entryTime, waitList);
    computeLifeSpan(jobList, jobCount, execTime, waitList, lifeSpan);

    cout << "JobID " << " ArrTime " << " RunTime "
         << " Wait " << " TurnAround\n";

    for (int i = 0; i < jobCount; i++) {
        totalWait += waitList[i];
        totalSpan += lifeSpan[i];
        cout << " " << jobList[i]
             << "\t " << entryTime[i]
             << "\t " << execTime[i]
             << "\t " << waitList[i]
             << "\t " << lifeSpan[i] << "\n";
    }

    cout << "Average Waiting Time = " << (double)totalWait / jobCount << "\n";
    cout << "Average Turnaround Time = " << (double)totalSpan / jobCount << "\n";
}

int main() {
    int jobList[] = {1, 2, 3};
    int jobCount = sizeof(jobList) / sizeof(jobList[0]);
    int runDurations[] = {6, 2, 8};
    int entryTimes[] = {0, 1, 2};

    showAverageStatsSRJF(jobList, jobCount, runDurations, entryTimes);
    return 0;
}
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
