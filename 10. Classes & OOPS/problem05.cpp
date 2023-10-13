#include <iostream>
#include <cstring>
using namespace std;

// inheritance in OOPS
class Human{

    public:

        int age;
        int height;
        void setdata(int age, int height){
            this->age = age;
            this->height = height;
        }

        void getdata(){
            cout << this->age << endl;
            cout << this->height << endl;
        }
};

// single inheritance
// we cant access private members of parent class
class Male1 : public Human{
    public:
        bool gamer = true;

        void speak(){
            cout << "speaking.. " << endl;
        }
};

// protected members can be access inside class and also ib child class
class Male2 : private Human{
    public:
        void speak(){
            cout << "speaking.. " << endl;
        }

        void getvalues(){
            this->setdata(1,3);
            this->getdata();
        }
};

// Multi level inheritance
class Animal{
    public:
        void speak(){
            cout << "Animal Sound" << endl ;
        }
};
class Dog : public Animal{
    public:
        void speakDog(){
            cout << "dog Barking" << endl ;
        }
};
class labra : public Dog{
    public:
        void speakLabra(){
            cout << "bho bho" << endl ;
        }
};

// multiple inheritance
class Alien : public Human, public Animal{
    void speakAlien(){
        cout << "Alien say kjsforegbveird" << endl;
    }
};

// hierarchical Inheritance
// hybrid Inheritance

int main(){   
    Male1 obj1;
    obj1.setdata(21,52);
    obj1.getdata();
    obj1.speak();

    Male2 obj2;
    // coz private cant be access cout << obj2.age;
    obj2.getvalues();
    return 0;
}