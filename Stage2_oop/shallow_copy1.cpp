#include <iostream>


using namespace std;

class Shallow {
    int* data;

    public:
        Shallow(int d) {
            data = new int(d);
        }

        //problem: default copy constructor does shallow copy
        //Shallow(const Shallow& src) : data(src.data) {}

        ~Shallow() {
            delete data;
        }

        void print() {
            cout << *data << endl;
        }
};


int main() {
    Shallow obj1{10};
    Shallow obj2 = obj1; //shallow copy - both point to the same memory

    obj1.print();
    obj2.print();

    //deleting obj1 deletes the memory obj2 still points to
    //double delete in destructor - undefined behavior
    return 0;
}

/*
10
10
free(): double free detected in tcache 2
Aborted (core dumpe
*/
