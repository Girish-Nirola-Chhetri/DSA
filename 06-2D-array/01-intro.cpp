#include<iostream>
using namespace std;


int main () {

    int arr[3][3] ={ 1,2,3,4,5,6,7,8,9}; // rowise 

    for ( int i = 0; i<3; i++ ) {
        for ( int j = 0; j<3; j++ ) {
            cout<< arr[i][j] <<" ";

        }
        cout<<endl;
    }

    // give  rowwise value
    int arr2[3][3] = { {1,4,7}, {2,5,8}, {3,6,9}} ;

    cout<<"second array: "<<endl;
    for ( int i = 0; i<3; i++ ) {
        for ( int j = 0; j<3; j++ ) {
            cout<< arr2[i][j] <<" ";

        }
        cout<<endl;
    }

    // userinput array
    cout<<"enter array elements: ";
    for ( int i = 0; i<3; i++) {
        for( int j = 0; j<3; j++ ) {
            cin>>arr[i][j];
        }
    }

    cout<<"user input array: "<<endl;
    for ( int i = 0; i<3; i++ ) {
        for ( int j = 0; j<3; j++ ) {
            cout<< arr[i][j] <<" ";

        }
        cout<<endl;
    }


    return 0;
}