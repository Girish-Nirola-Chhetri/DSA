#include<iostream>
#include<stack>
using namespace std;

void insertButtom( stack<int>& s, int data ) {
    // base case
    if( s.empty() ) {
        s.push( data );
        return;
    }

    int num = s.top();
    s.pop();
    insertButtom( s, data );
    s.push( num );
}


void printStack( stack<int> s ) {
    while( !s.empty() ) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main () {

    stack<int> s;
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    printStack( s );

    insertButtom( s, 10 );
    printStack( s );

    return 0;
}