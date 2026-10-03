#include<iostream>
#include<stack>
using namespace std;

void sortInsert( stack<int>& s, int data ) {
    if( s.empty() || ( !s.empty() && s.top() < data ) ) {
        s.push( data );
        return;
    }
    
    int x = s.top();

    s.pop();
    sortInsert(s, data );
    s.push( x );
    
}

void sortStack( stack<int>& s ) {
    if( s.empty() ) {
        return;
    };

    int x = s.top();
    s.pop();

    sortStack( s );
    sortInsert( s, x );
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
    s.push(1);
    s.push(2);
    s.push(15);
    s.push(4);
    s.push(5);

    printStack( s );

    sortStack( s );

    printStack( s );

    return 0;
}