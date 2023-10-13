#include <iostream>
#include <cstring>
using namespace std;

// encapsulation in OOPS
// data/information hiding and member can ony acees by getter and setter
// this is known as fully encapsulate
class Student{
    string name;
    int age;

    public:
        void setdata(){
            this->age = 21;
            this->name = "vishal";
        }

        void getdata(){
            cout << this->name << endl;
            cout << this->age << endl;
        }
};

int main(){
    
    Student vishu;
    vishu.setdata();
    vishu.getdata();
    return 0;
}