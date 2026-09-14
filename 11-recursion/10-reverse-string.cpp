#include<iostream>
#include<string>
using namespace std;

void reverse ( string& str, int i, int j ) {
    if ( i>j ) return ;

    swap( str[i], str[j]);
    i++, j--;
    reverse( str, i, j);
}

int main() {

    string s = "girish";
    int i = 0, j = s.length() -1;

    cout<<"original: "<< s <<endl;
    reverse( s, i, j);

    cout<<"Reversed: "<< s << endl;



    return 0;
}