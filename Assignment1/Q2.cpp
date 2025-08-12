#include <iostream>
using namespace std;

int removeDuplicates(int arr[], int n) {
    if (n == 0) return 0;

    int k = 0; // index for placing unique elements

    for (int i = 0; i < n; i++) {
        bool isDuplicate = false;
        // Check if arr[i] appeared before
        for (int j = 0; j < k; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[k] = arr[i];
            k++;
        }
    }
    return k; // new size of array
}

int main() {
    int arr[10] = {1, 2, 2, 3, 4, 4, 5};
    int n = 7;

    int newSize = removeDuplicates(arr, n);

    cout << "Array after removing duplicates: ";
    for (int i = 0; i < newSize; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
