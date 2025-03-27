#include <iostream>
#include "binary_search.h"

int main() {
    std::vector<int> data = {1,2,3,4,5,6,7,8,9,10, 11, 12, 13, 14};

    BinarySearch<int> bs(data);
    
    int target = 7;
    int result = bs.search(target);

    if (result != -1) {
        std::cout << "Element found at index: " << result << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }

    return 0;
}