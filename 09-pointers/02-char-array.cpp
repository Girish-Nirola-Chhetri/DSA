#include<iostream>
using namespace std;

int main() {

    char ch[6] = "abcde";

    // this will pring the char array not the first index address as int array
    cout<<ch <<endl;

    char *c = &ch[0];
    cout<< c << endl;       // print 6the array

    cout<< *( c+1) << endl;      // print the first char only


    cout<< &ch << endl;

    cout<< &c <<endl;



    int i = 5;
    int *p1 = &i;
    int **p2 = &p1;

    int num = 10;
    int *ptr1 = &num;
    int *ptr2  = ptr1;

    return 0;
}