#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom( stack<int>&s, int data ) {
    if( s.empty() ) {
        s.push( data );
        return;
    }

    int x = s.top();
    s.pop();
    insertAtBottom( s, data );
    s.push( x );
}

void reverseStack( stack<int>& s ) {
    // base case
    if( s.empty() ){
        return;
    }

    int x = s.top();
    s.pop();
    reverseStack( s );
    insertAtBottom( s, x );

}


void printStack( stack<int> s ) {
    while( !s.empty() ) {
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<endl;
}

int main() {

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    printStack( s );

    reverseStack( s );

    printStack( s );

    return 0;
}