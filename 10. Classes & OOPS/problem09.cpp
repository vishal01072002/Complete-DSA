#include <iostream>
#include <cstring>
using namespace std;

// polymorphism

// 2. Run time polymorphism

// achive by function/method overRiding (late binding / virtual function)

class animal{
    public:
        void speak(){
            cout<< "speaking " << endl;
        }
        virtual void say(){
            cout<< "saying " << endl;
        }
        // pure virtual
        //virtual void tell() = 0;
};

class dog : public animal{
    public:
        void speak(){
            cout<< "bark " << endl;
        }
        void say(){
            cout<< "dog saying " << endl;
        }
        void tell (){
            cout<< "telling" << endl;
        }
};

int main(){   

    animal *ptr1;
    animal *ptr2;
    animal a;
    dog d;
    
    ptr1 = &a;
    ptr2 = &d;

    ptr1->speak();
    ptr2->speak();

    ptr1->say();
    ptr2->say();
    
    // ptr1->tell(); 
    // pure virtual cant acess coz no defenation
    //d.tell();

    return 0;
}