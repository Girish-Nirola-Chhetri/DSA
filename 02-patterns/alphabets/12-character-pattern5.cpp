// a b c
// d e f 
// g h i 


// a
// b c
// d e f


#include<iostream>
using namespace std;

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i = 1;
    char ch = 'A';
    while (i<=n) {
        int j = 1;
        while ( j<=n ) {
            cout<<ch<<" ";
            ch++, j++;
        }
        cout<<endl;
        i++;
    }


    cout<<"----------------------------"<<endl;
    i = 1;
    ch = 'A';
    while ( i<=n ) {
        int j = 1;
        while ( j<=i ) {
            cout<<ch<<" ";
            ch++, j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}