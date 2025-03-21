//some extra information: https://medium.com/design-bootcamp/association-composition-and-aggregation-in-c-3ca70336e992

/*
A strong "whole-part" relationship where the lifetime of the part is tightly
coupled to the lifetime of the whole. If the whole is destroyed, the parts are 
also destroyed.

key characteristics:
The part cannot exist independently of the whole.
The part is typically created and destroyed inside the whole.
Represents a strong ownership relationship.

*/

#include <iostream>
#include <string>

class Engine {
    public:
        void start() {
            std::cout << "Engine started\n";
        }
        ~Engine() {
            std::cout << "Calling Engine Destructor\n";
        }
};

class Car {
    private:
        Engine engine; //composition: since car owns the engine
    public:
        // Car() : engine() {}
        ~Car() {
            std::cout << "Calling Car destructor\n";
        }

        void start() {
            engine.start();
            std::cout << "Car started\n";
        }
};

//question: wait, so if the code works, where is the object created? Is this how the
//compiler works by default of creating object (so no explicit code doing this)? Uhmm

int main() {
    Car car;
    car.start();
    return 0;
}

/*
output:
Engine started
Car started
Calling Car destructor
Calling Engine Destructor

So the Engine object is created when the Car object is created (in the constructor)
The Engine object is destroyed when the Car object is destroyed.

*/