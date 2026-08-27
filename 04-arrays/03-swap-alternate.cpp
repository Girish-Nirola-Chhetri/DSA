#include<iostream>
#include<utility>
using namespace std;

void printArray( int arr[], int n ) {
    for ( int i = 0; i<n; i++ ) {
        cout<<arr[i]<<" ";
    }
}

void swapAlternate( int arr[], int n ) {

    for ( int i =0; i< n; i+=2 ) {
        if( i+1 < n ){
            swap(arr[i], arr[i+1]);
        }
    }

    printArray( arr, n);
}


int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int arr[n];
    cout<<"enter array elements: ";

    for( int i = 0; i<n; i++ ) {
        cin>>arr[i];
    }

    swapAlternate( arr, n );

    return 0;
}