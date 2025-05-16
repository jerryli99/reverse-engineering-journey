// /*Copy constructor with inheritance*/
// #include <iostream>
// using namespace std;

// class Base {
//     public:
//         Base() {
//             cout << "Base default constructor" << endl;
//         }

//         Base(const Base& ) {
//             cout << "Base copy constructor" << endl;
//         }
// };


// class Derived : public Base {
//     public:
//         Derived() {
//             cout << "Derived default constructor" << endl;
//         }

//         Derived(const Derived& d) : Base(d) { //explicite base copy
//             cout << "Derived copy constructor" << endl;
//         }
// };


// int main() {
//     Derived d1;
//     Derived d2 = d1; //calls both base and derived copy constructors
// }

/*
Base default constructor
Derived default constructor
Base copy constructor
Derived copy constructor
*/