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

    int solve( Node* root, int &k, int &i ) {
        if( !root ) return -1;
        
        int left = solve( root-> left, k, i);
        // if ans was is left subtree we return the ans 
        //this is early stopping
        if( left != -1 ) {
            return left;            // left as root-> data will upate data at each point
        }
        
        i++;
        if( i == k ) return root-> data;
        
        // if ans not in sub tree return right ( if ans exists returns ans else ans)
        return solve( root-> right, k, i);
    }
    
  public:
    int kthSmallest(Node *root, int k) {
        if( !root ) return -1;
        int i = 0;
        return solve( root, k, i );
        
    }
};