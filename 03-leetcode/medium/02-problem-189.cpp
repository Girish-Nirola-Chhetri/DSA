#include<iostream>
#include<utility>

using namespace std;


void rotate( int arr[], int n, int k ) {

    k = k%n;
    int s = 0, e= n-k-1;

    while ( s< e ) {
        swap(arr[s], arr[e]);
        s++, e--;
    }

    s = n-k, e = n-1;
    while ( s< e ) {
        swap(arr[s], arr[e]);
        s++, e--;
    }

    s = 0, e = n-1;
    while ( s<e ) {
        swap(arr[s], arr[e]);
        s++, e--;
    }

}



int main () {

    int n;
    cout<<"enter array size: ";
    cin>>n;

    int arr[n];
    cout<<"enter array elements: ";
    for( int i = 0; i<n; i++) {
        cin>>arr[i];
    }

    int k;
    cout<<"ennter k: ";
    cin>>k;

    rotate( arr, n, k);

    for ( int i = 0; i<n ; i++ ) {
        cout<<arr[i]<<" ";
    }



    return 0;
}