#include <iostream>
#include <cstring>
using namespace std;

// inheritance ambiguity in OOPS
class A{
    public:
        void say(){
            cout << "inside A" << endl;
        }
};
class B{
    public:
        void say(){
            cout << "inside B" << endl;
        }
};
class C: public A, public B{
    
};

int main(){   
    C obj1;
    
    // this will confuse compiler so it gives error
    // obj1.say();

    // to remove ambiguity we use scope resolution operator
    obj1.A::say();
    obj1.B::say();
    return 0;
}