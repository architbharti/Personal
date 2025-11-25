<<<<<<< HEAD
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int totalJobs;
    cout << "Enter number of processes: ";
    cin >> totalJobs;

    int jobId[totalJobs], entryTime[totalJobs], runTime[totalJobs];
    int finishTime[totalJobs], cycleTime[totalJobs], delayTime[totalJobs];

    
    for (int k = 0; k < totalJobs; k++) {
        jobId[k] = k + 1;
        cout << "Enter Arrival time of process " << jobId[k] << ": ";
        cin >> entryTime[k];
        cout << "Enter Burst time of process " << jobId[k] << ": ";
        cin >> runTime[k];
    }

   
    for (int x = 0; x < totalJobs - 1; x++) {
        for (int y = x + 1; y < totalJobs; y++) {
            if (entryTime[x] > entryTime[y]) {
                swap(entryTime[x], entryTime[y]);
                swap(runTime[x], runTime[y]);
                swap(jobId[x], jobId[y]);
            }
        }
    }

    // Calculate Finish Time, Turnaround, and Waiting
    int cpuClock = 0;
    for (int p = 0; p < totalJobs; p++) {
        if (cpuClock < entryTime[p]) {
            cpuClock = entryTime[p]; 
        }
        cpuClock += runTime[p];
        finishTime[p] = cpuClock;
        cycleTime[p] = finishTime[p] - entryTime[p];  
        delayTime[p] = cycleTime[p] - runTime[p];      
    }

    
    cout << "\nFCFS Scheduling Results:\n";
    cout << "JID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int m = 0; m < totalJobs; m++) {
        cout << jobId[m] << "\t" << entryTime[m] << "\t" << runTime[m]
             << "\t" << finishTime[m] << "\t" << cycleTime[m]
             << "\t" << delayTime[m] << "\n";
    }

    double avgCycle = 0, avgDelay = 0;
    for (int q = 0; q < totalJobs; q++) {
        avgCycle += cycleTime[q];
        avgDelay += delayTime[q];
    }
    avgCycle /= totalJobs;
    avgDelay /= totalJobs;

    cout << "\nAverage Turnaround Time: " << avgCycle;
    cout << "\nAverage Waiting Time: " << avgDelay << "\n";

    return 0;
}



=======
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int totalJobs;
    cout << "Enter number of processes: ";
    cin >> totalJobs;

    int jobId[totalJobs], entryTime[totalJobs], runTime[totalJobs];
    int finishTime[totalJobs], cycleTime[totalJobs], delayTime[totalJobs];

    
    for (int k = 0; k < totalJobs; k++) {
        jobId[k] = k + 1;
        cout << "Enter Arrival time of process " << jobId[k] << ": ";
        cin >> entryTime[k];
        cout << "Enter Burst time of process " << jobId[k] << ": ";
        cin >> runTime[k];
    }

   
    for (int x = 0; x < totalJobs - 1; x++) {
        for (int y = x + 1; y < totalJobs; y++) {
            if (entryTime[x] > entryTime[y]) {
                swap(entryTime[x], entryTime[y]);
                swap(runTime[x], runTime[y]);
                swap(jobId[x], jobId[y]);
            }
        }
    }

    // Calculate Finish Time, Turnaround, and Waiting
    int cpuClock = 0;
    for (int p = 0; p < totalJobs; p++) {
        if (cpuClock < entryTime[p]) {
            cpuClock = entryTime[p]; 
        }
        cpuClock += runTime[p];
        finishTime[p] = cpuClock;
        cycleTime[p] = finishTime[p] - entryTime[p];  
        delayTime[p] = cycleTime[p] - runTime[p];      
    }

    
    cout << "\nFCFS Scheduling Results:\n";
    cout << "JID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int m = 0; m < totalJobs; m++) {
        cout << jobId[m] << "\t" << entryTime[m] << "\t" << runTime[m]
             << "\t" << finishTime[m] << "\t" << cycleTime[m]
             << "\t" << delayTime[m] << "\n";
    }

    double avgCycle = 0, avgDelay = 0;
    for (int q = 0; q < totalJobs; q++) {
        avgCycle += cycleTime[q];
        avgDelay += delayTime[q];
    }
    avgCycle /= totalJobs;
    avgDelay /= totalJobs;

    cout << "\nAverage Turnaround Time: " << avgCycle;
    cout << "\nAverage Waiting Time: " << avgDelay << "\n";

    return 0;
}



>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
