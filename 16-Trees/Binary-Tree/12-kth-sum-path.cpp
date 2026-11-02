#include<iostream>
#include<vector>
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
    void solve( Node* root, const int& k, vector<int>& path, int& count ) {
        if( !root ) return ;
        
        path.push_back( root-> data);
        
        solve( root-> left, k, path, count );
        solve( root-> right, k, path, count );
        
        int n = path.size();
        int sum = 0;
        for( int i = n-1; i>=0; i-- ) {
            sum += path[i];
            if( sum == k ) 
                count++;
        }
        
        path.pop_back();
    }
    
  public:
    int countAllPaths(Node *root, int k ) {
        if( !root ) return -1;
        
        vector<int> path;
        int count = 0;
        
        solve( root, k, path, count );
        
        return count;
        
    }
};