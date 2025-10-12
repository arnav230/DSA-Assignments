#include<bits/stdc++.h>
using namespace std;

int main(){
    char str1[] = "listen";
    char str2[] = "silent";

    int cnt1[26] = {0};
    int cnt2[26] = {0};

    for(int i=0; str1[i]; i++) cnt1[str1[i]-'a']++;
    for(int i=0; str2[i]; i++) cnt2[str2[i]-'a']++;

    bool ok = true;
    for(int i=0;i<26;i++){
        if(cnt1[i] != cnt2[i]){
            ok = false;
            break;
        }
    }

    if(ok) cout<<"Yes";
    else cout<<"No";

    return 0;
}
