// Hamming weight problem => find the total number of 1 ( set bit ) in the binary form of a given number


#include<iostream>
#include<string>
using namespace std;

int main() {

    int n;
    cout<<"Enter n: ";
    cin>>n;


    // using bitwise AND and right shift operators
    int num = n, count = 0;;
    while( num != 0 ) {
        if( num & 1 ) {
            count++;
        }
        num = num >> 1;
    }
    cout<<"The number of set bit in "<< n << " : "<< count<<endl;



    return 0;
}