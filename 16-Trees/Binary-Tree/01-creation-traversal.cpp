#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node ( int data ) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* buildBinaryTree( Node* root ) {
    int data;
    cout<<"enter data: ";
    cin>> data;
    if( data == -1 ) return NULL;

    root = new Node( data );
    
    cout<<"enter the data for left of "<< root-> data <<endl;
    root-> left = buildBinaryTree( root-> left );

    cout<<" enter the data for right of "<<root-> data <<endl;
    root-> right = buildBinaryTree( root-> right );

    return root;

}


void levelOrderTraversal( Node* root ) {
    if( root == NULL ) return;

    queue<Node*> q;

    q.push( root );

    while( !q.empty() ) {
        int size = q.size();
        while ( size > 0 ) {
            Node* temp = q.front();
            cout<<temp -> data <<" ";
            q.pop();

            if( temp -> left ) q.push( temp-> left );
            if( temp -> right ) q.push( temp-> right );

            size--;
        }
        cout<<endl;

    }
}

void preOrderTraversal(Node* root) {
    if( root == NULL ) return ;

    cout<< root -> data <<" ";

    preOrderTraversal( root -> left );
    preOrderTraversal( root -> right );

}

void inOrderTraversal( Node* root ) {
    if( root == NULL ) return;

    inOrderTraversal( root-> left);

    cout<< root -> data << " ";

    inOrderTraversal( root -> right );
}

void postOrderTraversal( Node* root ) {
    if ( root == NULL ) return ;
    
    postOrderTraversal( root ->left );
    postOrderTraversal( root-> right );
    cout<< root -> data <<" ";
}



int main () {

    Node* root = NULL;

    root = buildBinaryTree( root );

    cout<<"level order traversal: ";
    levelOrderTraversal( root );

    cout<< "preorder Traversal: ";
    preOrderTraversal( root );
    cout<<endl;

    cout<<"inorder Traversal: ";
    inOrderTraversal( root );
    cout<<endl;

    cout<<" postOrder Traversal: ";
    postOrderTraversal( root );
    cout<<endl;

    return 0;
}