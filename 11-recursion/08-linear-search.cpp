#include<iostream>
using namespace std;

bool linearSearch( int* arr, int n, int key){
    if ( n == 0 ) return 0;

    if( arr[0] == key ) {
        return 1;

    }else {
        return linearSearch( arr+1, n-1, key);
    }
    

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

    if( linearSearch(arr, n, key) ) {
        cout<<"key found"<<endl;

    }else {
        cout<<"key not found"<<endl;

    }


    return 0;
}