#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* insert(Node* head,int x){
    Node* t=new Node();
    t->data=x;
    t->next=head;
    return t;
}

int removeKey(Node* &head,int key){
    int cnt=0;
    while(head && head->data==key){
        Node* temp=head;
        head=head->next;
        delete temp;
        cnt++;
    }
    Node* cur=head;
    while(cur && cur->next){
        if(cur->next->data==key){
            Node* temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
            cnt++;
        }else cur=cur->next;
    }
    return cnt;
}

void print(Node* head){
    while(head){
        cout<<head->data;
        if(head->next) cout<<"->";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    head=insert(head,1);
    head=insert(head,3);
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,1);
    head=insert(head,2);
    head=insert(head,1);

    int key=1;
    int c=removeKey(head,key);
    cout<<"Count: "<<c<<", Updated Linked List: ";
    print(head);
}
