#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
    
    void solve( Node* root, map<int, vector<int> >& mp, int dia ) {
        if( root == NULL ){
            return;
        }
        
        mp[dia].push_back( root-> data );
        
        solve( root-> left, mp, dia+1);
        solve( root-> right, mp, dia );
        
    }
    
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if ( root == NULL )return ans;
        
        map<int, vector<int> > mp;
        solve( root, mp, 0 );
        
        // for( const auto& [key, value] : mp ) {
        //     for( const auto& val : value ) {
        //         ans.push_back( val );
        //     }
        // }
        
        return ans;
    }
};


// using queue
class Solution {
    
  public:
    vector<int> diagonal(Node *root) {
        vector<int> ans;
        if( root == NULL ) return ans;
        
        queue<Node*> q;
        
        q.push(root);
        
        while ( !q.empty() ) {
            Node* curr = q.front();
            q.pop();
            
            while ( curr!= NULL ) {
                ans.push_back( curr-> data);
                
                if( curr-> left != NULL ) {
                    q.push( curr-> left );
                    
                }
                curr = curr-> right;
            }
        }
        
        return ans;
    }
};