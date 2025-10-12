#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {4, 5, 2, 25};
    vector<int> ans(arr.size(), -1);
    stack<int> s;

    for(int i=0;i<arr.size();i++){
        while(!s.empty() && arr[s.top()] < arr[i]){
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }

    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    return 0;
}
