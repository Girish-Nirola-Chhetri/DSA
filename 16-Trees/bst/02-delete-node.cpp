#include<iostream>
using namespace std;
#include<queue>


class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
    Node* getdeleteNode( Node*root, int &data ) {
        if( root == NULL ) return NULL;
        
        queue<Node*> q;
        q.push( root );
        while( !q.empty()  ) {
            Node* curr = q.front();
            q.pop();
            
            if ( curr -> data == data ) return curr;
            
            if( curr-> left ) 
                q.push( curr->left );
            if( curr-> right ) 
                q.push( curr-> right );
        }
        
        return NULL;
    }
    
  public:
  
    Node* getMin( Node* root ) {
        while( root -> left != NULL ) {
            root = root ->left;
        }
        return root;
    }
  
    Node* delNode(Node* root, int x) {
        if( !root ) return NULL;
        
        if( root -> data == x ) {
            // 1: no child 
            if( !root-> left && !root -> right ) {
                delete root;
                return NULL;
            }
            
            // only left child
            if( root-> left && !root -> right ) {
                Node* temp = root->left;
                delete root;
                
                return temp;
            }
            
            // only right child 
            if( !root-> left && root -> right ) {
                Node* temp = root -> right;
                delete root;
                return temp;
            }
            
            // if both child 
            if( root-> left && root -> right ) {
                Node* min = getMin( root-> right );
                
                root-> data = min -> data;
                root-> right =  delNode( root -> right , min-> data );
                
                return root;
            }
                
        }
        
        if( x < root-> data ) {
            root-> left =  delNode( root->left, x );
        }else {
            root -> right = delNode( root ->right, x);
        }
        
        return root;
        

    }
};