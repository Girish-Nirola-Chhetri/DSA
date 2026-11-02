#include<iostream>
#include<vector>
#include<queue>>
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        if( root== nullptr ) return {};

        vector<vector<int>> result;

        queue<TreeNode*> q;
        q.push( root );

        while ( !q.empty() ) {
            int size = q.size();
            vector<int> currLevel;

            while ( size > 0 ) {
                TreeNode* temp = q.front();
                q.pop();

                currLevel.push_back( temp-> val );
                
                if( temp-> left ) q.push( temp-> left );
                if( temp-> right ) q.push( temp-> right );

                size--;
            }
            result.insert( result.begin(), currLevel );
        }


        return result;
    }
};