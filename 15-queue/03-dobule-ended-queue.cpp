#include<iostream>
using namespace std;

class Deque {
    int front, rear, size;
    int* arr;

    public:
    Deque( int size ) {
        front = rear = -1;
        this-> size = size;
        arr = new int[size];
    }

    void push_front( int data ) {
        if( (rear+1) % size == front ) return ;
        
        if( front == -1 ) {
            front = rear = 0;
            arr[front] = data;
            return;
        }

        if( front == 0 ) {
            front = size-1;
            arr[front] = data;
            return;
        }

        front = front -1;
        arr[front] = data;

    }

    void push_rear(int data) {
        if( (rear+1) % size == front ) return ;

        rear = ( rear+1 ) % size ;
        arr[ rear ] = data;

        if( front == -1 ) 
            front = 0;

    }


    int pop_front() {
        if( rear == -1 ) return -1;

        int val = arr[front];
        if( front == rear ) {
            front = rear = -1;
            return val;
        }

        front = ( front+1) % size ;
        return val;
    }


    int pop_rear() {
        if( rear == -1 ) return -1;

        int val = arr[rear];
        if( front == rear ) {
            front = rear = -1;
            return val;
        }

        rear = ( rear -1 )% size;
        return val;
    } 

    bool isEmpty() {
        if ( rear == -1 ) return true;
        return false;
    }

    int getFront() {
        if( isEmpty() ) return -1;
        return arr[front];
    }

    int getRear() {
        if( isEmpty() ) return -1;
        return arr[rear];
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

int main() {
    Deque dq(5);

    dq.push_rear(10);
    dq.push_rear(20);
    dq.push_rear(30);

    cout << "Deque: ";
    dq.print();

    dq.push_front(5);
    dq.push_front(1);

    cout << "After push_front: ";
    dq.print();

    dq.pop_front();

    cout << "After pop_front: ";
    dq.print();

    dq.pop_rear();

    cout << "After pop_rear: ";
    dq.print();

    dq.push_rear(40);
    dq.push_rear(50);

    cout << "After pushing 40 and 50: ";
    dq.print();

    cout << "Front: " << dq.getFront() << endl;
    cout << "Rear: " << dq.getRear() << endl;

    return 0;
}