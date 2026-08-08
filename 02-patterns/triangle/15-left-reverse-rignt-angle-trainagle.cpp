#include<iostream>
using namespace std;

int main() {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i = 1;
    while ( i<=n ) {
        int j =i, k =1;
        
        while ( j<=n ) {
            cout<<"*";
            j++;
        }

        while ( k < i ) {
            cout<<" ";
            k++;
        }

        cout<<endl;
        i++;
        
    }

    return 0;
}