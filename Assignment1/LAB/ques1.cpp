#include <iostream>
using namespace std;

#define MAX 100   // max size of array

// create array
void create(int a[], int &n) {
    cout << "How many elements? ";
    cin >> n;
    if(n > MAX) {
        cout << "Too many! max = " << MAX << endl;
        n = 0;
        return;
    }
    cout << "Enter elements: ";
    for(int i=0;i<n;i++) {
        cin >> a[i];
    }
    cout << "Array created.\n";
}

// display array
void display(int a[], int n) {
    if(n==0) {
        cout << "Array empty\n";
        return;
    }
    cout << "Array: ";
    for(int i=0;i<n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

// insert element
void insertEl(int a[], int &n) {
    if(n==MAX) {
        cout << "Array full\n";
        return;
    }
    int pos,val;
    cout << "Position (1-" << n+1 << "): ";
    cin >> pos;
    if(pos<1 || pos>n+1) {
        cout << "Invalid pos\n";
        return;
    }
    cout << "Value: ";
    cin >> val;
    for(int i=n;i>=pos;i--) {
        a[i] = a[i-1];
    }
    a[pos-1] = val;
    n++;
    cout << "Inserted.\n";
}

// delete element
void deleteEl(int a[], int &n) {
    if(n==0) {
        cout << "Nothing to delete\n";
        return;
    }
    int pos;
    cout << "Position (1-" << n << "): ";
    cin >> pos;
    if(pos<1 || pos>n) {
        cout << "Invalid pos\n";
        return;
    }
    for(int i=pos-1;i<n-1;i++) {
        a[i] = a[i+1];
    }
    n--;
    cout << "Deleted.\n";
}

// search element (linear)
void search(int a[], int n) {
    if(n==0) {
        cout << "Array empty\n";
        return;
    }
    int key;
    cout << "Element to search: ";
    cin >> key;
    for(int i=0;i<n;i++) {
        if(a[i]==key) {
            cout << "Found at pos " << i+1 << endl;
            return;
        }
    }
    cout << "Not found\n";
}

int main() {
    int arr[MAX], n=0, ch;

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Choice: ";
        cin >> ch;

        switch(ch) {
            case 1: create(arr,n); break;
            case 2: display(arr,n); break;
            case 3: insertEl(arr,n); break;
            case 4: deleteEl(arr,n); break;
            case 5: search(arr,n); break;
            case 6: cout << "Bye!\n"; break;
            default: cout << "Wrong choice\n";
        }
    } while(ch!=6);

    return 0;
}
