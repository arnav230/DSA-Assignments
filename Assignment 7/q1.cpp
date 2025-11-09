#include<bits/stdc++.h>
using namespace std;

void sel(int a[],int n){
    for(int i=0;i<n;i++){
        int m=i;
        for(int j=i+1;j<n;j++){
            if(a[j]<a[m]) m=j;
        }
        swap(a[i],a[m]);
    }
}

void ins(int a[],int n){
    for(int i=1;i<n;i++){
        int x=a[i],j=i-1;
        while(j>=0 && a[j]>x){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=x;
    }
}

void bub(int a[],int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j]>a[j+1]) swap(a[j],a[j+1]);
        }
    }
}

void mergeArr(int a[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int L[1000],R[1000];
    for(int i=0;i<n1;i++) L[i]=a[l+i];
    for(int j=0;j<n2;j++) R[j]=a[m+1+j];
    int i=0,j=0,k=l;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<n1) a[k++]=L[i++];
    while(j<n2) a[k++]=R[j++];
}

void msort(int a[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        msort(a,l,m);
        msort(a,m+1,r);
        mergeArr(a,l,m,r);
    }
}

int part(int a[],int l,int r){
    int p=a[r],i=l-1;
    for(int j=l;j<r;j++){
        if(a[j]<p){
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    return i+1;
}

void qsort(int a[],int l,int r){
    if(l<r){
        int p=part(a,l,r);
        qsort(a,l,p-1);
        qsort(a,p+1,r);
    }
}

void show(int a[],int n){
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
}

int main(){
    int ch,n,a[1000],b[1000];
    cout<<"size? ";
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    
    for(;;){
        cout<<"\n1 selection\n2 insertion\n3 bubble\n4 merge\n5 quick\n6 exit\n";
        cin>>ch;
        if(ch==6) break;
        for(int i=0;i<n;i++) b[i]=a[i];
        if(ch==1) sel(b,n);
        else if(ch==2) ins(b,n);
        else if(ch==3) bub(b,n);
        else if(ch==4) msort(b,0,n-1);
        else if(ch==5) qsort(b,0,n-1);
        else { cout<<"wrong\n"; continue; }
        show(b,n);
    }
}
