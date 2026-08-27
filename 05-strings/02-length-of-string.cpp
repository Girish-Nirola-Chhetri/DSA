#include<iostream>
#include<vector>
using namespace std;

int getLength( char name[] ) {
    int count = 0;
    for( int i = 0; name[i] != '\0'; i++ ) {
        count++;
    }

    return count;
}

int main() {

    char name[20];
    cout<<"enter name: ";
    cin>>name;

    int length = getLength( name );
    cout<<"Length of name is: "<< length <<endl;


    return 0;
}