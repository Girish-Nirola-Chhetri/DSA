//Reverse Ineteger problem

#include<iostream>
#include<climits>
using namespace std;

int main () {

    int num, rev = 0, digit;
    cout<<"enter the number m: ";
    cin>>num;

    int n = num, i = 0 ;
    while ( n != 0 ) {
        digit = n % 10;

        if( rev > INT_MAX / 10 || rev < INT_MIN / 10 ) {
            cout<<"out of range";
            return 0;
        }

        rev = ( rev * 10 ) + digit;

        n = n / 10;
        i++;
    }
    cout<<rev;


    return 0;
}