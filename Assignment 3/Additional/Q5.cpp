#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A = {4,1,2,3};
    stack<int> s;
    vector<int> B;
    int need = 1;
    int n = A.size();

    for(int i=0;i<n;i++){
        s.push(A[i]);
        while(!s.empty() && s.top()==need){
            B.push_back(s.top());
            s.pop();
            need++;
        }
    }

    if(need-1==n) cout<<"Yes";
    else cout<<"No";

    return 0;
}
