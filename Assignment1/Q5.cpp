#include <iostream>
using namespace std;

int main() {
    int rows;
    int cols;
    cout << "Enter rows and columns of matrix";
    cin >> rows >> cols;

    int mat[20][20];
    cout << "Enter elements of matrix";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += mat[i][j];
        }
        cout << "Sum of row" << i + 1 << " = " << rowSum << endl;
    }

    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += mat[i][j];
        }
        cout << "Sum of column" << j + 1 << " = " << colSum << endl;
    }
}

