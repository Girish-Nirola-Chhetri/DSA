#include<iostream>
#include<queue>
#include<stack>
using namespace std;


// recursive function to reverse a queue
void reverseQueue(queue<int> &q) {
    if( q.empty() ) return;
    
    int val = q.front();
    q.pop();
    
    reverseQueue(q);
    
    q.push(val);
    
}

// using stack
void reverseQueueUsingStack(queue<int> &q) {
    stack<int> s;

    while ( !q.empty() ){
        int val = q.front();
        q.pop();

        s.push( val );
    }

    while ( !s.empty() ) {
        int val = s.top();
        s.pop();

        q.push( val );
    }

}

