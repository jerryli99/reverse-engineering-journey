//a confusing concept, no clear definition? So I won't go deep.

/*
Aggregation is a weaker "whole-part" relationship where the part can exist independently
of the whole. The whole does not control the lifetime of the part.

The part can exist independently of the whole.
The part is typically passed to the whole from outside (via constructor or setter)
Represents a weak ownership relationship.

*/
#include <iostream>

class Wheel {
    public:
        void rotate() {
            std::cout << "Wheel rotating!\n";
        }
};

class Car {
    private:
        Wheel* wheels[4]; //aggregation here: Car need "wheels"
    
    public:
        Car(Wheel* w1, Wheel* w2, Wheel* w3, Wheel* w4) {
            wheels[0] = w1;
            wheels[1] = w2;
            wheels[2] = w3;
            wheels[3] = w4;
        }

        void drive() {
            for (int index = 0; index < 4; index++) {
                wheels[index]->rotate();
            }
            std::cout << "Car driving\n";
        }
};

int main() {
    Wheel w1, w2, w3, w4;
    Car car(&w1, &w2, &w3, &w4);
    car.drive();

    return 0;
}

/*
Wheel rotating!
Wheel rotating!
Wheel rotating!
Wheel rotating!
Car driving
*/