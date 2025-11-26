                                                                                                                                       
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Function to check if the top of the stack can be reduced
bool canReduce(stack<string> &stk) {
    if (stk.size() < 2) return false;

    string top1 = stk.top(); stk.pop();
    string top2 = stk.top(); stk.pop();

    if (top2 == "a" && top1 == "a") {
        stk.push("A");  // Reduce 'a a' to 'A'
        return true;
    }
    if (top2 == "b" && top1 == "b") {
        stk.push("B");  // Reduce 'b b' to 'B'
        return true;
    }
    if (top2 == "A" && top1 == "B") {
        stk.push("S");  // Reduce 'A B' to 'S'
        return true;
    }
    if (top2 == "a" && top1 == "b") {
        stk.push("S");  // NEW: Reduce 'a b' directly to 'S'
        return true;
    }

    // No reduction possible, push back popped elements
    stk.push(top2);
    stk.push(top1);
    return false;
}


// Shift-Reduce Parsing Function
bool shiftReduceParse(const string &input) {
    stack<string> stk;
    vector<string> tokens;

    // Convert input string into tokens (each character as string)
    for (char c : input) {
        tokens.push_back(string(1, c));
    }

    int i = 0; // token index
    while (i < tokens.size() || !stk.empty()) {
        // Try to reduce first
        if (canReduce(stk)) {
            cout << "Reduced: " << stk.top() << endl;
            continue;
        }

        // Shift if tokens left
        if (i < tokens.size()) {
            cout << "Shift: " << tokens[i] << endl;
            stk.push(tokens[i]);
            i++;
        } else {
            // No more tokens and no reduction possible
            break;
        }
    }

    // Final reduction if possible
    while (canReduce(stk)) {
        cout << "Reduced: " << stk.top() << endl;
    }

    // Accept if stack contains only the start symbol 'S'
    return (stk.size() == 1 && stk.top() == "S");
}

int main() {
    string input;
    cout << "Enter a string (containing only 'a' and 'b'): ";
    cin >> input;

    for (char c : input) {
        if (c != 'a' && c != 'b') {
            cout << "Invalid input. Only 'a' and 'b' allowed.\n";
            return 1;
        }
    }

    if (shiftReduceParse(input)) {
        cout << "Input string is accepted.\n";
    } else {
        cout << "Input string is not accepted.\n";
    }

    return 0;
}