#include <iostream>
using namespace std;

class Base {
public:
    int publicVar = 1;
protected:
    int protectedVar = 2;
private:
    int privateVar = 3;
};

// Public inheritance (default)
class PublicDerived : public Base {
    void access() {
        cout << publicVar;    // OK (remains public)
        cout << protectedVar; // OK (remains protected)
        // cout << privateVar; // Error: private in Base
    }
};

// Protected inheritance
class ProtectedDerived : protected Base {
    void access() {
        cout << publicVar;    // OK (becomes protected)
        cout << protectedVar; // OK (remains protected)
        // cout << privateVar; // Error: private in Base
    }
};

// Private inheritance
class PrivateDerived : private Base {
    void access() {
        cout << publicVar;    // OK (becomes private)
        cout << protectedVar; // OK (becomes private)
        // cout << privateVar; // Error: private in Base
    }
};

int main() {
    PublicDerived pub;
    cout << pub.publicVar;    // OK (public)
    // cout << pub.protectedVar; // Error: protected
    // cout << pub.privateVar;  // Error: private

    ProtectedDerived prot;
    // cout << prot.publicVar; // Error: now protected
    // cout << prot.protectedVar; // Error: protected

    PrivateDerived priv;
    // cout << priv.publicVar; // Error: now private
    // cout << priv.protectedVar; // Error: now private
}