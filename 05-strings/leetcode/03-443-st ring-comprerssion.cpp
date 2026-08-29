// Given an array of characters chars, compress it using the following algorithm:

// Begin with an empty string s. For each group of consecutive repeating characters in chars:

// If the group's length is 1, append the character to s.
// Otherwise, append the character followed by the group's length.
// The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

// After you are done modifying the input array, return the new length of the array.

// You must write an algorithm that uses only constant extra space.

// Note: The characters in the array beyond the returned length do not matter and should be ignored.

#include<iostream>
#include<string>
#include<vector>
using namespace std;

int getlength( char chars[]) {
    int count = 0;
    for ( int i = 0; chars[i] != '\0'; i++ ) {
        count++;
    }
    return count;
}

int compressString( char chars[] ) {
    int n = getlength( chars );

    int i  =0, ansIndex = 0;
    while( i<n ) {
        int j  = i+1;
        int count = 1;      // initailly pointer is on that element
        while( j<n && chars[i] == chars[j]) {
            j++, count++;
        }

        chars[ansIndex++] = chars[i];
        // int count = j-i;
        if( count > 1 ) {
            string cnt = to_string( count );
            for( char ch: cnt) {
                chars[ansIndex++] = ch;
            }
        }
        i=j;

    } 
    chars[ansIndex] = '\0';

    return ansIndex;

}


int main() {

    char chars[20];
    cout<<"enter the string: ";
    cin>>chars;

    int val = compressString( chars );
    cout<<chars<<" "<<val<<endl;

    return 0;
}