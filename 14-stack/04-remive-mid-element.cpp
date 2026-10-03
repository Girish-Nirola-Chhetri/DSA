#include<iostream>
#include<stack>
using namespace std;

// iterative
void removeMid( stack<int> &s ) {
    if( s.empty() ) {
        cout<<"stack is empty";
        return;
    }

    stack<int> temp;

    int mid = ( s.size()) / 2;

    int i = s.size() -1;
    while( i != mid ) {
        temp.push( s.top() );
        s.pop();
        i--;
    }

    s.pop();

    while ( !temp.empty() ) {
        s.push( temp.top() );
        temp.pop();
    }
}

// recursive
void recursive_removeMid( stack<int>& s, int i, int size ) {
    // base case
    if( i == size / 2 ) {
        s.pop();
        return;
    }

    int num = s.top();
    s.pop();

    recursive_removeMid( s,i+1, size );
    s.push( num );
}



int main () {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);


    // removeMid( s );
    recursive_removeMid( s, 0, s.size() );


    while( !s.empty() ) {
        cout<< s.top()<<" ";
        s.pop();
    }

    return 0;
}