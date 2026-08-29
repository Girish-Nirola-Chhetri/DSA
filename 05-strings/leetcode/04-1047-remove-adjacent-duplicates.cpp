// You are given a string s consisting of lowercase English letters. 
// A duplicate removal consists of choosing two adjacent and equal letters and removing them.

// We repeatedly make duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

#include<iostream>
#include<string>
using namespace std;

string removeDuplicates( string str ) {
    int i = 0; 
    while ( i< (int)str.length() - 1) {
        int j = i+1;
        if( str[i] == str[j] ) {
            str.erase(i, 2);
            
            if( i>0) {
                i--;
            }

        }else {
            i++;
        }
    }

    return str;
}



int main() {

    string str;
    cout<<"enter string: ";
    cin>>str;

    string res = removeDuplicates( str );
    cout<<res;

    return 0;
}