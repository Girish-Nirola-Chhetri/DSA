#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
  private:
    bool knows( int a, int b, vector<vector<int>>& mat ) {
        
        if( mat[a][b] == 1 ) return true;
        
        return false;
        
    }
    
    
    
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> s;
        int n = mat.size();
        if( n == 0 ) return -1;
        
        // push every person to stack
        for ( int i = 0; i<n; i++ ) {
            s.push(i);
        }
        
        // find potential candidate
        while ( s.size() > 1 ) {
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if ( knows(a,b, mat) ) {
                s.push(b);
                
            }else {
                s.push(a);
            }
            
        }
        int candidate = s.top();
        
        // check is celebrity or nor
        bool colCheck = true;
        for( int i = 0; i< n; i++ ) {
            if( mat[i][candidate] == 0) {
                colCheck = false;
                return -1;
            }
        }
        
        bool rowCheck = true;
        int zeroCount = 0;
        for( int i = 0; i< n; i++ ) {
            if( mat[candidate][i] == 0 )
                zeroCount++;
                
        }
        
        
        if( zeroCount != n-1 ) {
            rowCheck = false;
            return -1;
        }

        
        if( rowCheck && colCheck ) return candidate;
        
        
    }
};