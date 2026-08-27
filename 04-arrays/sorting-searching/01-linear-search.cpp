#include<iostream>
#include<vector>
using namespace std;


int linearSearch( vector<int>& arr, int key) {
    int n = arr.size();

    for ( int i = 0; i<n; i++ ) {
        if( arr[i] == key ) {
            return i;
        }
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

    int position = linearSearch( arr, key );
    if( position == -1 ) {
        cout<<"not found"<<endl;
        
    } else {
        cout<<"found ar index "<<position<<endl;
    }

    return 0;
}
