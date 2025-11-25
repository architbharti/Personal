<<<<<<< HEAD
#include <iostream>                                                                                                                                                                                                                                      #include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int burstTime[n], priority[n], waitingTime[n], turnaroundTime[n], completionTime[n];
    int totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter burst time and priority for Process " << i + 1 << ": ";
        cin >> burstTime[i] >> priority[i];
    }

    // Using Bubble Sort to arrange processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priority
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap burst time
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time, Turnaround Time, and Waiting Time
    completionTime[0] = burstTime[0];
    turnaroundTime[0] = completionTime[0];
    waitingTime[0] = 0;  

    for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
        turnaroundTime[i] = completionTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    for (int i = 0; i < n; i++) {
        totalWT += waitingTime[i];
        totalTAT += turnaroundTime[i];
    }

    cout << "\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t"
             << burstTime[i] << "\t\t"
             << priority[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\t\t"
             << completionTime[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)totalWT / n;
    cout << "\nAverage Turnaround Time = " << (float)totalTAT / n;

    return 0;
=======
#include <iostream>                                                                                                                                                                                                                                      #include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter the number of processes: ";
    cin >> n;

    int burstTime[n], priority[n], waitingTime[n], turnaroundTime[n], completionTime[n];
    int totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter burst time and priority for Process " << i + 1 << ": ";
        cin >> burstTime[i] >> priority[i];
    }

    // Using Bubble Sort to arrange processes based on priority
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priority
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap burst time
                temp = burstTime[j];
                burstTime[j] = burstTime[j + 1];
                burstTime[j + 1] = temp;
            }
        }
    }

    // Calculate Completion Time, Turnaround Time, and Waiting Time
    completionTime[0] = burstTime[0];
    turnaroundTime[0] = completionTime[0];
    waitingTime[0] = 0;  

    for (int i = 1; i < n; i++) {
        completionTime[i] = completionTime[i - 1] + burstTime[i];
        turnaroundTime[i] = completionTime[i];
        waitingTime[i] = turnaroundTime[i] - burstTime[i];
    }

    for (int i = 0; i < n; i++) {
        totalWT += waitingTime[i];
        totalTAT += turnaroundTime[i];
    }

    cout << "\nProcess ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\tCompletion Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t\t"
             << burstTime[i] << "\t\t"
             << priority[i] << "\t\t"
             << waitingTime[i] << "\t\t"
             << turnaroundTime[i] << "\t\t"
             << completionTime[i] << endl;
    }

    cout << "\nAverage Waiting Time = " << (float)totalWT / n;
    cout << "\nAverage Turnaround Time = " << (float)totalTAT / n;

    return 0;
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
}