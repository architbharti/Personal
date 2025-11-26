#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSets;
set<char> visited;

void findFirst(char symbol) {
    // If already processed, skip
    if (visited.find(symbol) != visited.end())
        return;

    visited.insert(symbol);

    for (auto production : grammar[symbol]) {
        // If production is epsilon ("#")
        if (production == "#") {
            firstSets[symbol].insert('#');
            continue;
        }

        bool allEpsilon = true;

        for (size_t i = 0; i < production.size(); i++) {
            char ch = production[i];

            // If terminal (non-uppercase letter), add directly to FIRST
            if (!isupper(ch)) {
                firstSets[symbol].insert(ch);
                allEpsilon = false;
                break;
            } else {
                // Non-terminal: compute its FIRST
                findFirst(ch);

                bool epsilonPresent = false;
                for (auto x : firstSets[ch]) {
                    if (x == '#')
                        epsilonPresent = true;
                    else
                        firstSets[symbol].insert(x);
                }

                // If this non-terminal does NOT derive epsilon, stop
                if (!epsilonPresent) {
                    allEpsilon = false;
                    break;
                }

                // else, epsilon present: continue to next symbol in production
                if (epsilonPresent && i == production.size() - 1) {
                    // All symbols can derive epsilon
                    allEpsilon = true;
                }
            }
        }

        if (allEpsilon) {
            firstSets[symbol].insert('#');
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions (e.g., E=TA or A=a or B=# for epsilon):\n";

    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        char lhs = input[0];
        string rhs = input.substr(2); // assuming format X=Y...

        grammar[lhs].push_back(rhs);
    }

    // Compute FIRST for all non-terminals
    for (auto rule : grammar) {
        findFirst(rule.first);
    }

    cout << "\nFIRST Sets:\n";
    for (auto rule : firstSets) {
        cout << "FIRST(" << rule.first << ") = { ";
        for (auto it = rule.second.begin(); it != rule.second.end(); ++it) {
            cout << *it;
            auto next = it;
            ++next;
            if (next != rule.second.end()) cout << ", ";
        }
        cout << " }\n";
    }

    return 0;
}
