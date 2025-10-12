#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> temp = {73,74,75,71,69,72,76,73};
    vector<int> ans(temp.size(),0);
    stack<int> s;

    for(int i=0;i<temp.size();i++){
        while(!s.empty() && temp[i] > temp[s.top()]){
            int j = s.top();
            s.pop();
            ans[j] = i - j;
        }
        s.push(i);
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
