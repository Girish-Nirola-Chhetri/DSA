#include<iostream>
using namespace std;

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i = 1;
    while( i<=n ) {
        int j = i, k = 1, l = 1;
        
        while ( j<n ) {
            cout<<" ";
            j++;
        }

        // prin first triangle
        while ( k<=i ) {
            cout<<k;
            k++;
        }

        //print second triangle
        while ( l<i ) {
            cout<<i-l;
            l++;
        }

        cout<<endl;
        i++;
    }

    return 0;
}