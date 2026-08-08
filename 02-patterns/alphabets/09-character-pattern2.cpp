// a b c 
// a b c
// a b c

#include<iostream>
using namespace std;

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i =1;
    while ( i<= n ) {
        char ch = 'a';
        int j = 1;
        while ( j<=n ) {
            cout<<ch<<" ";
            ch++;
            j++;
        }
        cout<<endl;
        i++;
    } 

    return 0;
}