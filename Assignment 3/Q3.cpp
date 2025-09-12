#include <bits/stdc++.h>
using namespace std;

int main() {
    char exp[100];
    cout << "Enter expression: ";
    cin >> exp;

    char stack[100];
    int top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            stack[++top] = '(';
        } else if (exp[i] == ')') {
            if (top == -1) {
                cout << "Not Balanced" << endl;
            }
            top--;
        }
    }

    if (top == -1)
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
}
