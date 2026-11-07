#include<iostream>
#include<map>
#include<queue>>
using namespace std;


class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
  public:
  
    // map and return target node
    void mapChildToParent( Node*root, map<Node*, Node*> &mp, int &target, Node* &tarNode ) {
        if( !root ) return ;
        
        if( root-> left ) mp[root-> left ] = root;
        if( root-> right ) mp[root-> right] = root;
        
        if( root -> data == target ) tarNode = root;
        
        mapChildToParent( root-> left, mp, target, tarNode );
        mapChildToParent( root-> right, mp, target, tarNode );
        
    }
    
    int burnTree( Node* root, map<Node*, Node*> &mp ) {
        map<Node*, bool> visited;
        queue<Node*> q;
        visited[ root ] = true;
        q.push( root );
        
        int time = 0;
        
        while( !q.empty() ) {
            bool isPushed = false;

            int size = q.size();
            
            // burn all the neighbiorig and the icrease the trime
            for ( int i = 0; i<size; i++ ) {
                
                Node* temp = q.front();
                q.pop();

                
                if( temp-> left && !visited[temp->left] ) {
                    visited[temp-> left] = true;
                    q.push( temp-> left);
                    isPushed = true;
                }
                
                if( temp-> right && !visited[temp-> right ]) {
                    visited[temp-> right] = true;
                    q.push( temp-> right );
                    isPushed = true;
                    
                }
                
                if( mp[temp] && !visited[ mp[temp] ]) {
                    visited[ mp[temp] ] = true;
                    q.push( mp[temp] );
                    isPushed = true;
                }
            }
            
            if( isPushed ) time++;
            
        }
        
        return time;
    }
  
    int minTime(Node* root, int target) {
        map<Node*, Node*> mp;
        mp[root] = NULL;
        
        Node* tarNode = NULL;
        
        mapChildToParent( root, mp, target, tarNode );
        
        int ans = burnTree( tarNode, mp );
        return ans;
        
    }
};