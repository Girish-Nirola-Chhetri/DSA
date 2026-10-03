// implement stack using ll
#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node( int data ) {
            this -> data = data;
            this -> next = NULL;
        }
};

class Stack {
    public:
        Node* top;

        Stack() {
            top = NULL;
        }

        void push( int data ) {
            Node* newNode = new Node( data );
            if( top == NULL ) {
                top = newNode;

            }else {
                newNode -> next = top;
                top = newNode;
            }
        }

        int pop () {
            if( top == NULL ) {
                cout<<"stack underflow"<<endl;
                return -1;
            }
            Node* temp = top;

            int val = temp -> data;
            top = top -> next;

            delete temp;

            return val;
            
        }

        bool isEmpty() {
            if( top == NULL ) return true;
            return false;
        }

        int peek() {
            if( top == NULL ){
                cout<<"stack is empty"<<endl;
                return -1;

            }
            return top -> data;
            
        }

        void print() {
            Node* p = top;
            while ( p != NULL ) {
                cout<< p-> data <<" ";
                p = p-> next;
            }
            cout<<endl;
        }

};

int main() {

    Stack s;
    s.push(10);
    s.push(20);
    s.print();

    cout<<"popped val: " <<s.pop()<<endl;

    s.print();

    cout<< "curr val"<< s.peek()<<endl;
    cout<<"is empty: "<< s.isEmpty()<<endl;


    s.pop();
    s.pop();

    
    return 0;
}

