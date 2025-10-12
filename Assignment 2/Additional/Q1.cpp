#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr = {1, 5, 3, 4, 2};
    int k = 2;
    int cnt = 0;

    unordered_set<int> s;
    for(int x : arr){
        if(s.find(x + k) != s.end()) cnt++;
        if(s.find(x - k) != s.end()) cnt++;
        s.insert(x);
    }

    cout<<cnt;
    return 0;
}
