#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next, *prev;
    Node(int x){
        data = x;
        next = prev = NULL;
    }
};

Node* head = NULL;

void insertBegin(int x){
    Node* temp = new Node(x);
    if(!head){
        temp->next = temp->prev = temp;
        head = temp;
        return;
    }
    Node* last = head->prev;
    temp->next = head;
    temp->prev = last;
    last->next = head->prev = temp;
    head = temp;
}

void insertEnd(int x){
    Node* temp = new Node(x);
    if(!head){
        temp->next = temp->prev = temp;
        head = temp;
        return;
    }
    Node* last = head->prev;
    last->next = temp;
    temp->prev = last;
    temp->next = head;
    head->prev = temp;
}

void insertAfter(int val, int x){
    if(!head) return;
    Node* curr = head;
    do{
        if(curr->data==val){
            Node* temp = new Node(x);
            Node* nxt = curr->next;
            curr->next = temp;
            temp->prev = curr;
            temp->next = nxt;
            nxt->prev = temp;
            return;
        }
        curr = curr->next;
    }while(curr!=head);
}

void deleteNode(int val){
    if(!head) return;
    Node* curr = head;
    do{
        if(curr->data==val){
            if(curr->next==curr){ 
                delete curr;
                head=NULL;
                return;
            }
            Node* prevn = curr->prev;
            Node* nextn = curr->next;
            prevn->next = nextn;
            nextn->prev = prevn;
            if(curr==head) head = nextn;
            delete curr;
            return;
        }
        curr = curr->next;
    }while(curr!=head);
}

bool searchNode(int val){
    if(!head) return false;
    Node* curr = head;
    do{
        if(curr->data==val) return true;
        curr = curr->next;
    }while(curr!=head);
    return false;
}

void display(){
    if(!head) {cout<<"List Empty\n"; return;}
    Node* curr = head;
    do{
        cout<<curr->data<<" ";
        curr = curr->next;
    }while(curr!=head);
    cout<<"\n";
}

int main(){
    insertBegin(10);
    insertEnd(20);
    insertEnd(30);
    insertAfter(20,25);
    display();

    cout<<(searchNode(25)?"Found\n":"Not Found\n"); 
    deleteNode(20);
    display(); 
    deleteNode(10);
    display(); 

    return 0;
}
