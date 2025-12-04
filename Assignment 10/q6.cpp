#include <bits/stdc++.h>
using namespace std;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(int x){ val=x; left=right=NULL; }
};

int main(){
    Node* root=new Node(5);
    root->left=new Node(3);
    root->right=new Node(7);
    root->left->left=new Node(3);

    unordered_set<int> s;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* u=q.front(); q.pop();
        if(s.count(u->val)){
            cout<<"Duplicates Found";
            return 0;
        }
        s.insert(u->val);
        if(u->left) q.push(u->left);
        if(u->right) q.push(u->right);
    }
    cout<<"No Duplicates";
}
