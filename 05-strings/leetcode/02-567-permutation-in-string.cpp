// Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.

// In other words, return true if one of s1's permutations is the substring of s2.


#include<iostream>
#include<string>
using namespace std;


bool checkEqual( int a[26], int b[26] ) {
    for ( int i = 0; i<26; i++ ) {
        if( a[i] != b[i] ) {
            return false;
        }
        return true;
    }
}

bool permutation(string s1, string s2 ) {

    // count of char of sub string
    int countTable1[26] = { 0 };
    for ( int i = 0; i<s1.size(); i++ ) {
        int index = s1[i] - 'a';
        countTable1[index]++;

    }

    int countTable2[26] = {0};

    // window size
    int window = s1.length();
    int i = 0;
    while ( i< window && i < s2.length() ) {
        int index = s2[i] - 'a';
        countTable2[index]++;
        i++;

    }

    if( checkEqual(countTable1, countTable2 )) 
        return true;

    
    // change the window
    while ( i<s2.length() ) {
        char newChar = s2[i];
        int index = newChar - 'a';
        countTable2[index]++;

        char oldChar = s2[i-window];
        index = oldChar - 'a';
        countTable2[index]--;

        i++;

        if( checkEqual( countTable1, countTable2 )) {
            return true;
        }
    }


    return false;

}

int main () {

    string s1, s2;
    cout<<"enter s1: ";
    cin>>s1;

    cout<<"enter s2: ";
    cin>>s2;

    bool val = permutation( s1, s2);

    cout<<val;

    return 0;
}