#include <iostream>
#include <cstring>
using namespace std;

// polymorphism

// 1. compile time polymorphism

// achive by 2 ways 

// a. function overloading

class A{
    public:
        void say(){
            cout<< "hello vishal" << endl;
        }
        void say(string name){
            cout<< "hello " << name << endl;
        }
        void say(int n){
            cout<< "hello vishal " << n << endl;
        }
        void say(int n,string s){
            cout<< "yo " << s << n << endl;
        }

        // change in return type not done function overloading  
        //int say(){
        //    cout<< "hello vishal with int" << endl;
        //    return 1;
        //}
};

// b. method overloading

class B{
    public:
        int a;

        void operator + (B obj){
            cout<< this->a - obj.a << endl;
        }

        void operator () (){
            cout<< "bracket overloaded " << this->a << endl;
        }
};

int main(){   

    A obj;
    obj.say();
    obj.say("lucifer");
    obj.say(1);
    obj.say(7,"lucifer");

    // it give error
    // obj.say();

    // operator overloading
    B obj1;
    B obj2;
    obj1.a = 10;
    obj2.a = 3;
    obj1 + obj2;
    obj2 + obj1;

    obj1();
    obj2();

    
    return 0;
}