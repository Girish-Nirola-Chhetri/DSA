#include<iostream>
using namespace std;


void rowwiseSum ( int arr[][3], int row, int col ) {
    for ( int i = 0; i< row; i++ ) {
        int sum = 0;
        for ( int j = 0; j<col; j++ ) {
            sum += arr[i][j];
        }
        cout<<"sum of row "<< i+1 << " is: "<< sum<<endl;
    }
}



void columnwiseSum ( int arr[][3], int row, int col ) {
    for ( int j = 0; j< col; j++ ) {
        int sum = 0;
        for ( int i = 0; i<row; i++ ) {
            sum += arr[i][j];
        }
        cout<<"sum of column "<< j+1 << " is: "<< sum<<endl;
    }
}

int main() {


    int arr[3][3];

    cout<<"enter array elements: ";
    for( int i = 0; i< 3; i++ ) {
        for ( int j = 0; j<3; j++ ) {
            cin>> arr[i][j];
        }
    }

    rowwiseSum(arr, 3,3);

    cout<<endl<<endl;

    columnwiseSum( arr, 3,3);




    return 0;
}