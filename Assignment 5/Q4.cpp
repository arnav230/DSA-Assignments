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

void reverse() {
    node* prev = NULL;
    node* curr = head;
    node* next;
    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
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
    cout << "original list: ";
    print();
    reverse();
    cout << "reversed list: ";
    print();
}
