#include<iostream>
#include<stack>
using namespace std;

bool matches( char s, char t ) {
    if( s == '(' && t == ')' ) return true;
    if( s == '[' && t == ']' ) return true;
    if( s == '{' && t == '}' ) return true;

    return false;
}



bool validParenthesis( string expression ) {

    int n = expression.length();
    if( n == 0 ) return true;

    stack<char> s;
    for ( int i = 0; i<n; i++ ) {
        char ch = expression[ i ];

        // if opennning bracket push to stack
        if ( ch == '(' || ch == '[' || ch == '{' ) {
            s.push( ch );

        } else {
            // if closing bracket compare and pop
            if( ! s.empty() ) {
                if( matches( s.top(), ch )) {
                    s.pop();

                }else {
                    return false;
                }

            }else {
                // unbalanced expression -> [()]]
                return false;
            }
        }
    }

    if ( s.empty() ) {
        return true;

    }else {
        return false;

    }
}

int main () {

    string exp = "[({{()}})]}";

    if( validParenthesis( exp ) ) {
        cout<< "valid expression "<<endl;

    }else {
        cout<<" invlaid expression "<<endl;
    }

    return 0;
}