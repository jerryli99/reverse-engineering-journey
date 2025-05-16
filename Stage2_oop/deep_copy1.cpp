/* To solve the double free problem in shallow_copy1.cpp, we use deep copy*/
#include <iostream>

using namespace std;

class Deep {
    int* data;

    public:
        Deep(int d) {
            data = new int(d);
        }

        Deep(const Deep& source) {
            data = new int(*source.data);
        }

        ~Deep() {
            delete data;
        }

        void print() {
            cout << *data << endl;
        }
};

int main() {
    Deep obj1(20);
    Deep obj2 = obj1;

    obj1.print();
    obj2.print();

    return 0;
}