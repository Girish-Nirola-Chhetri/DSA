// i/p  -> 234
// o/p =? two theree four

#include<iostream>
#include<string>
using namespace std;


void sayDigit( int n ) {
    string arr[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};

    if( n == 0 ) {
        return;
    }

    int digit = n % 10;
    n = n/10;

    sayDigit( n );
    cout<< arr[digit]<< " ";

}



int main () {

    int n;
    cout<<"enter n : ";
    cin>> n;

    if( n == 0 ) {
        cout<< "Zero";
    }else {
        sayDigit( n );

    }



    return 0;
}