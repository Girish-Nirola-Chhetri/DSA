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


void insert( Node* &head, int data) {
    Node* temp = new Node(data);

    if( head == NULL ) {
        head = temp;
        return;
    }

    Node* p = head;
    while ( p-> next != NULL ) {
        p = p-> next;
    }

    p-> next = temp;
}

void removeDuplicates( Node* &head ) {
    if ( head == NULL || head -> next == NULL ) return;

    Node* dummy = new Node(-1);
    dummy-> next = head;
    Node* curr = head;
    Node* prev = dummy;     // cant e null we may remove the head as well

    while ( curr-> next != NULL ) {
        if( curr-> data == curr-> next -> data ) {
            int dupVal = curr-> data;

            while( curr!= NULL && curr-> data == dupVal ){
                // Node* temp = curr;       // delete teh node as well free space
                curr = curr -> next;
                // delete temp;
            }
            prev-> next = curr;

        }else {
            prev = prev->next;
            curr = curr -> next;
        }
    }

    head = dummy -> next;
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
    insert(head, 1);
    insert(head, 1);
    insert(head, 3);
    // insert(head, 3);
    // insert(head, 4);
    // insert(head, 4);
    // insert(head, 5);

    printList( head );

    removeDuplicates( head );
    printList( head );

    return 0;
}
