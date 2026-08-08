// a b c
// b c d
// d e f            => a + i + j -2

#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i =1;
    char ch;
    while ( i<= n ) {
        int j = 1;
        while ( j<= n) {
            ch = 'a' + i + j - 2;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    } 

    cout<<"-----------------------------"<<endl;

    i = 1;
    while( i<= n ) {
        int j = 1;
        while ( j<=i ) {
            ch = 'a' + i+j-2;
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    }

    return 0;
}