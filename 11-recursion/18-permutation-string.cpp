#include<iostream>
#include<vector>
#include<string>
using namespace std;

void permutation( string str, int index, vector<string>&ans) {
    if( index >= str.length() ) {
        ans.push_back( str );
        return;
    }

    for ( int i  = index; i< str.length(); i++ ) {
        swap(str[index], str[i]);
        
        permutation(str, index+1, ans);

        // backtracking
        swap( str[index], str[i]);
    }
}


int main () {

    string s;
    cout<<"Enter a string: ";
    cin>> s;

    string output;
    vector<string> ans;
    
    permutation( s, 0, ans );

    cout<<"permutations are: ";
    for ( int i =0; i<ans.size(); i++ ) {
        cout<< ans[i] <<" ";
    }




    return 0;
}