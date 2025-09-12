#include <iostream>
using namespace std;

int main() {

    // Concatenate one string to another
    {
        char str1[100], str2[100];
        cout << "Enter first string: ";
        cin >> str1;
        cout << "Enter second string: ";
        cin >> str2;
        int i=0,j=0;
        while(str1[i]!='\0') i++;
        while(str2[j]!='\0') {
            str1[i]=str2[j];
            i++; j++;
        }
        str1[i]='\0';
        cout <<str1 << endl;
    }

    // Reverse a string
    {
        char str[100];
        cout << "\nEnter string to reverse: ";
        cin >> str;
        int len=0;
        while(str[len]!='\0') len++;
        for(int i=len-1;i>=0;i--) cout<<str[i];
        cout << endl;
    }

    // Delete all vowels from the string
    {
        char str[100];
        cout << "\nEnter string to delete vowels: ";
        cin >> str;
        int i=0,j=0;
        while(str[i]!='\0') {
            if(str[i]!='a'&&str[i]!='e'&&str[i]!='i'&&str[i]!='o'&&str[i]!='u'&&
               str[i]!='A'&&str[i]!='E'&&str[i]!='I'&&str[i]!='O'&&str[i]!='U') {
                str[j++]=str[i];
            }
            i++;
        }
        str[j]='\0';
        cout << str << endl;
    }

    // Sort strings in alphabetical order
    {
        int n;
        cout << "\nEnter number of strings: ";
        cin >> n;
        char str[10][100];
        for(int i=0;i<n;i++) cin >> str[i];
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int k=0;
                while(str[i][k]==str[j][k]) k++;
                if(str[i][k]>str[j][k]) {
                    char temp[100];
                    int l=0;
                    while(str[i][l]!='\0'){ temp[l]=str[i][l]; l++; }
                    temp[l]='\0';
                    l=0;
                    while(str[j][l]!='\0'){ str[i][l]=str[j][l]; l++; }
                    str[i][l]='\0';
                    l=0;
                    while(temp[l]!='\0'){ str[j][l]=temp[l]; l++; }
                    str[j][l]='\0';
                }
            }
        }
        for(int i=0;i<n;i++) cout<<str[i]<<endl;
    }

    //  Convert uppercase to lowercase
    {
        char str[100];
        cout << "\nEnter string to convert to lowercase: ";
        cin >> str;
        int i=0;
        while(str[i]!='\0') {
            if(str[i]>='A' && str[i]<='Z') str[i]=str[i]+32;
            i++;
        }
        cout <<str << endl;
    }
}
