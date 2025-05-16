/*
So now you may be thinking, so the difference between copy constructor, operator=, 
deep copy, shallow copy, reference copy? and also, if there is inheritance, 
or multiple inheritance, what will be copied?
*/

/*Basic copy constructor*/
#include <iostream>
#include <cstring>

using namespace std;

class MyString {
    char* str;
    int length;

    public:
        MyString(const char* s) {
            length = strlen(s);
            str = new char[length + 1];
            strcpy(str, s);
        }

        //copy constructor
        MyString(const MyString& source) {
            length = source.length;
            str = new char[length + 1];
            strcpy(str, source.str);
            std::cout << "Copy constructor here" << std::endl;
        }

        ~MyString() {
            delete[] str;
        }

        void print() {
            std::cout << str << std::endl;
        }
};

int main() {
    MyString s1{"hello"};
    MyString s2 = s1; //copy constructor called, Uhmm, what if i overload the operator= ?

    s1.print();
    s2.print();

    return 0;
}