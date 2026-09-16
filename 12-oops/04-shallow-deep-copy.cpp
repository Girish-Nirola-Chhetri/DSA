#include<iostream>
using namespace std;


class Sample {
    public:
        int *num;

        Sample() {
            num = new int;
            cout<<"a initialized"<<endl;
        }
};

class Demo {
    public:
        int *num;

        Demo() {
            num = new int;
            cout<<"a initialized"<<endl;
        }

        // copy contructor
        Demo( Demo& temp ) {
            num = new int;
            *num = *temp.num;
        }

};

int main () {

    Sample A;
    *A.num = 10;
    cout<< " num a addrrss: "<< A.num <<endl;
    cout<< " num a : "<< *A.num <<endl;

    Sample B = A;       // shallow copy
    cout<< " num B address: "<< B.num << endl;
    cout<< " num B : "<< *B.num << endl;

    *A.num = 12;

    cout<< " num a : "<< *A.num <<endl;
    cout<< " num B : "<< *B.num << endl;


    // deep copy
    Demo d1;
    *d1.num = 100;
    cout<<" num d1: "<< *d1.num <<endl;

    Demo d2 = d1;
    cout<<" num d2: "<< *d2.num <<endl;

    *d1.num =120;

    cout<<" num d1: "<< *d1.num <<endl;
    cout<<" num d2: "<< *d2.num <<endl; // no changes


    return 0;
}