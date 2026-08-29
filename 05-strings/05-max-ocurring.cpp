// max-occurring char

#include<iostream>
#include<string>
using namespace std;

char maxOccurringChar( string str ) {
    int arr[26] = {0};

    for ( int i = 0; i<str.length(); i++ ) {
        // add the count of char to the arr

        int num = str[i] - 'a';     // thios gives the index in array  if ch = f ->  f -  a = 5 
        arr[num]++;
        
    }

    // find max occuring char
    int max = -1, ans = 0;
    for( int i  = 0; i<26; i++ ) {
        if( max < arr[i] ) {
            ans = i;
            max = arr[i];
        }
    }

    return 'a' + ans;        // returns the max occurring char
}

int main () {
    string s;
    cout<<"enter a string: ";
    cin>>s;

    char ans = maxOccurringChar( s );
    cout<<"the maxinum occurring character is: "<<ans;
    
    return 0;
}