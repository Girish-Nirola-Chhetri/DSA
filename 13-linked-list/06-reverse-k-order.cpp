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



void reverseK( Node* &head, int k ) {
    if( head == NULL || head-> next == NULL || k == 1 ) return;

    if( k<1 ) {
        cout<<"invalid k";
        return;
    }

    Node* curr = head;
    Node* prev =  NULL;
    Node* forward = NULL;
    Node* groupPrev = NULL;
    Node* groupStart = NULL;


    while ( curr != NULL ) {
        int count = 0;
        Node *p = curr;
        while( p != NULL && count < k ) {
            count ++;
            p= p->next;
        }
        
        if( count < k ) {
            break;
        }


        groupStart = curr;

        // reverser first k
        prev = NULL;
        for ( int i = 0; i<k ; i++ ) {
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }

        if( groupPrev == NULL ) {
            head = prev;
        }else {
            groupPrev-> next = prev;
        }


        groupStart-> next = curr;
        groupPrev = groupStart;

    }
}


// using recursion
Node* reverseKRecursion( Node* &head, int k ) {
    if( head == NULL ) return head;

    Node* curr = head;
    Node* next = NULL;
    Node* prev = NULL;
    int count = 0;

    while ( curr != NULL && count < k ) {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;

        count++;
    }

    // by this head pints to last ele of reversed sun ll and prev points to first ele of list and next points to the first ele of other part
    if( next != NULL ) {
        head -> next = reverseKRecursion( next, k);
    }

    return prev;
     
}




int main () {
    Node* head = NULL, *tail = NULL;

    insert( head, tail, 10 );
    insert( head, tail, 20 );
    insert( head, tail, 30 );
    insert( head, tail, 40 );
    // insert( head, tail, 50 );

    printList( head );

    Node* val = reverseKRecursion( head, 2);
    printList( val );

    // reverseK( head, 2 );
    // printList( head );

    


    return 0;
}