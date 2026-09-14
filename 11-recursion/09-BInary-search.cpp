#include<iostream>
#include<algorithm>
using namespace std;

bool BinarySearch ( int* arr, int n, int key ) {
    int s= 0, e= n-1;
    int mid = s+ (e-s)/2;

    if( s > e ) return 0;

    if( arr[mid] == key ) {
        return 1;

    }else if( arr[mid] > key ) {
        return BinarySearch(arr, mid-1, key);

    }else {
        return BinarySearch( arr+mid+1, e-mid, key );
    }
}

void print ( int* arr, int n ) {
    for ( int i = 0; i<n; i++ ) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main () {

    int n;
    cout<<"enter n: ";
    cin>> n;

    int* arr = new int[n];
    cout<<"enter array elememnts: ";
    for ( int i = 0; i<n; i++ ) {
        cin>> arr[i];
    }

    int key;
    cout<<"Enter key: ";
    cin>>key ;

    sort(arr, arr+n);

    print(arr, n);

    if( BinarySearch(arr, n, key) ) {
        cout<<"key found"<<endl;

    }else {
        cout<<"key not found"<<endl;

    }


    return 0;
}