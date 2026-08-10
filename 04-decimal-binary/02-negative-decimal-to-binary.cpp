#include<iostream>
#include<math.h>
using namespace std;

int main () {

    int num;
    cout<<"Enter a negative numer : ";
    cin>>num;

    for( int i = 31; i>=0; i-- ) {

        int bit = num >> i;
        int val = bit & 1;

        cout<<val;

        if( i%4 == 0 ) {
            cout<<" ";
        }
    }

    return 0;
}