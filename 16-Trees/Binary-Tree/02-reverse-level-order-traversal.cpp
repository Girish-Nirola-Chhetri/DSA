#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node( int data ) {
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};


vector<int> reverseLevelOrderTraversal( Node* root ) {
    vector<int> result;
    vector<vector<int>> levels;

    queue<Node*> q;
    q.push( root );

    while( !q.empty() ) {
        int size = q.size();
        vector<int> currLevel;

        while( size > 0 ) {
            Node* temp = q.front();
            q.pop();

            currLevel.push_back( temp -> data );

            if( temp -> left ) q.push( temp-> left );
            if( temp -> right ) q.push( temp-> right );
            size--;

        }
        levels.push_back( currLevel );

    }

    // traverse levels form buttom
    for ( int i = levels.size() - 1; i>=0; i-- ) {
        for( int data: levels[i]) {
            result.push_back( data );
        }
    }

    return result;
}



int main () {

    Node* root = new Node( 10 );
    root-> left = new Node( 20 );
    root-> right = new Node( 30 );

    root-> left -> left = new Node( 40 );
    root-> right-> right = new Node( 50 );

    vector<int>res = reverseLevelOrderTraversal( root );
    for ( int val: res ) {
        cout<< val<< " ";
    }

    return 0;
}