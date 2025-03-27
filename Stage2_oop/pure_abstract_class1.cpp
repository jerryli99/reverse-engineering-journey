#include <iostream>

//pure abstract class
class IAnimal {
public:
    virtual void MakeSound() = 0;
};

//base class
class Animal : public IAnimal {
public:
    virtual void MakeSound() override {
        std::cout << "Generic animal sound" << std::endl;
    }
};

//drived class
class Dog : public Animal {
public:
    void MakeSound() override {
        std::cout << "Bark!" << std::endl;
    }
};

//direct implementation of interface
class Cat : public IAnimal {
public:
    void MakeSound() override {
        std::cout << "Meow!" << std::endl;
    }
};

int main() {
    Animal* myAnimal = new Dog();
    myAnimal->MakeSound();

    IAnimal* myCat = new Cat();
    myCat->MakeSound();

    delete myAnimal;
    delete myCat;
    return 0;
}

// using System;

// // Interface (implicitly virtual)
// interface IAnimal {
//     void MakeSound(); // No 'virtual' needed (always virtual)
// }

// // Base class with virtual method
// class Animal : IAnimal {
//     public virtual void MakeSound() { // Explicit 'virtual'
//         Console.WriteLine("Generic animal sound");
//     }
// }

// // Derived class overriding behavior
// class Dog : Animal {
//     public override void MakeSound() { // 'override' required
//         Console.WriteLine("Bark!");
//     }
// }

// // Alternative: Direct interface implementation
// class Cat : IAnimal {
//     public void MakeSound() { // No 'override' (interface method)
//         Console.WriteLine("Meow!");
//     }
// }

// class Program {
//     static void Main() {
//         // Polymorphism via base class
//         Animal myAnimal = new Dog();
//         myAnimal.MakeSound(); // "Bark!" (virtual dispatch)

//         // Polymorphism via interface
//         IAnimal myCat = new Cat();
//         myCat.MakeSound(); // "Meow!" (interface dispatch)
//     }
// }