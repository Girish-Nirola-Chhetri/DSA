#include<iostream>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



class Solution {
    int solve( TreeNode* root, int &gmax ) {
        if( !root ) return 0;

        int left = max( 0, solve( root-> left, gmax ));
        int right = max( 0, solve( root-> right, gmax ));

        int both = left + right + root-> val;
        gmax = max( gmax, both );

        return root -> val + max( left, right );
    }


public:
    int maxPathSum(TreeNode* root) {
        if( !root ) return 0;
        int max = INT8_MIN;
        solve( root, max);

        return max;
    }
};