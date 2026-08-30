#include<iostream>
using namespace std;

int largestRowSum ( int arr[][3], int row, int col ) {

    int maxSum = INT32_MIN;
    int rowIndex = -1;
    for ( int i = 0; i<row; i++) {
        int sum = 0;
        for ( int j = 0; j< col; j++ ) {
            sum += arr[i][j];

        }
        if(sum > maxSum ) {
            maxSum = sum;
            rowIndex = row;
        }
    }

    cout<<" maximum sum is : "<< maxSum<<endl;

    return rowIndex;
}
 
int main () {

    int arr[3][3];

    cout<<"enter array elements: ";
    for( int i = 0; i< 3; i++ ) {
        for ( int j = 0; j<3; j++ ) {
            cin>> arr[i][j];
        }
    }

    int row = largestRowSum( arr, 3,3);
    cout<<" row: "<<row<<endl;

    return 0;
}