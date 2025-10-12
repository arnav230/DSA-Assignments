#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    stack<int> s;
    int need = 1;
    int n = q.size();

    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == need){
            need++;
        }else{
            while(!s.empty() && s.top()==need){
                s.pop();
                need++;
            }
            s.push(x);
        }
    }

    while(!s.empty() && s.top()==need){
        s.pop();
        need++;
    }

    if(need-1==n) cout<<"Yes";
    else cout<<"No";

    return 0;
}
