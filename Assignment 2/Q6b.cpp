#include <iostream>
using namespace std;

#define MAX 100

void printMatrix(int mat[MAX][3]) {
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void add(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][0] != b[0][0] || a[0][1] != b[0][1]) {
        cout << "Addition not possible" << endl;
        return;
    }
    int m = a[0][0], n = a[0][1];
    int t1 = a[0][2], t2 = b[0][2];
    int i = 1, j = 1, k = 1;
    c[0][0] = m;
    c[0][1] = n;
    while (i <= t1 && j <= t2) {
        if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2];
            i++;
        } else if (b[j][0] < a[i][0] || (b[j][0] == a[i][0] && b[j][1] < a[i][1])) {
            c[k][0] = b[j][0];
            c[k][1] = b[j][1];
            c[k][2] = b[j][2];
            j++;
        } else {
            c[k][0] = a[i][0];
            c[k][1] = a[i][1];
            c[k][2] = a[i][2] + b[j][2];
            i++;
            j++;
        }
        k++;
    }
    while (i <= t1) {
        c[k][0] = a[i][0];
        c[k][1] = a[i][1];
        c[k][2] = a[i][2];
        i++;
        k++;
    }
    while (j <= t2) {
        c[k][0] = b[j][0];
        c[k][1] = b[j][1];
        c[k][2] = b[j][2];
        j++;
        k++;
    }
    c[0][2] = k-1;
}

int main() {
    int a[MAX][3] = {
        {3, 3, 3}, 
        {0, 0, 5}, 
        {1, 1, 8}, 
        {2, 2, 6}
    };
    int b[MAX][3] = {
        {3, 3, 3}, 
        {0, 1, 4}, 
        {1, 1, 7}, 
        {2, 0, 2}
    };
    int c[MAX][3];
    cout<<"Matrix A:"<<endl;
    printMatrix(a);
    cout<<"Matrix B:"<<endl;
    printMatrix(b);
    add(a, b, c);
    cout<<"Sum Matrix:"<<endl;
    printMatrix(c);
}
