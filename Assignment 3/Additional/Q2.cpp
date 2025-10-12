#include<bits/stdc++.h>
using namespace std;

class mystack{
    stack<long long> s;
    long long minval;
public:
    void push(long long x){
        if(s.empty()){
            s.push(x);
            minval = x;
        }else{
            if(x < minval){
                s.push(2*x - minval);
                minval = x;
            }else{
                s.push(x);
            }
        }
    }

    void pop(){
        if(s.empty()) return;
        long long t = s.top();
        s.pop();
        if(t < minval){
            minval = 2*minval - t;
        }
    }

    long long top(){
        if(s.empty()) return -1;
        long long t = s.top();
        if(t < minval) return minval;
        return t;
    }

    long long getMin(){
        if(s.empty()) return -1;
        return minval;
    }
};

int main(){
    mystack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
    st.pop();
    cout<<st.getMin()<<endl;
}
