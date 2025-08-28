#include<bits/stdc++.h>
#include<cstdlib>
using namespace std;

int main() {
	int size;
	cout<<"enter stack size: "<<endl;
	cin>>size;
	int value, choice;
	int stack[size], top=-1;
	
	while(true) {
		cout<<"1. push"<<endl;
		cout<<"2. pop"<<endl;
		cout<<"3. isEmpty"<<endl;
		cout<<"4. isFull"<<endl;
		cout<<"5. display"<<endl;
		cout<<"6. peek"<<endl;
		cout<<"7. EXIT"<<endl;
		cout<<"enter choice: ";
		cin>>choice;
	
	switch(choice) {
		case 1:  //push
			if(top==size-1) {
				cout<<"stack overflow"<<endl;
			}
			else {
				cout<<"enter value to push";
				cin>>value;
				stack[++top] = value;
				cout<<"successfully pushed "<<value<<endl;
			}
		break;
		
		case 2:  //pop
		    if(top==-1) {
		    	cout<<"stack underflow"<<endl;
			}
		    else {
		    	cout<<"element popped out"<<stack[top--]<<endl;
			}
		break;
		
		case 3:
			if(top==-1) cout<<"stack is empty";
			else cout<<"stack not empty";
		break;
		
		case 4:
			if(top==size-1) cout<<"full";
			else cout<<"not full";
		break;
		
		case 5:
			for(int i=top; i>=0; i--) {
				cout<<stack[i]<<endl;
			}
		break;
		
		case 6:
			cout<<stack[top]<<endl;
		break;
}
}
} 