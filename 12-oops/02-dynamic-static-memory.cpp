#include<iostream>
using namespace std;

class Student {
    public:
        string fullName;
        int regd;
        int age;

};

int main () {

    // statisc memory allcoation
    Student s1;

    s1.fullName = "Girish Nirola Chhtri";
    s1.regd = 410;
    s1.age = 21;

    cout<< s1.fullName << " " << s1.regd << " " << s1.age <<endl;

    // dynamic memory allocation
    Student *s2 = new Student;

    (*s2).fullName = "Prapti Dhakal";
    s2->age =  19;
    s2->regd = 111;

    cout<< s2->fullName << " " << s2->regd << " " << s2->age <<endl;



    return 0;
}