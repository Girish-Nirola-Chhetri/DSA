#include<iostream>
using namespace std;

int main () {

    int num = 6;        // num var is just thebaddress of thememory 
    cout<< num<<endl;

    cout<< " address of num is : "<< &num <<endl;


    // declaration of pointers
    
    int *ptr = &num;

    cout<< ptr << endl;             // the address it stores 
    cout<< *ptr << endl;            // the value at the address iyt stroes

    cout<< (*ptr)++<<endl;
    cout<< (*ptr)++<<endl;


    int *ptr2 = nullptr;
    int a = 10;
    ptr2 = &a;

    cout<<"iinitial value of a: "<< a<< endl;

    (*ptr2) = (*ptr2) * 2;          // the changes are made directly in the address memory
    cout<<"updated value of a: "<< a<< endl;

    return 0;
}