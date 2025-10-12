#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

void insend(int x) {
    node* n = new node;
    n->data = x;
    n->next = NULL;
    if(head == NULL) {
        head = n;
        return;
    }
    node* t = head;
    while(t->next != NULL) t = t->next;
    t->next = n;
}

void print() {
    node* t = head;
    while(t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

void findmiddle() {
    if(head == NULL) {
        cout << "list empty\n";
        return;
    }
    node* slow = head;
    node* fast = head;
    while(fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout << "middle is " << slow->data << endl;
}

int main() {
    int n, x;
    cout << "enter number of nodes ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        cout << "enter val ";
        cin >> x;
        insend(x);
    }
    print();
    findmiddle();
}
