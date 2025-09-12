#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

int stack[100];
int top = -1;

void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char exp[]) {
    int i = 0;
    while (exp[i] != '\0') {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }
        else {
            int val2 = pop();
            int val1 = pop();
            switch (exp[i]) {
                case '+': push(val1 + val2); break;
                case '-': push(val1 - val2); break;
                case '*': push(val1 * val2); break;
                case '/': push(val1 / val2); break;
            }
        }
        i++;
    }
    return pop();
}

int main() {
    char exp[100];
    cout << "Enter Postfix expression:";
    cin >>exp;

    cout << "Result = " << evaluatePostfix(exp) << endl;
}
