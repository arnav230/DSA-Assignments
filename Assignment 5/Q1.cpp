#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = NULL;

void insbeg() {
    node* n = new node;
    int x;
    cout << "enter val ";
    cin >> x;
    n->data = x;
    n->next = head;
    head = n;
}

void insend() {
    node* n = new node;
    int x;
    cout << "enter val ";
    cin >> x;
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

void insmid() {
    int val, newval, choice;
    cout << "enter val to insert before(1)/after(2) ";
    cin >> choice;
    cout << "enter node val ";
    cin >> val;
    cout << "enter new val ";
    cin >> newval;
    node* n = new node;
    n->data = newval;
    if(head == NULL) return;
    node* t = head;
    if(choice == 1) {
        if(head->data == val) {
            n->next = head;
            head = n;
            return;
        }
        while(t->next != NULL && t->next->data != val) t = t->next;
        if(t->next != NULL) {
            n->next = t->next;
            t->next = n;
        }
    } else {
        while(t != NULL && t->data != val) t = t->next;
        if(t != NULL) {
            n->next = t->next;
            t->next = n;
        }
    }
}

void delbeg() {
    if(head == NULL) return;
    node* t = head;
    head = head->next;
    delete t;
}

void delend() {
    if(head == NULL) return;
    if(head->next == NULL) {
        delete head;
        head = NULL;
        return;
    }
    node* t = head;
    while(t->next->next != NULL) t = t->next;
    delete t->next;
    t->next = NULL;
}

void delnode() {
    int val;
    cout << "enter val to delete ";
    cin >> val;
    if(head == NULL) return;
    if(head->data == val) {
        node* t = head;
        head = head->next;
        delete t;
        return;
    }
    node* t = head;
    while(t->next != NULL && t->next->data != val) t = t->next;
    if(t->next != NULL) {
        node* temp = t->next;
        t->next = t->next->next;
        delete temp;
    }
}

void search() {
    int val, pos = 1;
    cout << "enter val to search ";
    cin >> val;
    node* t = head;
    while(t != NULL) {
        if(t->data == val) {
            cout << "found at pos " << pos << endl;
            return;
        }
        t = t->next;
        pos++;
    }
    cout << "not found\n";
}

void display() {
    node* t = head;
    while(t != NULL) {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

int main() {
    int ch;
    while(1) {
        cout << "1.ins beg\n2.ins end\n3.ins mid\n4.del beg\n5.del end\n6.del node\n7.search\n8.display\n9.exit\n";
        cin >> ch;
        switch(ch) {
            case 1: insbeg(); break;
            case 2: insend(); break;
            case 3: insmid(); break;
            case 4: delbeg(); break;
            case 5: delend(); break;
            case 6: delnode(); break;
            case 7: search(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: cout << "wrong\n";
        }
    }
}
