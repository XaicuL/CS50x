// binary_search

#include <iostream>
#include <vector>
#include <algorithm> // Required for binary_search

int main() {
    std::vector<int> data = {1, 3, 5, 7, 9, 11};
    int target = 7;

    if (std::binary_search(data.begin(), data.end(), target)) {
        std::cout << "Element found!" << std::endl;
    } else {
        std::cout << "Element not found." << std::endl;
    }
    return 0;
}

