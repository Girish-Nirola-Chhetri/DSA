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



Node* middle( Node* &head ) {
    if( head == NULL || head -> next == NULL ) {
        return head;
    }

    Node* p = head, *q = head;
    while ( p != NULL && p-> next != NULL ) {

        p = (p->next)-> next;
        q = q-> next;
    }

    return q;
}




int main () {
    Node* head = NULL, *tail = NULL;

    insert( head, tail, 10 );
    insert( head, tail, 20 );
    insert( head, tail, 30 );
    insert( head, tail, 40 );
    insert( head, tail, 50 );
    insert( head, tail, 60 );

    printList( head );

    Node* mid = middle( head );
    if( mid == NULL ) {
        cout<<"list is empty"<<endl;

    }else {
        cout<<"Middle: "<< mid->data<< endl;

    }


    return 0;
}