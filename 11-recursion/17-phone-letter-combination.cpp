#include<iostream>
#include<vector>
#include<string>
using namespace std;

void combinations( string& str, int index, string output, vector<string>& ans, string mapping[] ) {
    if( index >= str.length() ) {
        ans.push_back( output );
        return;
    }

    int digit = str[index] - '0';
    string digitValue = mapping[digit];

    for ( int i = 0; i< digitValue.length(); i++ ) {

        output.push_back( digitValue[i]);
        combinations( str, index+1, output, ans, mapping );
        output.pop_back();      // backtracking
    }
}



int main () {

    string s;
    cout<<"Enter a string: ";
    cin>> s;

    string output;
    vector<string> ans;

    string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "stuv", "wxyz"};

    
    combinations( s, 0, output, ans, mapping );

    cout<<"combinations are: ";
    for ( int i =0; i<ans.size(); i++ ) {
        cout<< ans[i] <<" ";
    }




    return 0;
}