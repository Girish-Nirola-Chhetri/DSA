#include<iostream>
using namespace std;

class Human {
    public:
        int height;
        int weight;
        int age;

        int getAge() {
            return age;
        }
};

class Male: public Human {
    public:
        string color;

        void getData() {
            cout<<"Color: "<< color<<" ";
            cout<<"Age: "<< age<<" ";
            cout<<"Height: "<< height<<" ";
            cout<<"weight: "<< weight<<" ";
        }
};

int main () {

    Male obj1;
    obj1.color = "Black";
    obj1.age = 12;
    obj1.weight = 53;
    obj1.height = 157;


    obj1.getData();

    return 0;
}