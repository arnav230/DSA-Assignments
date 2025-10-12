#include<bits/stdc++.h>
using namespace std;

int main(){
    char s[] = "abcabca";
    int n = strlen(s);
    bool ok = false;

    for(int i=1;i<n-1 && !ok;i++){
        for(int j=i+1;j<n && !ok;j++){
            char a[100], b[100], c[100];
            strncpy(a, s, i);
            a[i] = '\0';
            strncpy(b, s+i, j-i);
            b[j-i] = '\0';
            strcpy(c, s+j);

            if(strstr(a,b) && strstr(c,b)) ok = true;
            else if(strstr(b,a) && strstr(c,a)) ok = true;
            else if(strstr(a,c) && strstr(b,c)) ok = true;
        }
    }

    if(ok) cout<<"Yes";
    else cout<<"No";

    return 0;
}
