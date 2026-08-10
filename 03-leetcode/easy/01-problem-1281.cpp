#include<iostream>
using namespace std;

int main () {

    int num;
    cout<<"enter number: ";
    cin>>num;

    int n = num;
    int sum = 0, product = 1;

    while( n>0 ) {
        int digit = n % 10;
        n = n / 10;

        sum += digit, product *= digit;
    }
    
    int difference = product - sum;
    cout<<"The difference btw the product and sum of digits of "<<num<<" : "<<difference;

    return 0;
}