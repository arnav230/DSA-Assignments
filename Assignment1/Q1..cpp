#include <iostream>
using namespace std;

// create array
void create(int arr[], int &n) {
    cout << "How many elements? ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created!\n";
}

// display array
void display(int arr[], int n) {
    if (n == 0) {
        cout << "Array is empty\n";
        return;
    }
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// insert element
void insertEl(int arr[], int &n) {
    if (n >= MAX) {
        cout << "Array full, can't insert\n";
        return;
    }
    int pos, val;
    cout << "Position to insert (1-" << n+1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n+1) {
        cout << "Invalid position\n";
        return;
    }
    cout << "Value: ";
    cin >> val;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = val;
    n++;
    cout << "Inserted!\n";
}

// delete element
void deleteEl(int arr[], int &n) {
    if (n == 0) {
        cout << "Nothing to delete\n";
        return;
    }
    int pos;
    cout << "Position to delete (1-" << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos-1; i < n-1; i++) {
        arr[i] = arr[i+1];
    }
    n--;
    cout << "Deleted!\n";
}

// linear search
void search(int arr[], int n) {
    if (n == 0) {
        cout << "Array empty\n";
        return;
    }
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at position " << i+1 << "\n";
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int arr[MAX], n = 0, choice;

    do {
        cout << "\n---- MENU ----"<<endl;
        cout << "1. CREATE"<<endl;
        cout << "2. DISPLAY"<<endl;
        cout << "3. INSERT"<<endl;
        cout << "4. DELETE"<<endl;
        cout << "5. LINEAR SEARCH"<<endl;
        cout << "6. EXIT"<<endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(arr, n); break;
            case 2: display(arr, n); break;
            case 3: insertEl(arr, n); break;
            case 4: deleteEl(arr, n); break;
            case 5: search(arr, n); break;
            case 6: cout << "Bye!\n"; break;
            default: cout << "Invalid choice\n";
        }

    } while (choice != 6);

    return 0;
}

