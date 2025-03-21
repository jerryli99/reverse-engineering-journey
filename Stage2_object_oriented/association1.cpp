/*
Association is general relationship where one class is connected to another, but 
there is no ownership or lifetime dependency.

Key Characteristics:
The objects can exist independently
The relationship can be unidirectional or bidirectional
Represents a usage relationship

*/

#include <iostream>
#include <string>

//bidirectional relationship here:

class Teacher; //forward declaration, don't worry about it

class Student {
    public:
        void attendClass(Teacher* teacher) {
            std::cout << "Student is attending a class taught by the teacher\n";
        }
};

class Teacher {
    public:
        void teachClass(Student* student) {
            std::cout << "Teacher is teaching a class with the student.\n";
        }
};

int main() {
    Student student;
    Teacher teacher;

    student.attendClass(&teacher);
    teacher.teachClass(&student);
}

/*
Object Creation:
The Student and Teacher objects are created independently.

They interact with each other but do not control each other's lifetimes.

Use Cases:
Modeling relationships where objects interact but do not own each other (e.g., students and teachers).

Flexible relationships that can change over time.

*/