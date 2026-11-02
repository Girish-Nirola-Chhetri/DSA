#include<iostream>
#include<vector>
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
  public:
    vector<int> leftView(Node *root) {
        if( root == NULL ) return {};
        
        vector<int> ans;
        queue<Node*> q;
        q.push( root );
        
        while ( !q.empty() ) {
            int size = q.size();
            for( int i = 0; i<size; i++ ) {
                Node* curr = q.front();
                q.pop();
                
                if( curr-> left ) q.push( curr-> left );
                if( curr-> right ) q.push( curr-> right );
                
                if( i == 0 ) {
                    ans.push_back( curr-> data );
                }
            }
        }
        
        return ans;
        
    }
};