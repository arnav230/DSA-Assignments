#include <iostream>
using namespace std;

int main() {
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of first matrix";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matri";
    cin >> r2 >> c2;

    if (c1 != r2) {
        cout << "Matrix multiplication not possible";
        return 0;
    }

    int mat1[20][20], mat2[20][20], res[20][20] = {0};

    cout << "Enter elements of first matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c1; j++) {
            cin >> mat1[i][j];
        }
    }
    
    cout << "Enter elements of second matrix:\n";
    for (int i = 0; i < r2; i++) {
        for (int j = 0; j < c2; j++) {
            cin >> mat2[i][j];
        }
    }

    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            int sum = 0;
            for (int k = 0; k < c1; k++) {
                sum += mat1[i][k] * mat2[k][j];
            }
            res[i][j] = sum;
        }
    }

    cout << "Resultant matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }

}

