#include<iostream>
using namespace std;

int main () {

    int i = 10;         // static allocated in statck
    cout<< i<< endl;

    int* num = new int(10);         // value initialization heap 4 byte in heap 8 bytes to store the head address in stack
    cout<< num<< endl;  //ADDRESS
    cout<< "value is: "<< *num<<endl;

    //we need tp free the heap memory as well

    // runtime 
    int * val = new int;
    cin>> *val;
    cout<< "value is: "<< *val<<endl;

    // free space
    delete num;
    delete val;



    //1d array dma
    int *arr = new int[5];
    cout<< "enter the array elements: ";
    for( int i = 0; i< 5; i++ ) {
        cin>> arr[i] ;                   // equal to *(arr+i)
    }

    cout<< "array elements are: ";
    for( int i = 0; i< 5; i++ ) {
        cout<< arr[i] << " ";                   // equal to *(arr+i)
    }
    cout<<endl;

    
    // free space 
    delete []arr;


    int* arr2 = new int[5]{1,2,3,4,5};        // 1d array dma with initialization
    cout<< "array elements are: ";
    for( int i = 0; i< 5; i++ ) {
        cout<< arr2[i] << " ";                   // equal to *(arr2+i)
    }
    cout<<endl;

    // free space
    delete []arr2;

    return 0;
}