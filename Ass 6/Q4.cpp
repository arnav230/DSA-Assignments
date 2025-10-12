#include<bits/stdc++.h>
using namespace std;

struct DNode{
    char data;
    DNode* next;
    DNode* prev;
    DNode(char x){ data=x; next=prev=NULL;}
};

bool isPalindrome(DNode* head){
    if(!head) return true;
    DNode* tail = head;
    while(tail->next) tail = tail->next;
    while(head != tail && head->prev != tail){
        if(head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main(){
    DNode* dh = new DNode('r');
    dh->next = new DNode('a'); dh->next->prev = dh;
    dh->next->next = new DNode('d'); dh->next->next->prev = dh->next;
    dh->next->next->next = new DNode('a'); dh->next->next->next->prev = dh->next->next;
    dh->next->next->next->next = new DNode('r'); dh->next->next->next->next->prev = dh->next->next->next;

    cout<<(isPalindrome(dh)?"Yes":"No")<<endl;

    return 0;
}
