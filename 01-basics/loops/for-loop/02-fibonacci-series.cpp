#include<iostream>
using namespace std;

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int a = 0, b = 1;
    cout<<a<<" "<<b<<" ";

    for( int i=1; i < n-1; i++) {
        int nextNumber = a + b;
        cout<< nextNumber<<" ";

        a = b;
        b = nextNumber;

    }

    return 0;
}