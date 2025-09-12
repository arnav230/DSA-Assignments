#include <iostream>
using namespace std;

int main() {
    int q[100], n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> q[i];
    }

    int mid = n / 2;
    int res[100];
    int k = 0;

    for (int i = 0; i < mid; i++) {
        res[k++] = q[i];       
        res[k++] = q[i + mid];  
    }

    cout << "Interleaved Queue: ";
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << endl;
}
