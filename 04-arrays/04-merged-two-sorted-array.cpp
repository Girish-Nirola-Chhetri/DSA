#include<iostream>
using namespace std;


void merge ( int arr1[], int n, int arr2[], int m, int merged[] ) {
    int i = 0, j = 0, k = 0;

    while ( i < n && j < m ) {
        if( arr1[i] < arr2[j] ) {
            merged[k] = arr1[i];
            i++;

        } else {
            merged[k] = arr2[j];
            j++;
        }
        k++;
    }

    while ( i<n ) {
        merged[k] = arr1[i];
        i++, k++;
    }

    while ( j<m ) {
        merged[k] = arr2[j];
        j++, k++;
    }
}


void printArray( int arr[], int n ) {
    for ( int i = 0; i<n; i++ ) {
        cout<<arr[i]<<" ";
    }
}


int main () {

    int n, m;
    cout<<"ethter the size of two array: ";
    cin>>n>>m;

    int arr1[n], arr2[m], merged[m+n];


    cout<<"enter element in 1st array ( sorted ): ";
    for ( int i = 0; i<n; i++ ) {
        cin>>arr1[i];
    }

    cout<<"enter element in 2nd array ( sorted ): ";
    for ( int i = 0; i<m; i++ ) {
        cin>>arr2[i];
    }

    merge( arr1, n, arr2, m, merged );

    printArray(merged, m+n);


    return 0;
}