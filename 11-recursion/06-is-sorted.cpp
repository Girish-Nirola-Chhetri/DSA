#include<iostream>
using namespace std;

bool isSorted( int arr[], int n) {
    if( n ==0 || n == 1 ) {
        return true;
    }

    if( arr[0]> arr[1]) {
        return false;
    }else {
        return isSorted( arr+1, n-1);
    }
}

int main () {

    int arr[10];
    cout<<"enter array elememnts: ";
    for ( int i = 0; i<10; i++ ) {
        cin>> arr[i];
    }

    if( isSorted( arr+1, 10 )) {
        cout<<"Sorted: True"<<endl;

    }else {
        cout<<"Sorted: False"<<endl;
    }

    return 0;
}