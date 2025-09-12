#include <bits/stdc++.h>
using namespace std;

int main() {
    char str[] = "Arnav Gupta";
    char stack[100];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        stack[++top] = str[i];
    }

    cout << "Original string: " << str << endl;
    cout << "Reversed string: ";
    while (top != -1) {
        cout << stack[top--];
    }
    cout << endl;

    return 0;
}
