#include<bits/stdc++.h>
using namespace std;

int main(){
    queue<int> stu;
    stu.push(1);
    stu.push(1);
    stu.push(0);
    stu.push(0);

    stack<int> sand;
    sand.push(1);
    sand.push(0);
    sand.push(1);
    sand.push(0);

    int cnt = 0;

    while(!stu.empty() && cnt < stu.size()){
        if(stu.front() == sand.top()){
            stu.pop();
            sand.pop();
            cnt = 0;
        }else{
            int x = stu.front();
            stu.pop();
            stu.push(x);
            cnt++;
        }
    }

    cout<<stu.size();
    return 0;
}
