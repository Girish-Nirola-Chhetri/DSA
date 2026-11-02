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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if( !root ) return {};

        vector<vector<int>> ans;
        queue<TreeNode*> q;
        bool isLeftToRight = true;

        q.push( root  );
        while ( !q.empty() ) {
            int size = q.size();
            vector<int> res( size );

            for( int i = 0; i<size; i++ ) {
                TreeNode* curr = q.front();
                q.pop();

                int index = isLeftToRight ? i : size-i-1;
                res[index] = curr -> val;

                if( curr-> left ) q.push( curr-> left );
                if( curr -> right ) q.push( curr-> right );
            }
            isLeftToRight = !isLeftToRight;
            ans.push_back( res );
        }

        return ans;
    }
};