// find the complememnt of base 10 of integer

#include<iostream>
using namespace std;

int main () {

    int num;
    cout<<"enter a number : ";
    cin>>num;

    int n = num, mask = 0;
    if( num == 0 ) {
        cout<<"complememt of "<<num<<" is: 1"<<endl;
        return 0;
    }
    while( n != 0 ) {
        mask = ( mask << 1 ) | 1;
        n = n>>1;
    }

    cout<<"mask is: "<<mask<<endl;

    int complememt = ~num & mask;
    cout<<"complememt of "<<num<<" is : "<<complememt<<endl;

    return 0;
}