/*
Liskov Subsitution Principle (LSP)

Subtypes must be substitutable for their base types without altering correctness.

Example: Ensuring Derived Classes Don't Break Base Class Behavior
*/

#include <iostream>

//Bad: Square inherits from Rectangle but violates LSP
class Rectangle {
protected:
    int width, height;

public:
    virtual void setWidth(int w) {
        this->width = w;
    }

    virtual void setHeight(int h) {
        height = h;
    }

    int area() const {
        return width * height;
    }
};