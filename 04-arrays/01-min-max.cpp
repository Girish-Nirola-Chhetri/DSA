#include<iostream>
using namespace std;

int min( int arr[], int n ) {
    int min = INT32_MAX;
    for ( int i = 0; i<n; i++ ) {
        if( arr[i] < min ) {
            min = arr[i];
        }
    }
    return min;
}

int max( int arr[], int n ) {
    int max = INT32_MIN;
    for ( int i = 0; i<n; i++ ) {
        if( arr[i] > max ) {
            max = arr[i];
        }
    }
    return max;
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

    cout<<"min value: "<< min( arr, n)<<endl;
    cout<<"max value: "<<max(arr, n) <<endl;

    return 0;
}
