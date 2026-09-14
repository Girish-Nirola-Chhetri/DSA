#include<iostream>
using namespace std;


int fact(int n) {
    if( n==0 ) 
        return 1;
    
    return n * fact( n-1 );
}


int main () {

    int n;
    cout<<"enter n: ";
    cin>> n;

    int ans = fact( n );
    cout<<" fact of "<< n << " is : "<< ans << endl; 


    return 0;
}