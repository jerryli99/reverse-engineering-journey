/*
So Is composition coupling if it means strong relationship?

Well, composition itself is not coupling, but how you use composition can lead to
either coupled or decoupled designs.

To clarify, 
Composition -> a design principle where a class has(contains) another class as a member.
Coupling -> refers to how dependent one class is on another

Composition can be
1. Tightly coupled (Bad) -> If a class directly instantiates and depends on a concrete implementation
2. Loosely coupled (Good) -> if a class depends on an abstraction (interface/abstract class)
and the concrete implementation is injected(dependency injection)

(Bad example)
class Engine {
public:
    void start() { std::cout << "Engine started!" << std::endl; }
};

class Car {
private:
    Engine engine;  // Tight coupling (depends on concrete Engine)
public:
    void startCar() {
        engine.start();  // Directly uses Engine
    }
};
Problems:

If you change Engine, Car might break.

Hard to test Car in isolation (cannot mock Engine).

Cannot swap Engine with a different implementation (e.g., ElectricEngine).


*/
#include <iostream>
#include <memory>
// Abstraction (decouples Car from Engine implementations)
class IEngine {
public:
    virtual ~IEngine() = default;
    virtual void start() = 0;
};

// Concrete implementation
class GasEngine : public IEngine {
public:
    void start() override { std::cout << "Gas Engine started!" << std::endl; }
};

// Another implementation (easy to swap)
class ElectricEngine : public IEngine {
public:
    void start() override { std::cout << "Electric Engine started!" << std::endl; }
};

// Car depends on abstraction (IEngine), not concrete class
class Car {
private:
    std::unique_ptr<IEngine> engine;  // Decoupled (uses interface)
public:
    Car(std::unique_ptr<IEngine> eng) : engine(std::move(eng)) {}  // Dependency Injection
    void startCar() {
        engine->start();  // Works with any IEngine implementation
    }
};

int main() {
    auto gasCar = Car(std::make_unique<GasEngine>());
    gasCar.startCar();  // "Gas Engine started!"

    auto electricCar = Car(std::make_unique<ElectricEngine>());
    electricCar.startCar();  // "Electric Engine started!"

    return 0;
}