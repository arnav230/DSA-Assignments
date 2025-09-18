#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter rows and columns of matrix";
    cin >> rows >> cols;

    int mat[20][20], trans[20][20];

    cout << "Enter elements of matrix";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            trans[j][i] = mat[i][j];
        }
    }

    cout << "Transpose of matrix is";
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            cout << trans[i][j] << " ";
        }
        cout << endl;
    }
}


