#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Find the common prefix of all productions
string commonPrefix(const vector<string> &prods) {
    if (prods.empty()) return "";

    string prefix = prods[0];

    for (size_t i = 1; i < prods.size(); i++) {
        int j = 0;
        while (j < (int)prefix.size() && j < (int)prods[i].size() && prefix[j] == prods[i][j]) {
            j++;
        }
        prefix = prefix.substr(0, j);
        if (prefix.empty()) break;
    }

    return prefix;
}

// Perform left factoring for a single non-terminal
void leftFactor(const string &nt, const vector<string> &prods) {
    string prefix = commonPrefix(prods);

    // If no common prefix or only one production, nothing to factor
    if (prefix.empty() || prods.size() == 1) {
        for (auto &p : prods) {
            cout << nt << " -> " << p << endl;
        }
        return;
    }

    // Create new non-terminal (A')
    string newNt = nt + "'";

    // Print factored production: A -> prefix A'
    cout << nt << " -> " << prefix << newNt << endl;

    // Build productions for A'
    vector<string> newProds;
    for (auto &p : prods) {
        string suffix = p.substr(prefix.size());
        if (suffix.empty()) suffix = "ε";  // epsilon for empty string
        newProds.push_back(suffix);
    }

    // Print A' productions
    for (auto &p : newProds) {
        cout << newNt << " -> " << p << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of non-terminals: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string nt;
        int num;

        cout << "\nEnter non-terminal: ";
        cin >> nt;

        cout << "Enter number of productions: ";
        cin >> num;

        vector<string> prods(num);
        cout << "Enter productions (without spaces, use | separately by line if needed):\n";
        for (int j = 0; j < num; j++) {
            cin >> prods[j];
        }

        cout << "\nLeft Factored Grammar:\n";
        leftFactor(nt, prods);
    }

    return 0;
}
