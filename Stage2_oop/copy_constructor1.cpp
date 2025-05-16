#include <iostream>

using namespace std;

class Wall {

    private:
        double length;
        double height;

    public:
        Wall(double len, double hgt) {
            length = len;
            height = hgt;
        }

        //copy constructor with a Wall object as parameter
        Wall(Wall& obj) {
            //init private variables
            cout << "I am in copy constructor...";
            length = obj.length;
            height = obj.height;
        }

        double calculateArea() {
            return length * height;
        }      
};


int main() {
    Wall wall(10.5, 8.6);

    //
    cout << "Area of wall: " << wall.calculateArea() << endl;

    //copy contents of wall to another object wall2
    Wall wall2 = wall;

    cout << "Area of Wall 2: " << wall2.calculateArea() << endl;

    return 0;
}