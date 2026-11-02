#include<iostream>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    
    pair<int, int> solve( Node* root ) {
        if( root == NULL ) return make_pair(0, 0);
        
        pair<int, int> left = solve( root-> left );
        pair<int, int> right = solve( root-> right );
        
        pair<int, int> ans;
        ans.first = left.second + right.second + root-> data;
        ans.second = max(left.first, left.second) + max( right.first, right.second );
        
        
        return ans;
    }
    
  public:
    int getMaxSum(Node *root) {
        if( !root ) return 0;
        
        pair<int, int> ans = solve( root );
        return max( ans.first, ans.second );
    
    }
};