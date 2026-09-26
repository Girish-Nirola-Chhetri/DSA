#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = INT8_MIN;
        int n = height.size();
        int s = 0, e = n-1;

        while ( s < e ) {
            int area = min(  height[s], height[e]) * ( e -s );
            if( maxArea < area ) maxArea = area;
            
            if( height[s] <= height[e] ) {
                s++;
            }else {
                e--;
            }
        }

        return maxArea;
    }
};