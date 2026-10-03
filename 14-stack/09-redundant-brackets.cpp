#include<iostream>
#include<stack>
using namespace std;

bool hasRedundantBrackets( string str ) {

    stack<char> s;

    int n = str.length();
    for ( int i = 0; i< n; i++ ) {
        char ch = str[i];

        if( ch == '(' || ch == '+' || ch == '*' || ch == '-' || ch == '/' || ch == '%' ) {
            s.push( ch );

        }else {
            if( ch == ')') {
                bool isRedundant = true;
                while ( s.top() != '(' ) {
                    int top  = s.top();
                    if( top == '+' || top == '*' || top == '-' || top == '/' || top == '%' ) {
                        isRedundant = false;
                    }
                    s.pop();
                }

                if ( isRedundant ) return true;

                s.pop();
            }

        }
    }

    return false;

}



int main () {

    string str = "((a+b))";

    cout<< hasRedundantBrackets( str );



    return 0;
}