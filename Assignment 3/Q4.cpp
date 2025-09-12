#include <bits/stdc++.h>
using namespace std;

int priority(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100], stack[100];
    int top = -1, k = 0;
    cout << "Enter infix expression: ";
    cin >> infix;

    for(int i=0; infix[i] != '\0'; i++) {
        char c = infix[i];
        if(isalnum(c)) {
            postfix[k++] = c;
        }
        else if(c == '(') {
            stack[++top] = c;
        }
        else if(c == ')') {
            while(top != -1 && stack[top] != '(') {
                postfix[k++] = stack[top--];
            }
            top--; 
        }
        else {
            while(top != -1 && priority(stack[top]) >= priority(c)) {
                postfix[k++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while(top != -1) {
        postfix[k++] = stack[top--];
    }
    postfix[k] = '\0';

    cout << "Postfix expression" << postfix << endl;
}
