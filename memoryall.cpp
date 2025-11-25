<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);           
    vector<int> tempBlocks(blockSize, blockSize + m);   

    for (int i = 0; i < n; i++) {             
        for (int j = 0; j < m; j++) {         
            if (tempBlocks[j] >= processSize[i]) {
                allocation[i] = j;           
                tempBlocks[j] -= processSize[i];
                break;                       
            }
        }
    }

    cout << "\nFirst Fit Allocation\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << '\n';
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);
    vector<int> tempBlocks(blockSize, blockSize + m);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;

        for (int j = 0; j < m; j++) {
            if (tempBlocks[j] >= processSize[i]) {
                if (bestIdx == -1 || tempBlocks[j] < tempBlocks[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            tempBlocks[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << '\n';
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);
    vector<int> tempBlocks(blockSize, blockSize + m);

    for (int i = 0; i < n; i++) {
        int wstIdx = -1;

        for (int j = 0; j < m; j++) {
            if (tempBlocks[j] >= processSize[i]) {
                if (wstIdx == -1 || tempBlocks[j] > tempBlocks[wstIdx])
                    wstIdx = j;
            }
        }

        if (wstIdx != -1) {
            allocation[i] = wstIdx;
            tempBlocks[wstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << '\n';
    }
}

int main() {
    int blockSize[]   = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);

    return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;

void firstFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);           
    vector<int> tempBlocks(blockSize, blockSize + m);   

    for (int i = 0; i < n; i++) {             
        for (int j = 0; j < m; j++) {         
            if (tempBlocks[j] >= processSize[i]) {
                allocation[i] = j;           
                tempBlocks[j] -= processSize[i];
                break;                       
            }
        }
    }

    cout << "\nFirst Fit Allocation\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << '\n';
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);
    vector<int> tempBlocks(blockSize, blockSize + m);

    for (int i = 0; i < n; i++) {
        int bestIdx = -1;

        for (int j = 0; j < m; j++) {
            if (tempBlocks[j] >= processSize[i]) {
                if (bestIdx == -1 || tempBlocks[j] < tempBlocks[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            tempBlocks[bestIdx] -= processSize[i];
        }
    }

    cout << "\nBest Fit Allocation\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << '\n';
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n) {
    vector<int> allocation(n, -1);
    vector<int> tempBlocks(blockSize, blockSize + m);

    for (int i = 0; i < n; i++) {
        int wstIdx = -1;

        for (int j = 0; j < m; j++) {
            if (tempBlocks[j] >= processSize[i]) {
                if (wstIdx == -1 || tempBlocks[j] > tempBlocks[wstIdx])
                    wstIdx = j;
            }
        }

        if (wstIdx != -1) {
            allocation[i] = wstIdx;
            tempBlocks[wstIdx] -= processSize[i];
        }
    }

    cout << "\nWorst Fit Allocation\n";
    cout << "Process No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < n; i++) {
        cout << "   " << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << '\n';
    }
}

int main() {
    int blockSize[]   = {100, 500, 200, 300, 600};
    int processSize[] = {212, 417, 112, 426};

    int m = sizeof(blockSize) / sizeof(blockSize[0]);
    int n = sizeof(processSize) / sizeof(processSize[0]);

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);

    return 0;
}
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
