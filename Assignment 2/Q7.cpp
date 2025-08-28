#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array";
    cin >> n;

    int arr[n];
    cout << "Enter elements of arra";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0; 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                count++;
                cout << "Inversion: (" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }

    cout << "Total number of inversions:" << count;
}
