#include <iostream>
using namespace std;

int main() {
    char str[100];  
    cout << "Enter a string: ";
    cin >> str;     

    if (str[1] == '\0' && str[0] >= '0' && str[0] <= '9') {
        cout << "constant" << endl;
    } else {
        cout << "not constant" << endl;
    }

    return 0;
}

