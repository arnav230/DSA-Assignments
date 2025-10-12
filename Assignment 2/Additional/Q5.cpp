#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[] = {1,0,2,3,2,4,5,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int cnt = 0;

    for(int i=0;i<n;i++){
        if(arr[i]==2) cnt++;
    }

    int i = n-1;
    int j = n + cnt -1;

    while(i>=0){
        if(j<n) arr[j] = arr[i];
        if(arr[i]==2){
            j--;
            if(j<n) arr[j] = 2;
        }
        i--; j--;
    }

    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
