/*
Open/Closed Principle (OCP)

software entities should be open for extension but closed for modification.

Example: Extending Shapes Without Modifying Existing Code
*/

#include <iostream>
#include <vector>

// //Bad: adding a new shape requires modifying the areaCalculator
// class Rectangle {
// public:
//     double width, height;
// };

// class Circle {
// public:
//     double radius;
// };

// class AreaCalculator {
// public:
//     double calculateTotalArea(std::vector<Rectangle>& rectangles, std::vector<Circle>& circles) {
//         double total = 0;
//         for (auto& rect : rectangles) {
//             total += rect.width * rect.height;
//         }

//         for (auto& circle : circles) {
//             total += 3.14 * circle.radius * circle.radius;
//         }
//         return total;
//     }
// };

//Good, uses polymorphism 
class Shape {
public:
    virtual double area() const = 0;
};

class Rectangle : public Shape {
public:
    double width, height;
    Rectangle(double w, double h) : width(w), height(h) {}
    double area() const override {
        return width * height;
    }
};

class Circle : public Shape {
public:
    double radius;
    Circle (double r) : radius(r) {};
    double area() const override {
        return 3.14 * radius * radius;
    }
};

class AreaCalculator {
public:
    double calculateTotalArea(const std::vector<Shape*>& shapes) {
        double total = 0;
        for (auto& shape : shapes) {
            total += shape->area();
        }

        return total;
    }
};

int main() {
    /*
    Bad approach: approach (violates OCP)
    std::vector<Rectangle> rects = {{2,3}, {4,5}};
    std::vector<Circle> circle = {{1}, {2}};
    AreaCalculator badCalc;
    std::cout << "Total Area (Bad): " << badCalc.calculateTotalArea(rects, circles) << std::endl;
    */

    //good approach:
    std::vector<Shape*> shapes;
    shapes.push_back(new Rectangle{2,3});
    shapes.push_back(new Rectangle{4,5});
    shapes.push_back(new Circle{1});
    shapes.push_back(new Circle{2});

    AreaCalculator goodCalc;
    std::cout << "Total Area (Good): " << goodCalc.calculateTotalArea(shapes) 
              << std::endl;

    //clean up
    for (auto& shape : shapes) delete shape;

    return 0;
}


// Why OCP?

// New shapes (e.g., Triangle) can be added without changing AreaCalculator.