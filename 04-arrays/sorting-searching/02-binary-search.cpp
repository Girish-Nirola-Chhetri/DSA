#include<iostream>
#include<vector>
using namespace std;


int binarySearch( vector<int>& arr, int key) {
    int n = arr.size();
    int s = 0, e = n-1;
    int mid = s + ( e - s )/2;

    while ( s<=e ) {
        if( arr[mid] == key ) 
            return mid;

        else if ( arr[mid] < key ) 
            s = mid + 1;

        else 
            e = mid - 1;

        mid = s + ( e - s )/2;
    }

    return -1;
    
}

int main () {

    vector<int> arr(5);

    cout<<"enter array elements: ";
    for ( int i = 0; i<5; i++ ) {
        cin>>arr[i];
    }

    int key;
    cout<<"enter key: ";
    cin>>key;

    int position = binarySearch( arr, key );
    if( position == -1 ) {
        cout<<"not found"<<endl;
        
    } else {
        cout<<"found ar index "<<position<<endl;
    }

    return 0;
}
