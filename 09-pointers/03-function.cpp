#include<iostream>
using namespace std;

void print( int *p ) {
    p = p+1;

    cout<< "p in function: "<< p<< endl;

    cout<< *p <<endl;       // rrandom value

}


int getSUm( int *arr, int n ) {
    int sum = 0;
    for (int i= 0; i<n; i++ ) {
        sum += *arr;
        arr++;
    }

    return sum;
}



int main () {

    int n =6;
    int *p = &n;

    cout<< "p before: "<< p<< endl;

    print(p);

    cout<< "p after: "<< p<< endl;      // remain the same
    cout<< *(p+1) <<endl;




    // arrays
    int arr[5] = { 1,2,3,4,5};
    int sum = getSUm( arr+3, 5-3);

    cout<< sum << endl;



    return 0;
}