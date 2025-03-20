#include <iostream>

using namespace std;

int main() {
    int num1 = 10;
    float num2 = 3.14;
    double num3 = num1 / num2;
    uint32_t num4 = static_cast<uint32_t>(num3);
    double num5 = num4;
    
    cout << num1 << " " << num2 << " " << num3 << " " << num4 << " " << num5;
    return (0);
}