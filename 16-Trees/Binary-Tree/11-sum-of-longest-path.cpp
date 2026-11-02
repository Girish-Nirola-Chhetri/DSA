#include<iostream>
using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};


class Solution {
    void solve( Node* root, int& maxSum, int &maxLvl, int sum, int lvl ) {
        if( !root ) {
            if( lvl > maxLvl ) {
                maxSum = sum;
                maxLvl =lvl;
            } 
            if ( lvl == maxLvl ) {
                maxSum = max( maxSum, sum );
            }
            
            return ;
        }
        
        sum = sum + root-> data;
        
        solve( root->left, maxSum, maxLvl, sum, lvl+1);
        solve( root->right, maxSum, maxLvl, sum, lvl+1);
    }

  public:
    int sumOfLongRootToLeafPath(Node *root) {
        if( !root ) return -1;
        
        int maxSum = 0;
        int maxLvl = 0;
        
        int sum = 0, lvl = 0;
        
        solve( root, maxSum, maxLvl, sum, lvl );
        
        return maxSum;
        
        
    }
};