// main.cpp
#include <iostream>
#include <vector>
#include <chrono>
#include <string>
#include "StringData.h"

int linear_search(const std::vector<std::string>& words, const std::string& word) {
    for (size_t i = 0; i < words.size(); ++i) {
        if (words[i] == word) {
            return i;
        }
    }
    return -1;
}


int binary_search(const std::vector<std::string>& words, const std::string& word) {
    int low = 0;
    int high = words.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (words[mid] == word) {
            return mid;
        } else if (words[mid] < word) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    std::vector<std::string> dataset = getStringData();
    std::vector<std::string> things = {"not_here", "mzzzz", "aaaaa"};

    for (const std::string& element : things) {
        // Measure time for linear search
        auto start = std::chrono::system_clock::now();
        int result = linear_search(dataset, element);
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::cout << "Linear search for " << element << ": Index=" << result
                  << ", Time=" << duration.count() << " seconds" << std::endl;

        // Measure time for binary search
        start = std::chrono::system_clock::now();
        result = binary_search(dataset, element);
        end = std::chrono::system_clock::now();
        duration = end - start;
        std::cout << "Binary search for " << element << ": Index=" << result
                  << ", Time=" << duration.count() << " seconds" << std::endl;
    }

    return 0;
}