#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements of array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int distinctCount = 0;

    // Naive approach: check if element is seen before
    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        // check with previous elements
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) {
            distinctCount++;
        }
    }

    cout << "Total number of distinct elements = " << distinctCount << endl;

    return 0;
}
