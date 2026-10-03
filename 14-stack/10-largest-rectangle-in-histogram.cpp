#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
private:
    vector<int> nextSmallestElementIndex( vector<int>& arr ) {
        int n  = arr.size();

        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for ( int i = n-1; i>=0 ; i-- ) {
            while( s.top() != -1 && arr[s.top()] >= arr[i] ) {
                s.pop();
            }

            ans[i] = s.top();
            s.push( i );
        }
        return ans;
    }

    vector<int> prevSmallestElementIndex( vector<int>& arr ) {
        int n = arr.size();

        vector<int> ans(n);
        stack<int> s;
        s.push(-1);

        for( int i = 0; i<n; i++ ) {
            while ( s.top() != -1 && arr[s.top()] >= arr[i] ) {
                s.pop();
            }

            ans[i] = s.top();
            s.push( i );
        }

        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallestElementIndex( heights );

        vector<int> prev(n);
        prev = prevSmallestElementIndex( heights );

        int area = INT16_MIN;
        for ( int i = 0; i< n; i++ ) {
            int l = heights[i];

            if( next[i] == -1 ) 
                next[i] = n;

            int b = next[i] - prev[i] -1;
            int newArea = l*b;
            area = max( area, newArea );
        }

        return area;
    }
};