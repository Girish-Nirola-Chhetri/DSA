#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};


class Solution {
    
    void leftPart( Node* root, vector<int>& ans ) {
        if( root == NULL ) return;
        if( !root -> left && !root-> right ) return;
        
        ans.push_back( root -> data );
        if( root-> left ) {
            leftPart( root->left, ans );
        }else {
            leftPart( root->right, ans );
        }
    }
    
    void leafPart( Node* root, vector<int>& ans ) {
        if( root == NULL ) return;
        if( !root-> left && !root-> right ) {
            ans.push_back( root-> data );
            return ;
        }
        
        leafPart( root->left , ans );
        leafPart( root-> right, ans );
    }
    
    void rightPart( Node* root, vector<int>& ans ) {
        if( root == NULL ) return;
        if( !root-> left && !root-> right ) return;
        
        if( root -> right ) 
            rightPart( root-> right, ans );
        else 
            rightPart( root-> left, ans );

        ans.push_back( root-> data );
    }
    
    
  public:
    vector<int> boundaryTraversal(Node *root) {
        if( !root ) return {};
        
        vector<int> ans;
        
        // 1: push root to ans
        ans.push_back( root -> data );
        
        //2: left part
        leftPart( root-> left , ans );
        
        //2: leat part
        leafPart( root-> left, ans  );
        leafPart( root-> right, ans );
        
        //3: right part
        rightPart( root-> right, ans );
        
        return ans;
    
    }
};