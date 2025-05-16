#include <iostream>
#include <string>

int main() {
    std::string a = "abcdefg";
    std::string b = "hijklmnop";
    std::string&& c = (a + b);

    std::cout << c << std::endl;

    return 0;
}