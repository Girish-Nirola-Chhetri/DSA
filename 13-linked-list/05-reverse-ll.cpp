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

void printList( Node* &head ) {
    Node* temp = head;

    while( temp != NULL ) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}


void insert( Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);

    if( head == NULL ) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}


void reverse_iteratively( Node* &head ) {
    Node* prev = NULL, *curr = head, *forward = NULL;

    while ( curr != NULL ) {
        forward = curr->next;
        curr-> next = prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void reverse_recursively( Node* &head, Node* &curr, Node* &prev ) {

    if( curr == NULL ) {
        head =  prev;
        return;
    }

    Node* forward = curr->next;
    curr-> next = prev;
    reverse_recursively( head, forward, curr );
}



int main () {
    Node* head = NULL, *tail = NULL;

    insert( head, tail, 10 );
    insert( head, tail, 20 );
    insert( head, tail, 30 );
    insert( head, tail, 40 );

    printList( head );

    reverse_iteratively( head );
    printList( head );

    Node* curr = head;
    Node* prev = NULL;

    reverse_recursively( head, curr, prev );
    printList( head );

    return 0;
}