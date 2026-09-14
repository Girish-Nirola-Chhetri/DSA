#include<iostream>
using namespace std;


int power( int a, int n ) {
    if ( n == 0 ) return 1;
    if ( n == 1 ) return a;

    int ans = power( a, n/2 );

    if( n&1 ) {
        return a* ans * ans;
    }else {
        return ans* ans;
    }
}


int main() {

    long long int val = power( 3,12 );
    cout<< val <<endl;

    return 0;
}