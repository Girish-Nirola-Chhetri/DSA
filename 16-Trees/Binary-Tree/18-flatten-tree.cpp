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
    public:
    void flatten(TreeNode* root) {
        if ( !root ) return;

        TreeNode* curr = root;
        while( curr ) {
            if( curr -> left ) {
                TreeNode* pred  = curr-> left;
                while( pred-> right != NULL  ) 
                    pred =  pred -> right;
                
                pred -> right = curr -> right;
                curr-> right = curr-> left;
                curr -> left = NULL;

            } 
            // at this point curr -> right poits to cur -> left
            curr = curr-> right;
            
        }
    }
};