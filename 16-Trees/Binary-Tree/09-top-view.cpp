#include<iostream>
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
        left = nullptr;
        right = nullptr;
    }
};

class Solution {
  public:
    vector<int> topView(Node *root) {
        if( root == NULL ) return {};
        
        // hd, data
        // for a particular hd store on;ly first ele 
        map<int, int> mp;
        queue<pair<Node*, int> > q;
        
        q.push( make_pair(root, 0));
        while( !q.empty() ) {
            pair<Node*, int> curr = q.front();
            q.pop();
            
            // for btton view no ned to check just eep inserting
            if( (mp.find(curr.second) == mp.end())){
                mp[curr.second] = curr.first -> data;
            }
            
            if( curr.first -> left ) {
                q.push( make_pair(curr.first -> left, curr.second-1));
            }
            
            if( curr.first -> right ) {
                q.push( make_pair(curr.first -> right, curr.second+1));
            }
            
        }
        
        vector<int> ans;
        
        // for ( const auto& [key, val] : mp ) {
        //     ans.push_back( val );
        // }
        
        return ans;
    }
};