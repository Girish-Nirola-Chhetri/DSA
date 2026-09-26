#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;
        Node* prev;

        Node ( int data ) {
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

void insertAtHead(Node* &head, Node* &tail, int data ) {
    Node* new_node = new Node( data );

    if( head == NULL ) {
        head = tail = new_node;
        return;
    }

    new_node -> next = head;
    head-> prev = new_node;
    head = new_node;

}

void insertAtTail( Node* &head, Node* &tail, int data ) {
    Node* new_node = new Node( data );

    if( head == NULL ) {
        head = tail = new_node;
    }

    tail-> next = new_node;
    new_node -> prev = tail;
    tail = new_node;

}

void insertAtPosition( Node* &head, Node* &tail, int data, int position ) {
    if( position < 1 ) {
        cout<< "invalid position"<<endl;
        return;
    }

    if ( position == 1 ) {
        insertAtHead( head, tail , data );
        return ;
    }

    if( head == NULL  ) {
        cout<<"list is empty"<<endl;
        return;
    }

    Node* new_node = new Node( data );
    Node* p = head;
    for ( int i = 1; i< position -1 && p != NULL ; i++ ) {
        p = p -> next;
    }

    if( p == NULL ) {
        cout<< "invalid position"<<endl;
        return;
    }

    if( p-> next == NULL ) {
        insertAtTail( head, tail, data );
        return;
    }

    (p->next)-> prev = new_node;
    new_node-> next = p-> next;
    new_node -> prev = p;
    p-> next = new_node;

}


// delete 
void deleteHead(Node* &head, Node* &tail )  {
    if( head == NULL ) return;

    if( head == tail ) {
        head = tail = NULL;
        return;
    }

    Node* p = head;
    head = head-> next;
    head->prev = NULL;

    p-> next = NULL;
    delete p;
}

void deleteTail(Node* &head, Node* &tail ) {
    if( head == NULL ) return;

    if( head == tail ) {
        head = tail = NULL;
        return;
    }

    Node* p = tail;
    tail = tail -> prev;
    tail -> next = NULL;

    p-> prev = NULL;
    delete p;
}

void deleteBYPosition( Node* &head,Node* &tail, int pos ) {
    if ( head == NULL || pos <1  ) return;

    if( pos == 1 ) {
        deleteHead( head, tail );
        return;
    }

    Node* p = head, * q = NULL;
    int i = 1;
    while ( i< pos && p != NULL ) {
        q = p;
        p = p-> next;
        i++;
    }

    if( p == NULL ) return;

    if( p == tail ) {
        deleteTail( head, tail );
        return;
    }

    q -> next = p-> next;
    (p->next)->prev = q;

    p -> next = NULL;
    p -> prev = NULL;
    delete p;

}


void deleteByData( Node* &head, Node* &tail, int data ) {
    if( head == NULL ) return;

    if( head-> data == data ) {
        deleteHead( head, tail );
        return;
    }

    if( head == tail && head -> data != data ) {
        cout<<data << " does not exist on list"<< endl;
        return;
    }

    Node* p = head, *q= NULL;;
    
    while ( p!= NULL && p-> data != data ) {
        q = p;
        p = p-> next;
    }

    if (p == NULL) {
        cout << data << " does not exist on list" << endl;
        return;
    }

    if( p == tail ) {
        deleteTail( head, tail );
        return;
    }

    q -> next = p-> next;
    (p->next)->prev = q;

    p-> next = NULL;
    p-> prev = NULL;
    delete p;
}




void printList( Node* &head ) {
    Node* p = head;
    while ( p != NULL ) {
        cout<< p -> data << " <-> ";
        p = p-> next;
    }
    cout<< "NULL" << endl;
}



int main () {
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead( head , tail, 10);
    printList( head );

    insertAtTail( head, tail, 12);
    printList( head );

    insertAtPosition( head, tail , 14, 3 );
    printList( head );

    deleteHead( head, tail );
    printList( head );

    deleteTail( head, tail );
    printList( head );

    insertAtTail(head, tail, 34);
    insertAtHead(head, tail, 78);
    printList( head );


    deleteBYPosition( head, tail , 2);
    printList( head );

    insertAtPosition( head, tail , 14, 3 );
    printList( head );

    deleteByData( head, tail, 34);
    printList( head );

    return 0;
}