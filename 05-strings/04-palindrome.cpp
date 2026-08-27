#include<iostream>
#include<utility>
using namespace std;

int getLength( char name[] ) {
    int count = 0;
    for( int i = 0; name[i] != '\0'; i++ ) {
        count++;
    }

    return count;
}


bool isPalindrome( char str[] ) {
    int n = getLength( str );

    int s = 0, e= n-1;
    while ( s < e ) {

        if( str[s] != str[e] ) 
            return false;
        
        s++, e--;
    }
    return true;
}



int main() {

    char str[20];
    cout<<"enter string: ";
    cin>>str;


    if( isPalindrome( str )) {
        cout<<str<<" is a palindrome"<<endl;

    }else {
        cout<<str<<" is not a palindrome"<<endl;

    }

    return 0;
}