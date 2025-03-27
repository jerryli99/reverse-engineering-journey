class Base {
public:
    virtual ~Base() { 
    // Destructor implementation
    }
};
    
class Derived : public Base {
public:
    ~Derived() override {
    // Destructor implementation
    }
};

int main() {
    Base* ptr = new Derived();
    delete ptr; // Calls Derived's destructor, then Base's destructor
    return 0;
}