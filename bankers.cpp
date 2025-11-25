<<<<<<< HEAD
#include <iostream>
#include <vector>

using namespace std;

const int P = 5;
const int R = 3;

void printMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << "\n" << name << " Matrix:\n";
    cout << "   ";
    for(int j = 0; j < R; ++j) {
        cout << " R" << j << " ";
    }
    cout << "\n";
    for (int i = 0; i < P; ++i) {
        cout << "P" << i << " ";
        for (int j = 0; j < R; ++j) {
            cout << " " << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
}

void printVector(const vector<int>& vec, const string& name) {
    cout << "\n" << name << " Vector:\n";
    for (int j = 0; j < R; ++j) {
        cout << " R" << j << " ";
    }
    cout << "\n";
    for (int j = 0; j < R; ++j) {
        cout << " " << vec[j] << "  ";
    }
    cout << "\n";
}

bool isSafe(int p, int r, vector<vector<int>>& alloc, vector<vector<int>>& need, vector<int>& avail) {
    
    vector<int> work = avail;
    
    vector<bool> finish(p, false);
    
    vector<int> safeSeq;
    
    int count = 0; 
    
    while (count < p) {
        bool found = false; 
        
        for (int i = 0; i < p; ++i) {
            if (finish[i] == false) {
                
                int j;
                for (j = 0; j < r; ++j) {
                    if (need[i][j] > work[j]) {
                        break; 
                    }
                }
                
                if (j == r) {
                    for (int k = 0; k < r; ++k) {
                        work[k] += alloc[i][k];
                    }
                    
                    finish[i] = true;
                    
                    safeSeq.push_back(i);
                    
                    found = true;
                    
                    count++;
                }
            }
        } 
        
        if (found == false) {
            cout << "\nSystem is in an UNSAFE state." << endl;
            cout << "Deadlock may occur as no process can finish." << endl;
            return false;
        }
    } 
    
    cout << "\nSystem is in a SAFE state." << endl;
    cout << "Safe Sequence is: < ";
    for (int i = 0; i < safeSeq.size(); ++i) {
        cout << "P" << safeSeq[i] << (i == safeSeq.size() - 1 ? " >" : ", ");
    }
    cout << endl;
    return true;
}


int main() {
    
    vector<vector<int>> alloc = { {0, 1, 0},
                                  {2, 0, 0},
                                  {3, 0, 2},
                                  {2, 1, 1},
                                  {0, 0, 2} };
    
    vector<vector<int>> max = { {7, 5, 3},
                                {3, 2, 2},
                                {9, 0, 2},
                                {2, 2, 2},
                                {4, 3, 3} };
    
    vector<int> avail = {3, 3, 2};
    
    vector<vector<int>> need(P, vector<int>(R));
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    cout << "--- Initial System State ---" << endl;
    printMatrix(alloc, "Allocation");
    printMatrix(max, "Max");
    printMatrix(need, "Need");
    printVector(avail, "Available");
    
    isSafe(P, R, alloc, need, avail);
    
    return 0;
=======
#include <iostream>
#include <vector>

using namespace std;

const int P = 5;
const int R = 3;

void printMatrix(const vector<vector<int>>& matrix, const string& name) {
    cout << "\n" << name << " Matrix:\n";
    cout << "   ";
    for(int j = 0; j < R; ++j) {
        cout << " R" << j << " ";
    }
    cout << "\n";
    for (int i = 0; i < P; ++i) {
        cout << "P" << i << " ";
        for (int j = 0; j < R; ++j) {
            cout << " " << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
}

void printVector(const vector<int>& vec, const string& name) {
    cout << "\n" << name << " Vector:\n";
    for (int j = 0; j < R; ++j) {
        cout << " R" << j << " ";
    }
    cout << "\n";
    for (int j = 0; j < R; ++j) {
        cout << " " << vec[j] << "  ";
    }
    cout << "\n";
}

bool isSafe(int p, int r, vector<vector<int>>& alloc, vector<vector<int>>& need, vector<int>& avail) {
    
    vector<int> work = avail;
    
    vector<bool> finish(p, false);
    
    vector<int> safeSeq;
    
    int count = 0; 
    
    while (count < p) {
        bool found = false; 
        
        for (int i = 0; i < p; ++i) {
            if (finish[i] == false) {
                
                int j;
                for (j = 0; j < r; ++j) {
                    if (need[i][j] > work[j]) {
                        break; 
                    }
                }
                
                if (j == r) {
                    for (int k = 0; k < r; ++k) {
                        work[k] += alloc[i][k];
                    }
                    
                    finish[i] = true;
                    
                    safeSeq.push_back(i);
                    
                    found = true;
                    
                    count++;
                }
            }
        } 
        
        if (found == false) {
            cout << "\nSystem is in an UNSAFE state." << endl;
            cout << "Deadlock may occur as no process can finish." << endl;
            return false;
        }
    } 
    
    cout << "\nSystem is in a SAFE state." << endl;
    cout << "Safe Sequence is: < ";
    for (int i = 0; i < safeSeq.size(); ++i) {
        cout << "P" << safeSeq[i] << (i == safeSeq.size() - 1 ? " >" : ", ");
    }
    cout << endl;
    return true;
}


int main() {
    
    vector<vector<int>> alloc = { {0, 1, 0},
                                  {2, 0, 0},
                                  {3, 0, 2},
                                  {2, 1, 1},
                                  {0, 0, 2} };
    
    vector<vector<int>> max = { {7, 5, 3},
                                {3, 2, 2},
                                {9, 0, 2},
                                {2, 2, 2},
                                {4, 3, 3} };
    
    vector<int> avail = {3, 3, 2};
    
    vector<vector<int>> need(P, vector<int>(R));
    for (int i = 0; i < P; ++i) {
        for (int j = 0; j < R; ++j) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }
    
    cout << "--- Initial System State ---" << endl;
    printMatrix(alloc, "Allocation");
    printMatrix(max, "Max");
    printMatrix(need, "Need");
    printVector(avail, "Available");
    
    isSafe(P, R, alloc, need, avail);
    
    return 0;
>>>>>>> 4f0791a9bf5604156f7b7ebeee0052d4ac8531ca
}