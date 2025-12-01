#include <iostream>
using namespace std;

// Function for Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // return index if element is found
        }
    }
    return -1; // return -1 if element not found
}

int main() {
    int arr[] = {100 , 1000 , 10000 , 10 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;

    cout << "Enter element to search: ";
    cin >> x;

    int result = linearSearch(arr, n, x);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found in the array" << endl;

    return 0;
}
