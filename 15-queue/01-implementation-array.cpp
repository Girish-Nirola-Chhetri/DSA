#include<iostream>
using namespace std;

class Queue {
    int front, rear, size;
    int* arr;

    public:
        Queue(int size) {
            front = rear = -1;
            this -> size = size;
            arr = new int[size];
        }

        void enqueue( int data ) {
            if( rear >= size ) {
                cout<<"queue overflow"<<endl;
                return;

            }

            arr[++rear] = data;
            if( front == -1 )
                front++;
        }

        int dequeue() {
            if( rear == -1 ) {
                return -1;
            }

            int val = arr[front++];

            if( front > rear )  {
                front = rear = -1;
            }

            return val;
        }

        bool isEmpty() {
            if( rear == -1 ) return true;

            return false;
        }

        int getFront() {
            if( front == -1 ) return -1;
            return arr[front];
        }

        void print() {
            if( rear == -1 ) return ;
            for( int i = front; i<= rear; i++ ) {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
    
};

int main() {

    Queue q(10);
    q.enqueue(10);
    q.print();

    q.enqueue(12);
    q.enqueue(50);
    cout<<q.getFront()<<endl;
    cout<< q.isEmpty() <<endl;

    q.print();

    cout<< q.dequeue() <<endl;
    q.dequeue();
    q.dequeue();

    cout<< q.isEmpty() <<endl;


    q.print();


    return 0;
}