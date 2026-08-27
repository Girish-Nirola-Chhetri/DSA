#include<iostream>
#include<utility>
using namespace std;

void printArray (int arr[], int n ) {
    for ( int i = 0; i<n; i++ ) {
        cout<<arr[i]<<" ";
    }
}

void reverseArray(int arr[], int n ) {
    int start = 0, end = n- 1;

    while ( start < end ) {
        swap( arr[start], arr[end]);
        start++, end--;
    }

    printArray(arr, n);
    
}

int main () {

    int n;
    cout<<"enter n: ";
    cin>>n;

    int arr[n];
    
    cout<<"enter the array: ";
    for( int i = 0; i<n; i++ ) {
        cin>>arr[i];
    }

    reverseArray( arr, n);
    

    return 0;
}
