#include<iostream>
#include<vector>
#include<string>
using namespace std;

void subsequences( string& str, int index, string current, vector<string>& ans ) {
    if ( index >= str.length()) {
        ans.push_back( current );
        return;
    }

    //exclude
    subsequences( str, index+1, current, ans );

    //include
    current.push_back( str[index]);
    subsequences( str, index+1, current, ans);


}



int main () {

    string s;
    cout<<"Enter a string: ";
    cin>> s;

    string subsequence = "";
    vector<string> ans;


    subsequences( s, 0, subsequence, ans);

    cout<<"susequences are: ";
    for ( int i =0; i<ans.size(); i++ ) {
        cout<< ans[i] <<" ";
    }




    return 0;
}