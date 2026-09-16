#include<iostream>
#include<string>
using namespace std;

class Hero {
    private:
        string quirk;
        int age;

    public:
        string heroName;

    // setter and getter
    string getQuirk() {
        return quirk;

    }

    int getAge() {
        return age;

    }

    void setQUirk( string str ) {
        quirk = str;

    }

    void setAge( int a ) {
        age = a;
    }

};


int main () {

    // object => instance of class
    Hero Bakugo;

    Bakugo.heroName = "Deku";

    // accessing private data menbers using getter and setter

    Bakugo.setQUirk("Explosion");

    cout<< Bakugo.heroName <<endl;
    cout<< "Quirk : "<< Bakugo.getQuirk() <<endl;


    cout<< sizeof( Bakugo ) << endl;

    return 0;
}