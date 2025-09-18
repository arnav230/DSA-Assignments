#include <iostream>
using namespace std;

#define MAX 100

void printMatrix(int mat[MAX][3]) {
    for (int i = 0; i <= mat[0][2]; i++) {
        cout << mat[i][0] << " " << mat[i][1] << " " << mat[i][2] << endl;
    }
}

void transpose(int mat[MAX][3], int trans[MAX][3]) {
    int m = mat[0][0], n = mat[0][1], t = mat[0][2];
    trans[0][0] = n;
    trans[0][1] = m;
    trans[0][2] = t;
    int k = 1;
    for (int col = 0; col < n; col++) {
        for (int i = 1; i <= t; i++) {
            if (mat[i][1] == col) {
                trans[k][0] = mat[i][1];
                trans[k][1] = mat[i][0];
                trans[k][2] = mat[i][2];
                k++;
            }
        }
    }
}

int main() {
    int a[MAX][3] = {
        {4, 4, 4},   
        {0, 1, 5},
        {1, 2, 8},
        {2, 3, 3},
        {3, 0, 6}
    };
    int t[MAX][3];
    cout<<"Original matrix:"<<endl;
    printMatrix(a);
    transpose(a, t);
    cout<<"Transpose matrix:"<<endl;
    printMatrix(t);
}

