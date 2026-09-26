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

void insertCircular( Node* &head, int data) {
    Node* temp = new Node(data);

    if( head == NULL ) {
        head = temp;
        temp-> next = head;
    
    }else {
        Node* p = head;
        while ( p-> next != head ) {
            p = p-> next;
        }

        p-> next = temp;
        temp -> next = head;
    }
}


bool hasCycle(Node* &head) {
    if( head == NULL || head -> next == NULL ) return false;

    Node* fast = head;
    Node* slow = head;

    while ( fast!= NULL && fast -> next != NULL ) {
        slow = slow -> next;
        fast = fast -> next -> next;

        if( slow == fast ) {
            return true;
        }
    }
    return false;
}





int main () {


    Node* head = NULL;
    Node* tail = NULL;
    insert( head,tail, 10);
    insert( head,tail, 20);
    insert( head,tail, 30);
    insert( head,tail, 40);
    printList( head );

    cout<< hasCycle( head )<< endl;

    Node* head2 = NULL;
    insertCircular( head2, 10);
    insertCircular( head2, 20);
    insertCircular( head2, 30);
    insertCircular( head2, 40);

    cout<< hasCycle( head2 )<< endl;






    return 0;
}