#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,6,7,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    int low=0,high=n-1,ans=-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==mid+1){
            low=mid+1;
        } else {
            ans=mid+1;
            high=mid-1;
        }
    }
    cout << "Missing number: " << ans;
    return 0;
}
