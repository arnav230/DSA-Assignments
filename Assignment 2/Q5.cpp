#include <iostream>
using namespace std;

// diagonal matrix
void setDiagonal(int A[],int n,int i,int j,int val){
    if(i==j) A[i-1]=val;
}
int getDiagonal(int A[],int n,int i,int j){
    if(i==j) return A[i-1];
    else return 0;
}

// lower triangular
void setLower(int A[],int n,int i,int j,int val){
    if(i>=j) A[i*(i-1)/2 + (j-1)] = val;
}
int getLower(int A[],int n,int i,int j){
    if(i>=j) return A[i*(i-1)/2 + (j-1)];
    else return 0;
}

// upper triangular
void setUpper(int A[],int n,int i,int j,int val){
    if(i<=j) A[j*(j-1)/2 + (i-1)] = val;
}
int getUpper(int A[],int n,int i,int j){
    if(i<=j) return A[j*(j-1)/2 + (i-1)];
    else return 0;
}

// symmetric
void setSym(int A[],int n,int i,int j,int val){
    if(i>=j) A[i*(i-1)/2 + (j-1)] = val;
    else A[j*(j-1)/2 + (i-1)] = val;
}
int getSym(int A[],int n,int i,int j){
    if(i>=j) return A[i*(i-1)/2 + (j-1)];
    else return A[j*(j-1)/2 + (i-1)];
}

// tri-diagonal
void setTri(int A[],int n,int i,int j,int val){
    if(i-j==0) A[n-1 + i-1] = val;        // main diag
    else if(i-j==1) A[i-2] = val;         // lower
    else if(i-j==-1) A[2*n-1 + i-1] = val;// upper
}
int getTri(int A[],int n,int i,int j){
    if(i-j==0) return A[n-1 + i-1];
    else if(i-j==1) return A[i-2];
    else if(i-j==-1) return A[2*n-1 + i-1];
    else return 0;
}

int main(){
    int n=4;
    int D[10]={0}; // diagonal
    setDiagonal(D,n,1,1,5);
    setDiagonal(D,n,2,2,8);
    setDiagonal(D,n,3,3,9);
    setDiagonal(D,n,4,4,12);

    cout<<"Diagonal Matrix:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<getDiagonal(D,n,i,j)<<" ";
        }
        cout<<endl;
    }
    //can test others in same way
}
