#include<iostream>
#include<utility>
using namespace std;

int getLength( char name[] ) {
    int count = 0;
    for( int i = 0; name[i] != '\0'; i++ ) {
        count++;
    }

    return count;
}


void reverse( char arr[] ) {
    int n =  getLength( arr );

    int s = 0, e = n-1;
    while( s < e ) {
        swap(arr[s], arr[e]);
        s++, e--;
    }

}

int main() {

    char name[20];
    cout<<"enter name: ";
    cin>>name;


    cout<<"original string: "<< name<<endl;

    reverse(name);
    cout<<"after reverse: "<< name<<endl;


    return 0;
}