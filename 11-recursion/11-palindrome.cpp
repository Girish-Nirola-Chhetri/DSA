#include<iostream>
#include<string>
using namespace std;

bool palindrome ( string str, int i, int j ) {
    if ( i > j ) return true;

    if( str[i] != str[j] ) {
        return false;
    }
    i++, j--;

    return palindrome( str, i, j);

}

int main() {

    string s = "girishsirig";

    if( palindrome(s, 0, s.length() - 1)) {
        cout<< "string is palindrome"<<endl;
    } else {
        cout<< "string is not palindorme"<< endl;
    }


    return 0;
}