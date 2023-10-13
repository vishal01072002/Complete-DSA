#include <iostream>
using namespace std;

// basic of class
class Hero
{
    // access modifier 
    // default is private which can only acess inside the class
    // we can acess current object using this , which store address of current  object
    // we can access member using arrow -> operator on pointer

    int level = 69;
    public:
        int health;

        void setLevel(int n){
            // setter
            this->level = n;
        }

        void getLevel(){
            // getter
            cout << "level of hero is " << this->level << endl;
        }
};

class emptyClass{

};

int main(){
    Hero h1;
    emptyClass e;

    // size 1 for only track;
    cout << "size of empty class object " << sizeof(e) << endl;

    cout << "size of object " << sizeof(h1) << endl;

    // access element of class using . , -> (dot or arrow operator)
    h1.health = 100;
    cout << "value of health of hero " << h1.health << endl;

    h1.getLevel();
    h1.setLevel(669);
    h1.getLevel();

    // Hero h1; this is static allocation

    // dynamic allocation same work as pointer
    Hero *h2 = new Hero; 
    (*h2).getLevel();

    // arrow operator work on pointer
    h2->getLevel();
    return 0;
}