#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string LCS(string X, string Y, int m, int n) {
    if (m == 0 || n == 0)
        return "";

    if (X[m - 1] == Y[n - 1])
        return LCS(X, Y, m - 1, n - 1) + X[m - 1];
    else {
        string s1 = LCS(X, Y, m - 1, n);
        string s2 = LCS(X, Y, m, n - 1);
        return (s1.length() > s2.length()) ? s1 : s2;
    }
}

int main() {
    string X, Y;
    cout << "Enter first string: ";
    cin >> X;

    cout << "Enter second string: ";
    cin >> Y;

    int m = X.length();
    int n = Y.length();

    string lcs = LCS(X, Y, m, n);

    cout << "\nLength of Longest Common Subsequence: " << lcs.length() << endl;
    cout << "Longest Common Subsequence: " << lcs << endl;

    return 0;
}
