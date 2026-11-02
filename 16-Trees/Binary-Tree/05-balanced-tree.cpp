#include<iostream>
#include<vector>
#include<queue>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    pair<bool, int> balancedTree( TreeNode* root ) {
        if( root == NULL ) {
            pair<bool, int> p = make_pair(true,0);
            return p;
        }

        pair<bool, int> left = balancedTree( root -> left );
        pair<bool, int> right = balancedTree( root -> right );

        if( left.first && right.first && abs( left.second - right.second ) <= 1 ) {
            return make_pair(true, max( left.second, right.second) + 1);
        } else {
            return make_pair( false, max( left.second, right.second) + 1);
        }
    }


public:
    bool isBalanced(TreeNode* root) {
        return balancedTree( root ).first;
    }
};