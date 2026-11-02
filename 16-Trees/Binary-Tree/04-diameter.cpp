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
    pair<int, int> findDiameter( TreeNode* root ) {
        if( !root ) {
            pair<int, int> p = make_pair( 0,0 );
            return p;
        };

        pair<int, int> left = findDiameter( root-> left );
        pair<int, int> right = findDiameter( root-> right );

        int opt1 = left.first;
        int opt2 = right.first;
        int opt3 = left.second + right.second ;
        
        pair<int, int> ans;
        ans.first = max(opt1, opt2, opt3);
        ans.second = max( left.second, right.second) + 1;
        return ans;
    }



public:
    int diameterOfBinaryTree(TreeNode* root) {
        return findDiameter( root ).first;
    }
};