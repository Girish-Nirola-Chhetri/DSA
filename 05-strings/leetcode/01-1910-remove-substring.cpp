// Given two strings s and part, perform the following operation on s until all occurrences of the substring part are removed:

// Find the leftmost occurrence of the substring part and remove it from s.
// Return s after removing all occurrences of part.

// A substring is a contiguous sequence of characters in a string.

#include<iostream>
#include<string>
using namespace std;

string removeSubString ( string str, string part ) {

    while ( str.length()!= 0 && str.find( part ) < str.length() ) {
        str.erase( str.find( part ), part.length() );
    }

    return str;
}





int main () {

    string s, part;
    cout<<"Enter a string: ";
    cin>>s;

    cout<<"enter the substring: ";
    cin>>part;

    string removed = removeSubString( s, part );
    cout<<"the string after removing the subsequence of "<<part << " is : "<<removed<<endl;

}