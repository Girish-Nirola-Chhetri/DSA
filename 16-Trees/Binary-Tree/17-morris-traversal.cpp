#include<iostream>
#include<vector>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
    
    Node* inorderPredecessor(Node* curr,  Node* root ) {
        while ( root -> right != NULL  && root-> right !=curr  ) {
            root =root-> right;
        }
        
        return root;
    }
  
    vector<int> morisTraversal(Node* root ) {
        vector<int> ans;
        Node* curr = root;
        while( curr ) {
            if( !curr-> left ) {
                ans.push_back( curr-> data );
                curr = curr-> right;
                
            }else {
                Node* pred = inorderPredecessor( curr, curr-> left);
                if( pred-> right == NULL  ) {
                    pred -> right = curr;
                    curr = curr-> left;
                    
                }else {
                    pred -> right = NULL;
                    ans.push_back( curr -> data );
                    curr = curr -> right ;
                }
            }
        }
        
        return ans;
    }
  
    vector<int> inOrder(Node* root) {
        if( !root ) return {};
        
        return morisTraversal( root );
        
    }
};

