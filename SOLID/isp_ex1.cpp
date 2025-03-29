/*
Interface Segregation Principle

Clients should not be forced to depend on interfaces they don't use

Example: Splitting a Bloated Interface
*/

#include <iostream>

//Bad: A single interface forcing unnecessary methods
// class Worker {
// public:
//     virtual void work() = 0;
//     virtual void eat() = 0;
// };

// class Human : public Worker {
// public:
//     void work() override {
//         std::cout << "Human working\n";
//     }

//     void eat() override {
//         std::cout << "Human eating\n";
//     }
// };

// class Robot : public Worker {
// public:
//     void work() override {
//         std::cout << "Robot working\n";
//     }

//     void eat() override {
//         //uhm, robots don't eat! Forced to implement here anywayss...
//     }
// };

// Good: Split into smaller interfaces
class Workable {
    public:
        virtual void work() = 0;
    };
    
    class Eatable {
    public:
        virtual void eat() = 0;
    };
    
    class Human : public Workable, public Eatable {
    public:
        void work() override { std::cout << "Human working\n"; }
        void eat() override { std::cout << "Human eating\n"; }
    };
    
    class Robot : public Workable {
    public:
        void work() override { std::cout << "Robot working\n"; }
    };
    
    int main() {
        // Bad approach (violates ISP)
        // Robot badRobot;
        // badRobot.work();
        // badRobot.eat(); // Doesn't make sense!
    
        // Good approach (follows ISP)
        Robot goodRobot;
        goodRobot.work(); // Only implements Workable
    
        Human human;
        human.work();
        human.eat();
    
        return 0;
    }