#include<iostream>
using namespace std;

void update( int& n ) {
    n++;
}

int& val() {            // bad practice
    int val = 10;
    int& ref = val;

    return ref;

}

int main() {
    int i =10;
    cout<< "before: "<< i<< endl;       // 10

    update( i );

    cout<< "after: "<< i<< endl;        // 11

    cout<< val()<< endl;
    int ans = val();
    ans++;

    cout<< val();


    return 0;
}