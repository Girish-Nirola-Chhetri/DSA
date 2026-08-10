#include<iostream>
#include<math.h>
using namespace std;

int main () {

    int num;
    cout<<"Enter num: ";
    cin>>num;

    int n = num, binary = 0, i = 0;
    while ( n != 0) {
        
        int bit = n & 1;
        binary += ( bit * pow(10, i));
        
        n = n>>1;
        i++;
    }

    cout<<"Binary of "<< num << " : "<< binary <<endl;

    return 0;
}