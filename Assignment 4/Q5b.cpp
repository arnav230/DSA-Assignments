#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    int choice, val;

    do {
        cout << "\n1. Push\n2. Pop\n3. Top\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: {
                cout << "Enter value: ";
                cin >> val;
                q.push(val);
                int sz = q.size();
                for(int i=1; i<sz; i++) {
                    q.push(q.front());
                    q.pop();
                }
                break;
            }

            case 2:
                if(q.empty()) cout << "Stack is Empty!\n";
                else {
                    cout << "Popped: " << q.front() << endl;
                    q.pop();
                }
                break;

            case 3:
                if(q.empty()) cout << "Stack is Empty!\n";
                else cout << "Top: " << q.front() << endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while(choice != 4);

    return 0;
}
