#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node( int data ) {
        this-> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* insertIntoBST ( Node* root, int data ) {
    if( root == NULL ) {
        root = new Node( data );
        return root;
    } 

    if( data < root-> data ) 
        root->left = insertIntoBST( root -> left, data  );
    else 
        root -> right = insertIntoBST( root-> right, data );

    return root;
}


void createBST( Node* &root ) {
    int data ;
    cin>> data;

    while( data != -1 ) {
        root = insertIntoBST( root, data );
        cin>> data;
    }
} 



bool searchBST( Node* root, int &data ) {
    if( root == NULL ) return false;

    if( root-> data == data ) return true;
    if( data < root -> data ) {
        return searchBST( root->left, data );

    }else {
        return searchBST( root-> right, data );

    }

}

Node* minNode( Node* root ) {
    if( !root ) return NULL;
    while( root-> left != NULL ) 
        root = root -> left;

    return root;
}

Node* maxNode( Node* root ) {
    if( !root ) return NULL;
    while ( root -> right ) 
        root = root -> right;

    return root;
}





void preOrderTraversal( Node* root ) {
    if( root == NULL ) return;

    cout<< root-> data <<" ";
    preOrderTraversal(  root -> left );
    preOrderTraversal( root-> right );
}

int main ( ) {

    Node* root = NULL;
    
    cout<<"enter elements to create BST: ";
    createBST( root );

    cout<<" preorder of BST: ";
    preOrderTraversal( root );



    return 0;
}