#include<iostream>
using namespace std;

class CircularQueue {
    int front, rear,size;
    int* arr;

    public:
    CircularQueue( int size ) {
        this -> size = size;
        front = rear = -1;
        arr = new int( size );
    }

    void enqueue( int data ) {
        if( (rear+1) % size == front ){
            cout<< "overlfow"<<endl;
            return;
        }

        rear = (rear+1) % size;
        arr[rear] = data;

        if( front == -1 ) 
            front++;
    }

    int dequeue() {
        if( rear == -1 ) return -1;

        int val = arr[front];
        if( front == rear ) {
            front = rear = -1;
            return val;
        } 

        front = (front +1) % size;
        return val;
    }

    bool isEmpty() {
        if( rear == -1 ) return true;
        return false;
    }

    int getFirst() {
        if( isEmpty() ) return -1;
        
        return arr[ front ];
    }

    void print () {
        if( isEmpty() ) return;

        int i = front;
        while( true ) {
            cout<<arr[i]<<" ";
            if( i == rear ) break;

            i = ( i+1 )% size;
        }
        cout<<endl;
    }
};

int main () {

    CircularQueue q(4);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.dequeue();

    q.enqueue(70);
    q.enqueue(90);
    q.enqueue(100);

    q.print();
    


    return 0;
}