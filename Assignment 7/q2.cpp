#include<bits/stdc++.h>
using namespace std;

void sel2(int a[],int n){
    int l=0,r=n-1;
    while(l<r){
        int mn=l,mx=l;
        for(int i=l;i<=r;i++){
            if(a[i]<a[mn]) mn=i;
            if(a[i]>a[mx]) mx=i;
        }
        swap(a[l],a[mn]);
        if(mx==l) mx=mn;
        swap(a[r],a[mx]);
        l++;
        r--;
    }
}

int main(){
    int n,a[1000];
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    sel2(a,n);
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}
