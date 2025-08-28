#include <iostream>
using namespace std;

/* 
   Diagonal Matrix 
   Only diagonal elements are non-zero
   Space required = n
*/
class Diagonal {
    int n;
    int *A;
public:
    Diagonal(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        return 0;
    }
    void display() {
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (i == j) cout << A[i] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};

/*
   Tri-diagonal Matrix
   Non-zero only on main, upper and lower diagonal
   Space required = 3n - 2
*/
class TriDiagonal {
    int n;
    int *A;
public:
    TriDiagonal(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i-j == 1) A[i-2] = x;                // lower diagonal
        else if (i-j == 0) A[n-1 + i-1] = x;     // main diagonal
        else if (i-j == -1) A[2*n-1 + i-1] = x;  // upper diagonal
    }
    int get(int i, int j) {
        if (i-j == 1) return A[i-2];
        else if (i-j == 0) return A[n-1 + i-1];
        else if (i-j == -1) return A[2*n-1 + i-1];
        return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/*
   Lower Triangular Matrix
   Non-zero only below or on diagonal
   Space required = n(n+1)/2
*/
class LowerTriangular {
    int n;
    int *A;
public:
    LowerTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) {
            int k = i*(i-1)/2 + (j-1);
            A[k] = x;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int k = i*(i-1)/2 + (j-1);
            return A[k];
        }
        return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/*
   Upper Triangular Matrix
   Non-zero only above or on diagonal
   Space required = n(n+1)/2
*/
class UpperTriangular {
    int n;
    int *A;
public:
    UpperTriangular(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) {
            int k = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
            A[k] = x;
        }
    }
    int get(int i, int j) {
        if (i <= j) {
            int k = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
            return A[k];
        }
        return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/*
   Symmetric Matrix
   A[i][j] = A[j][i]
   Space required = n(n+1)/2
*/
class Symmetric {
    int n;
    int *A;
public:
    Symmetric(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) {
            int k = i*(i-1)/2 + (j-1);
            A[k] = x;
        } else {
            int k = j*(j-1)/2 + (i-1); // symmetry
            A[k] = x;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int k = i*(i-1)/2 + (j-1);
            return A[k];
        } else {
            int k = j*(j-1)/2 + (i-1);
            return A[k];
        }
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

/* ---------------- MAIN FUNCTION ---------------- */
int main() {
    int n = 4;

    cout << "Diagonal Matrix:" << endl;
    Diagonal d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,10); d.set(4,4,12);
    d.display();

    cout << "\nTri-diagonal Matrix:" << endl;
    TriDiagonal t(n);
    t.set(1,1,1); t.set(1,2,2); 
    t.set(2,1,3); t.set(2,2,4); t.set(2,3,5);
    t.set(3,2,6); t.set(3,3,7); t.set(3,4,8);
    t.set(4,3,9); t.set(4,4,10);
    t.display();

    cout << "\nLower Triangular Matrix:" << endl;
    LowerTriangular l(n);
    l.set(1,1,1); l.set(2,1,2); l.set(2,2,3);
    l.set(3,1,4); l.set(3,2,5); l.set(3,3,6);
    l.set(4,1,7); l.set(4,2,8); l.set(4,3,9); l.set(4,4,10);
    l.display();

    cout << "\nUpper Triangular Matrix:" << endl;
    UpperTriangular u(n);
    u.set(1,1,1); u.set(1,2,2); u.set(1,3,3); u.set(1,4,4);
    u.set(2,2,5); u.set(2,3,6); u.set(2,4,7);
    u.set(3,3,8); u.set(3,4,9);
    u.set(4,4,10);
    u.display();

    cout << "\nSymmetric Matrix:" << endl;
    Symmetric s(n);
    s.set(1,1,1); s.set(2,1,2); s.set(2,2,3);
    s.set(3,1,4); s.set(3,2,5); s.set(3,3,6);
    s.set(4,1,7); s.set(4,2,8); s.set(4,3,9); s.set(4,4,10);
    s.display();

    return 0;
}
