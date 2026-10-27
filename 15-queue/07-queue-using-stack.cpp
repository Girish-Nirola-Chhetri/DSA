#include<iostream>
#include<stack>
using namespace std;

class Queue {
public:
    stack<int> s1;
    stack<int> s2;
    int top1, top2;

    Queue() {
        this-> top1 = -1;
        this-> top2 = -1;
    }

    void push( int data ) {
        s1.push( data );
    }

    void pop() {
        if( s1.empty() && s2.empty() ) 
            return;

        if( s2.empty() ) {
            while( s1.empty() ) {
                s2.push( s1.top() );
                s1.pop();
            }
        }
        
        s2.pop();
    }

    int front() {
        if ( s1.empty() && s2.empty() ) return -1;

        if( s2.empty() ) {
            while( !s1.empty() ) {
                s2.push( s1.top() );
                s1.pop();
            }
        }

        return s2.top();
    }

}; 


int main() {

    Queue q;
    q.push(1);
    q.push(2);
    cout<< q.front() <<endl;

    q.pop();
    q.push(10);
    cout<< q.front() <<endl;


    return 0;
}