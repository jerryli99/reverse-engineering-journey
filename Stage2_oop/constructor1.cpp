/*
Here we explore the calling sequence when we have inheritance in c++...
*/

#include <iostream>

class Base1 {
    public:
        Base1() {
            std::cout << "Base1 constructor\n";
        }
        ~Base1() {
            std::cout << "Base1 destructor\n";
        }
};

class Base2 {
    public: 
        Base2() {
            std::cout << "Base2 constructor\n";
        }

        ~Base2() {
            std::cout << "Base2 destructor\n";
        }
};

class Derived : public Base2, public Base1 {
    public:
        Derived() {
            std::cout << "Derived constructor\n";
        }

        ~Derived() {
            std::cout << "Derived destructor\n";
        }
};

int main() {
    Derived d;

    return 0;
}

/* 
What do you think will happen? What if we switch the inherit order of base1 and base2?

Base1 constructor
Base2 constructor
Derived constructor
Derived destructor
Base2 destructor
Base1 destructor

//---------------
Base2 constructor
Base1 constructor
Derived constructor
Derived destructor
Base1 destructor
Base2 destructor

*/

