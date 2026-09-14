#include<iostream>
using namespace std;

void merge ( int arr[], int s, int e ) {

    int mid = s + ( e-s)/2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int* left = new int[len1];
    int* right = new int[len2];

    // copy values
    int k = s;
    for ( int i = 0; i<len1; i++ ) {
        left[i] = arr[k++];
    }

    for ( int i = 0; i<len2; i++ ) {
        right[i] = arr[k++];
    }

    // merge the two arrays 
    int i  = 0, j = 0;
    k = s;
    while ( i< len1 && j < len2 ) {
        if( left[i] < right[j] ) {
            arr[k++] = left[i++];

        }else {
            arr[k++] = right[j++];

        }
    }

    while ( i< len1 ) {
        arr[k++] = left[i++];

    }

    while ( j < len2 ) {
        arr[k++] = right[j++];

    }
   

    delete []left;
    delete []right;

}

void mergeSort( int arr[], int s, int e ) {
    if ( s >= e ) return ;
    int mid = s + ( e-s)/2;

    // sort left part
    mergeSort( arr, s, mid );

    // srot right part
    mergeSort( arr, mid+1, e );

    merge ( arr, s, e );


}

int main () {

    int n;
    cout<<"enter n: ";
    cin>> n;

    int *arr = new int[n];
    cout<<"Enter the elements of array: ";
    for ( int i = 0; i<n; i++ ) {
        cin>> arr[i];
    }

    cout<<"Before: ";
    for ( int i = 0; i<n; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    mergeSort( arr, 0, n-1);


    cout<<"After: ";
    for ( int i = 0; i<n; i++ ) {
        cout<< arr[i]<< " ";
    }


    return 0;
}