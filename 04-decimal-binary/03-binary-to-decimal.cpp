#include<iostream>
#include<math.h>
using namespace std;

int main () {

    int num;
    cout<<"Enter biary numer : ";
    cin>>num;

    int n = num, decimal = 0, i = 0;
    while ( n != 0 ) {
        int digit = n % 10;
        decimal = decimal + ( digit * pow(2, i) );
        
        n = n / 10;
        i++;
    }

    cout<<"Decimal of "<<num<<" : "<<decimal<<endl;

    return 0;
}