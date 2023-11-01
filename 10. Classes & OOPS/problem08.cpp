#include <iostream>
#include <cstring>
using namespace std;

// polymorphism

// 2. Run time polymorphism

// achive by function/method overRiding (early binding)

class animal{
    public:
        void speak(){
            cout<< "speaking " << endl;
        }
};
class dog :public animal{
    public:
        void speak(){
            cout<< "bark " << endl;
        }
};
class cat :public animal{
    public:
        void speak(){
            cout<< "mew mew \n" << endl;
        }
};

int main(){   

    animal a;
    dog d;
    cat c;
    a.speak();
    d.speak();
    c.speak();
    
    d.animal::speak();
    c.animal::speak();
    return 0;
}