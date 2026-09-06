// find greatest common divisor of a, b

#include<iostream>
using namespace std;


int gcd(int a, int b ) {
    if( a == 0 ) return b;
    if( b == 0 ) return a;

    while ( a>0 && b > 0 ) {
        if( a > b ) {
            a = a % b;

        }else {
            b = b % a;

        }
    }
    return ( a== 0 )? b : a;
 
}


int main () {

    
    int val = gcd( 120, 150 );
    cout<<val;


    return 0;
}