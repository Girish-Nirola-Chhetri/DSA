#include<iostream>
using namespace std;

class Stack {
    public:
        int size, top;
        int* arr;

        Stack(int size) {
            this -> top = -1;
            this -> size = size;
            arr = new int[size];
        }

        void push(int data ) {
            if( !data ) return ;

            if( top == size-1 ) {
                cout<< "stack overflow"<<endl;
                return;
            }

            arr[ ++top ] = data;
        }

        int pop () {
            if( top == -1 ) {
                cout<<"stack underflow"<<endl;
            }else {
                int val = arr[top--];
                return val;
            }
        }

        bool isEmpty() {
            if ( top == -1 ) return true;

            return false;
        }

        int peek() {
            if( top >=0 && top < size) {
                return arr[top];

            }else {
                cout<<'stack is empty'<<endl;
            }
        }

        void print() {
            for ( int i = top; i>=0; i-- ) {
                cout<< arr[i--]<<" ";
            }
            cout<<endl;
        }
};


int main () {

    Stack s(10);
    s.push(10);
    s.print();
    int val = s.pop();
    cout<<"cal"<< val;
    s.pop();


    return 0;
}