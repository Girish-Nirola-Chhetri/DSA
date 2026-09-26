#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node( int data ) {
            this->data = data;
            this->next = NULL;
        }
};

void insertHead( Node* &head, Node* &tail, int data ) {
    Node* temp = new Node(data);

    if( head == NULL ) {
        head = tail = temp;
    } else {
        temp->next = head;
        head = temp;
    }
}

void insertEnd( Node* &head, Node* &tail, int data) {
    Node* temp = new Node(data);

    if( head == NULL ) {
        head = tail = temp;
    } else {
        tail->next = temp;
        tail = temp;
    }
}

void insertMiddle( Node* &head, Node* &tail, int data, int position ) {

    if( position <= 0 ) return;

    if( position == 1 ) {
        insertHead(head, tail, data);
        return;
    }

    if( head == NULL ) return;

    Node* p = head;
    int i = 1;

    while( i < position - 1 && p->next != NULL ) {
        p = p->next;
        i++;
    }

    if( i < position - 1 ) return;

    if( p->next == NULL ) {
        insertEnd(head, tail, data);
        return;
    }

    Node* temp = new Node(data);

    temp->next = p->next;
    p->next = temp;
}


void deleteHead( Node* &head, Node* &tail ) {

    if( head == NULL ) return;

    Node* p = head;

    if( head == tail ) {
        head = tail = NULL;
    } else {
        head = head->next;
    }

    p-> next = NULL;
    delete p;
}

void deletePos( Node* &head, Node* &tail, int pos ) {

    if( head == NULL || pos <= 0 ) return;

    if( pos == 1 ) {
        deleteHead(head, tail);
        return;
    }

    Node* p = head;
    Node* q = NULL;

    int i = 1;

    while( i < pos && p != NULL ) {
        q = p;
        p = p->next;
        i++;
    }

    if( p == NULL ) return;

    q->next = p->next;

    if( p == tail ) {
        tail = q;
    }
    p-> next = NULL;
    delete p;
}

void deleteEnd( Node* &head, Node* &tail ) {

    if( head == NULL ) return;

    if( head == tail ) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node* p = head;

    while( p->next != tail ) {
        p = p->next;
    }

    delete tail;

    tail = p;
    tail->next = NULL;
}

void deleteByData( Node* &head, Node* &tail, int data ) {

    if( head == NULL ) {
        cout << "not found" << endl;
        return;
    }

    if( head->data == data ) {
        deleteHead(head, tail);
        return;
    }

    Node* p = head;
    Node* q = NULL;

    while( p != NULL && p->data != data ) {
        q = p;
        p = p->next;
    }

    if( p == NULL ) {
        cout << "not found" << endl;
    } else {
        q->next = p->next;

        if( p == tail ) {
            tail = q;
        }

        p-> next = NULL;
        delete p;
    }
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
    Node* tail = NULL;

    Node* N1 = new Node(10);
    head = N1;
    tail = N1;

    insertHead( head, tail, 12 );
    printList( head );

    cout << endl;

    insertHead( head, tail, 14 );
    printList( head );

    insertEnd( head, tail, 16 );
    printList( head );

    insertMiddle( head, tail, 20, 3);
    printList( head );

    deleteEnd( head, tail );
    printList( head );

    deleteHead( head, tail );
    printList( head );

    deletePos( head, tail, 1);
    printList( head );

    deleteByData( head, tail, 50 );
    printList( head );

    return 0;
}