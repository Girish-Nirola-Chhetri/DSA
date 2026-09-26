#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node( int data ) {
            this-> data = data;
            this-> next = NULL;
        }
};

Node* startingLoopNode( Node* &head ) {
    if ( head == NULL || head -> next == NULL ) return NULL;

    Node* slow = head;
    Node* fast = head;

    while( fast != NULL && fast-> next != NULL ) {
        slow = slow -> next;
        fast = fast-> next -> next;

        if( slow == fast ) {
            break;
        }
    }

    if( fast == NULL  || fast-> next == NULL ) return NULL;
    
    slow = head;
    while( slow != fast ) {
        slow = slow-> next;
        fast = fast-> next;

    }

    return slow;

}


void removeLopp( Node* &head ) {
    if( head == NULL || head-> next == NULL ) return;

    Node* startNode = startingLoopNode( head );
    if( startNode == NULL ) return ;

    Node* temp = startNode;

    while ( temp -> next != startNode ) {
        temp = temp ->next;
    }

    temp -> next = NULL;

}