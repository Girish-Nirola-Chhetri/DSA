#include<iostream>
#include<vector>
using namespace std;

int binarySearch( vector<vector<int>>& matrix, int key) {
    int row =  matrix.size();
    int col = matrix[0].size();

    int s = 0, e = row * col - 1;
    int mid = s + ( e- s)/2;

    while ( s<= e ) {
        if ( matrix[mid/col][mid%col] == key ){
            return mid;

        }else if( matrix[mid/col][mid%col] < key  ) {
            s = mid+1;

        }else {
            e = mid-1;
        }

        mid = s + ( e- s)/2;
    } 
    return -1;

}

int main () {

    vector<vector<int>> matrix;

    int rows, cols;
    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    int val;
    cout<<"Enter the elements: ";
    for ( int i = 0; i<rows; i++) {
        vector<int> row;
        for ( int j = 0; j<cols; j++ ) {
            cin>>val;
            row.push_back( val);

        }
        matrix.push_back( row );
    }
    
    int key;
    cout<<"enter the key : ";
    cin>>key;

    int index = binarySearch( matrix, key );
    if( index >= 0 ) {
        cout<<"key found at index : "<<index<<endl;
    }else {
        cout<<"not  found"<<endl;
    }


    return 0;
}