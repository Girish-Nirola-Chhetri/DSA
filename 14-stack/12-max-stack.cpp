#include<iostream>
#include<stack>
using namespace std;

class SpecialStack {
  public:
    stack<int> s;
    long long int max;

    SpecialStack() {
        max = INT8_MIN;
    }

    void push(int x) {
        if( s.empty() ) {
            s.push( x );
            max = x;
            return ;
            
        }
        if( x > max ) {
            long long  val = 2* x - max;           // x was more than max so this val will always benmore tan new max
            max = x;
            s.push(val);
        }else {
            s.push(x);
        }
    }

    void pop() {
        if( s.empty() ) return ;
        
        if( s.top() > max ) {
            max = 2*max - s.top();
            s.pop();
        }else {
            s.pop();
        }
        
        if( s.empty ()) {
            max = -1;
        }
    }

    int peek() {
        
        if (s.empty()) return -1;
        
        if( s.top() > max ) {
            return max;
        }else {
            return s.top();
        }
    }

    bool isEmpty() {
        if( s.empty() ) return true;
        
        return false;
    }

    int getMax() {
        return max;
    }
};