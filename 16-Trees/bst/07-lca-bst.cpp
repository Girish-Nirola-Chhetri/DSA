#include <iostream>
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
    TreeNode* solve( TreeNode* root, int p, int q ) {
        if( !root ) return NULL;
        if( root-> val  == p || root-> val == q ) return root;

        if( root-> val <p && root-> val < q ) {
            return solve( root-> right, p, q );

        }else if( root-> val > p && root-> val > q  ) {
            return solve( root-> left, p, q );

        }else {
            return root;
        }

        return NULL;

    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if( !root ) return NULL;

        return solve( root, p-> val, q-> val );
    }
};