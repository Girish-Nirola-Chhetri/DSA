#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        queue<int> q;
        vector<int> ans;
        
        int n = arr.size();
        
        // push -ve elememts of ofrst window
        for( int i= 0; i<k; i++ ) {
            if( arr[i] < 0 ) {
                q.push(i);
            }
        }
        
        if( q.empty() ) 
            ans.push_back( 0 );
        else 
            ans.push_back( arr[q.front()] );
            
        
        for( int i = k; i<n; i++ ) {
            while( !q.empty() && ( i - q.front() >= k )) 
                q.pop();
                
            if ( arr[i] < 0 ) 
                q.push( i );
                
            
            if( q.empty() ) 
                ans.push_back( 0 );
            else 
                ans.push_back( arr[q.front()] );
        }
        
        return ans;
    }
};