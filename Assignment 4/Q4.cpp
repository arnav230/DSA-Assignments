#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter string: ";
    cin >> str;

    int count[256] = {0};
    char q[100];
    int front = 0, rear = -1;

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        count[ch]++;          
        q[++rear] = ch;       

        while (front <= rear && count[q[front]] > 1) {
            front++;       
        }

        if (front <= rear)
            cout << q[front] << " ";
        else
            cout << -1 << " ";
    }
    cout << endl;

    return 0;
}
