#include<iostream>
#include<climits>
using namespace std;



class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Info {
public:
    int max;
    int min;
    bool isBST;
    int size;
};


class Solution {
    Info solve( Node* root, int &ans ) {
        if( !root ) return {INT_MIN, INT_MAX, true, 0};
        
        Info left = solve( root -> left, ans );
        Info right = solve( root -> right, ans );
        
        Info currNode;
        currNode.max = max( root-> data, max( left.max, right.max));
        currNode.min = min( root-> data, min( left.min, right.min));
        currNode.size = left.size + right.size + 1;
        
        if( left.isBST && right.isBST && root->data > left.max && root-> data < right.min ) {
            currNode.isBST = true;
        }else {
             currNode.isBST = false;
        }
        
        
        if( currNode.isBST ) 
            ans = max( ans, currNode.size );
        
        return currNode;
    }
    
    
    
  public:
    int largestBst(Node *root) {
        if( !root ) return 0;
        int ans = 0;
        
        solve(root, ans);
        
        return ans;
    }
};