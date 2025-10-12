#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {4, 5, 2, 10, 8};
    stack<int> s;
    vector<int> ans;

    for(int i=0;i<a.size();i++){
        while(!s.empty() && s.top()>=a[i]){
            s.pop();
        }
        if(s.empty()) ans.push_back(-1);
        else ans.push_back(s.top());
        s.push(a[i]);
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
