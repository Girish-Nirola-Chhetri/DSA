#include<iostream>
using namespace std;

class Student {

    string name;
    int regd;

    public:
    // no parameter constructor
    Student() {
        cout<<"non parameterized constructor invoked "<<endl;
    }

    // parameterized constrctor
    Student( string name, int regd ) {
        this -> name = name;
        ( *this ).regd = regd;
        cout<< "parameterized constructor invoked"<<endl;
    }


    // copy constructor
    Student ( const Student &temp ) {
        this->regd = temp.regd;
    }
    
    void print() {
        cout<<"Name: "<< name << " Regd: "<< regd <<endl;
    }

};


int main () {
    Student s1;
    s1.print();

    Student s2( "girish", 410 );
    s2.print();


    // copy contructor
    Student s3( s2);     // default copy constructor if no copy contructor has created
    s3.print();


    
    return 0;
}