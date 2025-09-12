#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2;
    int choice, val;

    do {
        cout << "1. Push\n2. Pop\n3. Top\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                q2.push(val);
                while(!q1.empty()) {
                    q2.push(q1.front());
                    q1.pop();
                }
                swap(q1, q2);
                break;

            case 2:
                if(q1.empty())
                    cout << "Stack is Empty!\n";
                else {
                    cout << "Popped: " << q1.front() << endl;
                    q1.pop();
                }
                break;

            case 3:
                if(q1.empty())
                    cout << "Stack is Empty!\n";
                else
                    cout << "Top: " << q1.front() << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);
}
