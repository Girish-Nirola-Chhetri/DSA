#include<iostream>
using namespace std;




int main () {

    int row = 3, col = 2;

    int** arr = new int* [row];        // ROWS    // createa a array of pointer

    for ( int i = 0; i<row; i++ ) {     // fopr each pointer create a array 

        arr[i] = new int[col];          // *(arr + i ) = new int[]
    }

    // incput
    cout<<"enter array elements: ";
    for ( int i =0; i<row; i++ ) {
        for ( int j = 0; j< col; j++ ) {
            cin>> arr[i][j];
        }
    }

    //output
    cout<< "array elements are: "<<endl;
    for ( int i =0; i<row; i++ ) {
        for ( int j = 0; j< col; j++ ) {
            cout<< arr[i][j] << " ";
        }
        cout<<endl;
    }
    


    //FRERE SPAC colforst then row

    for ( int i = 0; i< row; i++ ) {
        delete [] arr[i];
    }
    delete []arr;


    return 0;
}