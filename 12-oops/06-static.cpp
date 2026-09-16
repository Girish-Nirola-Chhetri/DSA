#include<iostream>
using namespace std;

class Student {
    public:
        static int count;
        string* name;
        int regd;

        Student( string name, int regd ) {
            this->name = new string(name);
            this-> regd = regd;

            count++;
        }

        static void printCount() {
            cout<<"Count: "<< count <<endl;
        }
};

int Student::count = 0;

int main () {

    Student s1( "girish", 410 );
    Student s2( "prapti", 111 );
    cout<<"Count: "<< Student::count <<endl;   

    // accessing using object
    cout<< "s1 Count: "<< s1.count <<endl;


    // static fuctions
    Student::printCount();

    return 0;
}