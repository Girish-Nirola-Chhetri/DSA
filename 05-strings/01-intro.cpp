#include<iostream>
using namespace std;

int main() {

    char name[10];

    // user input
    cout<<"enter name: ";
    cin>>name;              // will terminate or capture till space tab or neter 

    // display the char srray / string
    cout<<"name is : "<<name<<endl;

    name[4] = '\0';
    cout<<"name after inserting null: "<<name<<endl;


    return 0;
}