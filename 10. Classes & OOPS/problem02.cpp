#include <iostream>
#include <cstring>
using namespace std;

// Constructor & Destructor of class
class Hero
{
    // access modifier 
    // default is private which can only acess inside the class
    // we can acess current object using this , which store address of current  object
    // we can access member using arrow -> operator on pointer

    int level = 69;
    public:
        char *name;
        int health;

        // when we make our constructor previous constuctor will be deleted
        Hero(){
            cout << "Constructor is called " << endl ;
            name = new char[100];
        } 

        // parameterized Constructor
        Hero(int health){
            cout << "Parameterized Constructor is called " << endl ;
            this->health = health;
        }

        // copy Constructor
        // if we not call by reference it send copy which again call that copy constructor and it will be in infinite loop
        
        /*
        copy constructor
        Hero(Hero &obj){
            cout << "Copy Constructor is called " << endl ;
            this->health = obj.health;
            this->level = obj.level;
        }
        */       
        
        // deep copy constructor
        Hero(Hero &obj){
            cout << "deep Copy Constructor is called " << endl ;
            char *temp = new char[(strlen(obj.name)) + 1];
            strcpy(temp,obj.name);
            this->name = temp;
            this->health = obj.health;
            this->level = obj.level;
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

        void setName(char *name){
            this->name = name;
        }

        void getName(){
            cout<<"name is " << this->name << endl;
        }

        // destructor
        ~Hero(){
            cout << "destructor is called " << endl ;
        }
};

int main(){

    // when objec is created constructor is called like h2.Hero();

    /*
    Hero h1(1); 
    Hero *h2 = new Hero(10);
    cout << "health of hero " << h2->health << endl; 
    // h2->getLevel();

    // copy constructor
    // Hero b(12);
    Hero a(*h2);
    a.getLevel();
    */

    cout<<endl<<endl;
    Hero *x = new Hero;
    char name[10] = "vishal";
    x->setName(name);
    x->getName();

    // default copy constructor do shallow copy , user define do deep copy
    // by use of default copy constructor
    Hero *y = new Hero(*x);
    y->getName();

    // update value of x and we see shallow copy
    // it copy the addres of name for all object so if one obj change other will also change
    x->name[0] = 'L';
    x->getName();
    y->getName();


    // destructor
    // for static allocated memory destructor is called automatically
    // for dynamic allocated memory we have to call it mannualy using delete 
    Hero vishu;
    delete x;
    return 0;
}