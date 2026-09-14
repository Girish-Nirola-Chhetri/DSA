#include<iostream>
using namespace std;


int power(int base, int exp) {
    if( exp==0 ) 
        return 1;
    
    return base * power(base, exp-1);
}


int main () {

    int base, exp;
    cout<<"enter base and exponent: ";
    cin>> base >> exp;

    int ans = power( base, exp );
    cout<<" "<< base <<" raised to the power of "<< exp << " is : "<< ans << endl; 


    return 0;
}