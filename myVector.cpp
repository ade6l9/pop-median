// myVector.cpp
#include "myVector.hpp"
#include <iostream>
#include <vector>
#include <algorithm>

void vectorMedian(const std::vector<int> *instructions) {
    std::vector<int> data;
    std::vector<int> medians;

    for (int inst : *instructions) {
        if (inst != -1) { // Insert
            auto it = std::lower_bound(data.begin(), data.end(), inst);
            data.insert(it, inst);
        } else { // Pop median
            if (!data.empty()) {
                int medianIndex = (data.size() - 1) / 2;
                medians.push_back(data[medianIndex]);
                data.erase(data.begin() + medianIndex);
            }
        }
    }

    // Output medians
    for (int median : medians) {
        std::cout << median << " ";
    }
    std::cout << std::endl;
}
