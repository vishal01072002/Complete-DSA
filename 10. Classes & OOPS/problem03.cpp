#include <iostream>
#include <cstring>
using namespace std;

// all about Static of class
class Hero
{
    // To access static member no need to create object 
    // we can access using scope resulation operator (::)
    // static do not have this keyword 
    int level = 69;
    public:
        static int duration;
        int health = 10;

        // when we make our constructor previous constuctor will be deleted
        Hero(){
            cout << "Constructor is called " << endl ;
        } 

        // parameterized Constructor
        Hero(int health){
            cout << "Parameterized Constructor is called " << endl ;
            this->health = health;
        }

        // copy constructor
        Hero(Hero &obj){
            cout << "Copy Constructor is called " << endl ;
            this->health = obj.health;
            this->level = obj.level;
        }
              
        // static fun can only access static member and not have this
        static int time(){
            // cout << this->health;
            cout << duration ;
            return duration;
        }

        void setLevel(int n){
            // setter
            this->level = n;
        }

        void getLevel(){
            // getter
            cout << "health of hero is " << this->health << endl;
            cout << "level of hero is " << this->level << endl;
        }

};

// Inititalization of static variable
int Hero :: duration = 70; 

int main(){
    Hero a;
    cout << Hero :: duration << endl; 
    cout << a.duration << endl; 

    // non static can change and access static variables
    Hero b;
    b.duration = 10;
    cout << b.duration << endl; 
    cout << a.duration << endl; 
    return 0;
}