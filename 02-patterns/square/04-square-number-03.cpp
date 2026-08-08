// 1 2 3 4
// 5 6 7 8
// 9 10 11 12
// 13 14 15 16

#include<iostream>
using namespace std;

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int count=1, i=1;
    while ( i<= n) {

        int j = 1;
        while ( j<=n ) {

            cout<<count<<" ";
            count++;
            j++;
        }

        cout<<endl;
        i++;
    }

    return 0;
}