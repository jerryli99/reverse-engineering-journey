#include <iostream>

using namespace std;

template<typename T>
class Box {
    T* content;

    public:
        Box(const T& value) : content(new T(value)) {}

        //copy constructor for template class
        Box(const Box& other) : content(new T(*other.content)) {}

        ~Box() {
            delete content;
        }

        T get() const {
            return *content;
        }
};

int main() {
    Box<int> intBox(42);
    Box<int> intBoxCopy = intBox;

    Box<string> strBox("Hello");
    Box<string> strBoxCopy = strBox;

    return 0;
}