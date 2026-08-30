// search a target in a 2d array where boyth rows and cols are sorted 

#include<iostream>
#include<vector>
using namespace std;



bool search( vector<vector<int>>& matrix, int target) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    int rowIndex = 0, colIndex = cols -1;
    while( rowIndex < rows && colIndex >= 0) {
        int element = matrix[rowIndex][colIndex];

        if( element == target ) {
            return true;

        }else if( element > target ) {
            colIndex--;

        }else {
            rowIndex++;
        }
    }

    return false;

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

    int cal = search( matrix, key );
    if ( val ) {
        cout<<"found"<<endl;
    }else {
        cout<<"not found"<<endl;
    }

    return 0;
}