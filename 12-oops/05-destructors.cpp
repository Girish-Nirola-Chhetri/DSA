#include<iostream>
using namespace std;

class Sample {
    public:
        int regd;
        char sec;

        Sample(int regd, char sec ) {
            this->regd = regd;
            this->sec = sec;
        }

        void print() {
            cout<<"regd: "<< regd << " " << " sec: "<< sec << endl;
        }


        ~Sample() {
            cout<<"Destructor called"<<endl;
        }
};


int main () {

    Sample A(10, 'A');
    Sample* B = new Sample(111, 'B');

    A.print();
    B->print();


    A = *B;

    A.print();      // copies B in A
    B->print();         


    // manually call destructor for dynamically allocated obj
    delete B;

    return 0;
}