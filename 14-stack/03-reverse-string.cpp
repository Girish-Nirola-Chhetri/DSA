#include<iostream>
#include<stack>
using namespace std;

int main() {
    string str = "girish";

    stack<char> s;
    for( int i = 0; i< str.length(); i++ ) {
        char ch = str[i];
        s.push(ch);
    }

    string revStr = "";
    int i = 0;
    while ( ! s.empty() ) {
        char ch = s.top();
        revStr.push_back( ch );

        s.pop();
    }

    cout<< revStr;

    return 0;
}