#include<iostream>
#include<climits>
#include<vector>
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
    TreeNode* solve(  vector<int>& preorder,int &index, int min, int max ) {
        if( index>= preorder.size() ) return NULL;

        int val = preorder[index];
        if( val <min || val > max ) {
            return NULL;
        }

        index++;
        TreeNode* root = new TreeNode( val );
        root-> left = solve( preorder, index, min, val );
        root-> right = solve( preorder, index, val, max );

        return root;
    }


public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if( preorder.size() <=0 ) return NULL;
        int index = 0;

        return solve(  preorder,index, INT_MIN, INT_MAX );

    }
};