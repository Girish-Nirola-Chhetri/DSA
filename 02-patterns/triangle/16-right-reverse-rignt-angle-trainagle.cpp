#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i = 1;
    while ( i<=n ) {
        int j =i, k =1;

        while ( k < i ) {
            cout<<" ";
            k++;
        }

        while ( j<=n ) {
            cout<<"*";
            j++;
        }

        cout<<endl;
        i++;
        
    }

    return 0;
}