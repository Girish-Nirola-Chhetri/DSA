#include<iostream>
using namespace std;

int main() {

    char ch;
    cout<<"enter a character or number form 0 to 9: ";
    cin>>ch;

    if( ch >= 'a' && ch <= 'z' ) {
        cout<<"character is lowercase"<<endl;

    }else if( ch >= 'A' && ch <= 'Z' ) {
        cout<<"character is UPPERCASE"<<endl;

    }else if( ch>= '0' && ch<='9') {
        cout<<"character is numeric"<<endl;

    }else {
        cout<<"Invalid Input"<<endl;
    }

    return 0;
}