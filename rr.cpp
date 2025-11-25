<<<<<<< HEAD
#include <iostream>
using namespace std;

void calculateHoldTime(int taskList[], int taskCount, int burstLen[], int holdTime[], int timeSlice) {
    int pending[100];
    for (int i = 0; i < taskCount; i++)
        pending[i] = burstLen[i];

    int clock = 0;
    while (true) {
        bool allDone = true;

        for (int i = 0; i < taskCount; i++) {
            if (pending[i] > 0) {
                allDone = false;

                if (pending[i] > timeSlice) {
                    clock += timeSlice;
                    pending[i] -= timeSlice;
                } else {
                    clock += pending[i];
                    holdTime[i] = clock - burstLen[i];
                    pending[i] = 0;
                }
            }
        }
        if (allDone) break;
    }
}

void calculateCompletionSpan(int taskList[], int taskCount, int burstLen[], int holdTime[], int turnaround[]) {
    for (int i = 0; i < taskCount; i++)
        turnaround[i] = burstLen[i] + holdTime[i];
}

void displayRoundRobinStats(int taskList[], int taskCount, int burstLen[], int timeSlice) {
    int holdTime[100], turnaround[100];
    int sumHold = 0, sumTurn = 0;

    calculateHoldTime(taskList, taskCount, burstLen, holdTime, timeSlice);
    calculateCompletionSpan(taskList, taskCount, burstLen, holdTime, turnaround);

    cout << "TaskID\tBurst\tHold\tTurnaround\n";
    for (int i = 0; i < taskCount; i++) {
        sumHold += holdTime[i];
        sumTurn += turnaround[i];
        cout << " " << taskList[i] << "\t" << burstLen[i]
             << "\t" << holdTime[i]
             << "\t" << turnaround[i] << "\n";
    }

    cout << "Average Hold (Waiting) Time = " << (float)sumHold / taskCount;
    cout << "\nAverage Turnaround Time = " << (float)sumTurn / taskCount;
}

int main() {
    int jobQueue[] = {1, 2, 3};
    int jobCount = sizeof(jobQueue) / sizeof(jobQueue[0]);
    int runBurst[] = {10, 5, 8};
    int quantumSlice = 2;

    displayRoundRobinStats(jobQueue, jobCount, runBurst, quantumSlice);
    return 0;
}
=======
#include <iostream>
using namespace std;

void calculateHoldTime(int taskList[], int taskCount, int burstLen[], int holdTime[], int timeSlice) {
    int pending[100];
    for (int i = 0; i < taskCount; i++)
        pending[i] = burstLen[i];

    int clock = 0;
    while (true) {
        bool allDone = true;

        for (int i = 0; i < taskCount; i++) {
            if (pending[i] > 0) {
                allDone = false;

                if (pending[i] > timeSlice) {
                    clock += timeSlice;
                    pending[i] -= timeSlice;
                } else {
                    clock += pending[i];
                    holdTime[i] = clock - burstLen[i];
                    pending[i] = 0;
                }
            }
        }
        if (allDone) break;
    }
}

void calculateCompletionSpan(int taskList[], int taskCount, int burstLen[], int holdTime[], int turnaround[]) {
    for (int i = 0; i < taskCount; i++)
        turnaround[i] = burstLen[i] + holdTime[i];
}

void displayRoundRobinStats(int taskList[], int taskCount, int burstLen[], int timeSlice) {
    int holdTime[100], turnaround[100];
    int sumHold = 0, sumTurn = 0;

    calculateHoldTime(taskList, taskCount, burstLen, holdTime, timeSlice);
    calculateCompletionSpan(taskList, taskCount, burstLen, holdTime, turnaround);

    cout << "TaskID\tBurst\tHold\tTurnaround\n";
    for (int i = 0; i < taskCount; i++) {
        sumHold += holdTime[i];
        sumTurn += turnaround[i];
        cout << " " << taskList[i] << "\t" << burstLen[i]
             << "\t" << holdTime[i]
             << "\t" << turnaround[i] << "\n";
    }

    cout << "Average Hold (Waiting) Time = " << (float)sumHold / taskCount;
    cout << "\nAverage Turnaround Time = " << (float)sumTurn / taskCount;
}

int main() {
    int jobQueue[] = {1, 2, 3};
    int jobCount = sizeof(jobQueue) / sizeof(jobQueue[0]);
    int runBurst[] = {10, 5, 8};
    int quantumSlice = 2;

    displayRoundRobinStats(jobQueue, jobCount, runBurst, quantumSlice);
    return 0;
}
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
