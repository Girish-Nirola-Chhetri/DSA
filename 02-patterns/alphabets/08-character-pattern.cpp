// A A A
// B B B
// C C C

#include <iostream>
using namespace std;    

int main() {
    int n;
    cout<<"enter n: ";
    cin>>n;

    int i=1;
    char ch = 65;
    // while( i<=n ) {
    //     int j = 1;
    //     while ( j<=n ) {
    //         cout<<ch<<" ";
    //         j++;
    //     }
    //     cout<<endl;
    //     ch++;
    //     i++;
    // }

    char chh = 'A';
     while( i<=n ) {
        int j = 1;
        while ( j<=n ) {
            cout<<chh<<" ";
            j++;
        }
        cout<<endl;
        chh = chh+ 1;
        i++;
    }
}