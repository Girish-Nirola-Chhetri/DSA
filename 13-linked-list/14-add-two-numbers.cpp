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


Node* addNum( Node* first, Node* second ) {
    if( first == NULL ) return second;
    if( second == NULL ) return first;

    reverse( first );
    reverse( second );

    Node* ansHead = NULL;
    Node* ansTail = NULL;

    int carry = 0;
    while ( first!= NULL || second!= NULL || carry!= 0 ) {
        int val1 = 0;
        if( first!= NULL ) 
            val1 = first-> data;
        
        int val2 = 0;
        if( second!= NULL )
            val2 = second-> data;

        int sum = val1 + val2 + carry;
        int digit = sum % 10;
        carry = sum / 10;

        insert( ansHead, ansTail, digit );
    
        if( first!= NULL ) 
            first = first-> next;

        if( second!= NULL )
            second = second -> next;
    }
    
    reverse( ansHead );

    return ansHead;
}





int main () {
    Node* firstHead = NULL, *firstTail = NULL;
    insert( firstHead, firstTail, 1);
    insert( firstHead, firstTail, 4);

    Node* secondHead = NULL, *secondTail = NULL;
    insert( secondHead, secondTail, 1);
    insert( secondHead, secondTail, 4);
    insert( secondHead, secondTail, 4);


    printList( firstHead );
    printList( secondHead );


    Node* ans = addNum( firstHead, secondHead );
    printList( ans );

    return 0;
}