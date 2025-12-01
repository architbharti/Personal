#include <iostream>
using namespace std;

#define N 8  // You can change N to solve for any board size

int board[N][N];

// Function to print the chessboard
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed safely
bool isSafe(int row, int col) {
    int i, j;

    // Check this column on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive utility function to solve N-Queen problem
bool solveNQueens(int col) {
    if (col >= N)
        return true;

    // Try placing this queen in all rows one by one
    for (int row = 0; row < N; row++) {
        if (isSafe(row, col)) {
            board[row][col] = 1;  // Place the queen

            // Recur to place rest of the queens
            if (solveNQueens(col + 1))
                return true;

            // If placing queen in board[row][col] doesn't lead to a solution,
            // then backtrack
            board[row][col] = 0;
        }
    }

    // If queen cannot be placed in any row in this column, return false
    return false;
}

int main() {
    // Initialize board with 0s
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            board[i][j] = 0;

    if (solveNQueens(0))
        printBoard();
    else
        cout << "No solution exists" << endl;

    return 0;
}
