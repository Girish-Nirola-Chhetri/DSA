// find x^n ( mod m)

#include<iostream>
using namespace std;

long long power_mod( int x, int n, int m ) {
    if( m == 1 ) return 0;

    x = x % m;

    long long result = 1;
    while ( n > 0 ) {
        if( n&1 ) {
            result = (result * x) % m;
        }

        x = ( x*x)%m;
        n = n/2;
    }
    return result;
}


int main () {

    long long val = power_mod(2,5,13);
    cout<< val;



    return 0;
}