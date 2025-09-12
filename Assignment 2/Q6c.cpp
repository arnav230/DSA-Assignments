#include <iostream>
using namespace std;

#define MAX 100

void printMatrix(int mat[MAX][3]) {
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void multiply(int a[MAX][3], int b[MAX][3], int c[MAX][3]) {
    if (a[0][1] != b[0][0]) {
        cout << "Multiplication not possible" << endl;
        return;
    }
    int m = a[0][0], n = b[0][1], t1 = a[0][2], t2 = b[0][2];
    int k = 1;
    c[0][0] = m;
    c[0][1] = n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int p = 1; p <= t1; p++) {
                if (a[p][0] == i) {
                    for (int q = 1; q <= t2; q++) {
                        if (b[q][1] == j && b[q][0] == a[p][1]) {
                            sum += a[p][2] * b[q][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                c[k][0] = i;
                c[k][1] = j;
                c[k][2] = sum;
                k++;
            }
        }
    }
    c[0][2] = k-1;
}

int main() {
    int a[MAX][3] = {
        {2, 3, 3},
        {0, 0, 2},
        {0, 2, 3},
        {1, 1, 4}
    };
    int b[MAX][3] = {
        {3, 2, 3},
        {0, 1, 5},
        {1, 0, 6},
        {2, 1, 7}
    };
    int c[MAX][3];
    cout<<"Matrix A:"<<endl;
    printMatrix(a);
    cout<<"Matrix B:"<<endl;
    printMatrix(b);
    multiply(a, b, c);
    cout<<"Product Matrix:"<<endl;
    printMatrix(c);
    return 0;
}
