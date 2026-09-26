#include <iostream>
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

Node* getMid( Node* &head ) {
    Node* slow = head;
    Node* fast = head -> next;

    while ( fast!= NULL && fast-> next != NULL ) {
        slow = slow-> next;
        fast = fast -> next-> next;
    }

    return slow;
}

Node* merge( Node* left, Node* right ) {
    if( left == NULL ) return right;
    if( right == NULL ) return left;

    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while( left != NULL && right != NULL ) {
        if( left -> data <= right -> data ) {
            temp -> next = left ;
            temp = left;
            left = left-> next;

        }else {
            temp -> next = right ;
            temp = right;
            right = right-> next;
        }
    }

    while ( left != NULL ) {
        temp -> next = left ;
        temp = left;
        left = left-> next;
    }

    while ( right != NULL ) {
        temp -> next = right ;
        temp = right;
        right = right-> next;
    }

    return dummy -> next;
}

Node* mergeSort(Node* head ) {
    if( head == NULL || head -> next == NULL ) return head;

    Node* mid = getMid( head );

    //left e 
    Node* left = head;
    Node* right = mid-> next;
    mid-> next = NULL;
    
    left = mergeSort( left );
    right = mergeSort( right );

    Node* ans=  merge( left, right );
    return ans;
}

void insert(Node* &head, int data ) {
    Node* temp = new Node( data );

    if( head == NULL ) {
        head = temp;
        return;
    }

    Node* p = head;
    while ( p-> next != NULL ) {
        p = p-> next;
    }
    p-> next = temp;
    p = temp;
}

void printList( Node* &head ) {
    Node* temp = head;

    while( temp != NULL ) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}


int main() {

    Node* head = NULL;
    insert( head, 10 );
    insert( head, 12);
    insert( head, 1);
    insert( head, 8);
    insert( head, 55);
    insert( head, 12);

    printList( head );

    Node* ans = mergeSort( head );

    printList( ans );


    return 0;
}