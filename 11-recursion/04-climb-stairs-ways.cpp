// for n stairs count the number of ways to climb the stairs if we can take 1 or 2 steps at a time

#include<iostream>
using namespace std;

int climbStiarsWays( int n ) {
    if( n ==0 || n==1 ) return 1;

    return climbStiarsWays( n-1 ) + climbStiarsWays( n-2 );
}


int main () {

    int n;
    cout<<"enter n : ";
    cin>> n;

    int val = climbStiarsWays( n );
    cout<< val<<endl;

    return 0;
}