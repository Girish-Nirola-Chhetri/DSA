#include<iostream>>
#include<vector>
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
    void flatten(Node* root, Node* &head ) {
        if( !root ) return;
        
        flatten( root-> right , head );
        root-> right = head;
        head = root;
        
        flatten( root-> left, head );
    }
    
    Node* mergeTree( Node* head1, Node* head2 ) {
        Node* head = new Node( -1 );
        Node* temp = head;
        
        while( head1 != NULL && head2 != NULL ) {
            if( head1-> data < head2-> data ) {
                temp-> right = head1;
                head1 = head1 -> right;
            }else {
                temp -> right = head2;
                head2 = head2-> right;
            }
            temp = temp -> right;
        }
        
        while( head1!= NULL ) {
            temp -> right = head1;
            head1= head1-> right;
            temp = temp -> right;
        }
        
        while( head2!= NULL ) {
            temp -> right = head2;
            head2= head2-> right;
            temp = temp -> right;
        }
        
        Node* res = head-> right;
        delete head;
        
        return res;
    }
    
    int getSize(Node* head ) {
        int count = 0;
        while( head != NULL ) {
            count++;
            head = head -> right;
        }
        return count;
    }
    
    Node* createBST(Node* &head, int n ) {
        if( n<=0 || !head ) return NULL;
        
        Node* left = createBST( head, n/2 );
        Node* root = head;
        root-> left = left;
        
        head = root-> right;
        
        root-> right = createBST( head, n- n/2 -1 );
        
        return root;
    }
    
    void inorder( Node* root, vector<int> &ans ) {
        if( !root ) return ;
        
        inorder( root-> left, ans );
        ans.push_back( root-> data );
        
        inorder( root-> right, ans );
    }
    
    
  public:
    vector<int> merge(Node *r1, Node *r2) {
        Node* head1 = NULL;
        Node* head2 = NULL;
        
        flatten( r1, head1 );
        flatten( r2, head2 );
        
        Node* head = mergeTree( head1, head2 );
        int n = getSize( head );
        Node* root = createBST( head, n );
        
        vector<int> ans;
        inorder( root, ans );
        
        return ans;
        
    }
};