// a 
// b b
// c c c            a+i-1

#include<iostream>
using namespace std;

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int i = 1;
    while( i<=n ) {
        int j =1;
        char ch = 'a' + i - 1;
        while( j<= i ) {
            cout<<ch<<" ";
            j++;
        }
        cout<<endl;
        i++;
    } 

    return 0;
}