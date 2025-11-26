#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSets;
map<char, set<char>> followSets;
set<char> visitedFirst;
set<char> visitedFollow;
char startSymbol;

// Compute FIRST set of a non-terminal
void findFirst(char symbol) {
    if (visitedFirst.find(symbol) != visitedFirst.end())
        return;

    visitedFirst.insert(symbol);

    for (auto production : grammar[symbol]) {
        if (production == "#") {
            firstSets[symbol].insert('#');
            continue;
        }

        bool allEpsilon = true;

        for (size_t i = 0; i < production.size(); i++) {
            char ch = production[i];

            // Terminal
            if (!isupper(ch)) {
                if (ch != '#')
                    firstSets[symbol].insert(ch);
                allEpsilon = false;
                break;
            } else {
                // Non-terminal
                findFirst(ch);

                bool epsilonPresent = false;
                for (auto x : firstSets[ch]) {
                    if (x == '#')
                        epsilonPresent = true;
                    else
                        firstSets[symbol].insert(x);
                }

                if (!epsilonPresent) {
                    allEpsilon = false;
                    break;
                }

                // if epsilon in FIRST(ch), continue to next symbol
                if (epsilonPresent && i == production.size() - 1) {
                    allEpsilon = true;
                }
            }
        }

        if (allEpsilon) {
            firstSets[symbol].insert('#');
        }
    }
}

// Compute FOLLOW set of a non-terminal
void findFollow(char symbol) {
    if (visitedFollow.find(symbol) != visitedFollow.end())
        return;

    visitedFollow.insert(symbol);

    // Start symbol gets '$'
    if (symbol == startSymbol) {
        followSets[symbol].insert('$');
    }

    // For all productions A -> α B β
    for (auto &rule : grammar) {
        char lhs = rule.first;
        for (auto &production : rule.second) {
            for (size_t i = 0; i < production.size(); i++) {
                if (production[i] == symbol) {
                    // Case where symbol is followed by something (β not empty)
                    if (i + 1 < production.size()) {
                        bool allEpsilon = true;

                        for (size_t j = i + 1; j < production.size(); j++) {
                            char next = production[j];

                            // Terminal
                            if (!isupper(next)) {
                                if (next != '#')
                                    followSets[symbol].insert(next);
                                allEpsilon = false;
                                break;
                            } else {
                                // Non-terminal
                                findFirst(next);
                                bool epsilonPresent = false;

                                for (auto x : firstSets[next]) {
                                    if (x == '#')
                                        epsilonPresent = true;
                                    else
                                        followSets[symbol].insert(x);
                                }

                                if (!epsilonPresent) {
                                    allEpsilon = false;
                                    break;
                                }

                                if (epsilonPresent && j == production.size() - 1) {
                                    allEpsilon = true;
                                }
                            }
                        }

                        // If every symbol in β can derive epsilon, add FOLLOW(lhs)
                        if (allEpsilon) {
                            findFollow(lhs);
                            for (auto x : followSets[lhs]) {
                                followSets[symbol].insert(x);
                            }
                        }
                    } else {
                        // symbol at end: A -> α B
                        if (lhs != symbol) {
                            findFollow(lhs);
                            for (auto x : followSets[lhs]) {
                                followSets[symbol].insert(x);
                            }
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int n;
    cout << "Enter number of productions: ";
    cin >> n;

    cout << "Enter productions (e.g., E=TA or A=a or B=# for epsilon):\n";

    bool firstRule = true;
    for (int i = 0; i < n; i++) {
        string input;
        cin >> input;

        char lhs = input[0];
        string rhs = input.substr(2);  // assumes format X=...

        if (firstRule) {
            startSymbol = lhs;
            firstRule = false;
        }

        grammar[lhs].push_back(rhs);
    }

    // Compute FIRST sets
    for (auto rule : grammar) {
        findFirst(rule.first);
    }

    // Compute FOLLOW sets
    for (auto rule : grammar) {
        findFollow(rule.first);
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

    cout << "\nFOLLOW Sets:\n";
    for (auto rule : followSets) {
        cout << "FOLLOW(" << rule.first << ") = { ";
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
