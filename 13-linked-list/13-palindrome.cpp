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



Node* getMid( Node* head ) {
    if( head == NULL || head -> next == NULL ) return head;

    Node* slow = head;
    Node* fast = head -> next;

    while( fast!= NULL && fast -> next != NULL ) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
}

void reverse( Node* &head ) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next = NULL;

    while ( curr !=NULL ) {
        next = curr -> next;
        curr-> next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool isPalindrome ( Node* &head ) {
    if( head == NULL || head -> next == NULL ) return true;

    Node* mid = getMid(head);

    reverse( mid-> next );

    Node* p = head;
    Node* q =  mid -> next;
    while ( q != NULL ) {
        if( p-> data != q-> data ) {
            reverse( mid -> next );
            return false;
        }

        p = p-> next;
        q = q-> next;
    }
    reverse( mid -> next );

    return true;
}






int main () {
    Node* head = NULL, *tail = NULL;

    insert( head, tail, 1 );
    insert( head, tail, 2 );
    insert( head, tail, 3 );
    insert( head, tail, 3 );
    insert( head, tail, 2 );
    insert( head, tail, 1 );
    // insert( head, tail, 60 );

    printList( head );

    bool val = isPalindrome( head );
    cout<< val<< endl;


    return 0;
}