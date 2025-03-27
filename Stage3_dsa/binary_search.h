#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

template <typename T>
class BinarySearch {
public:
    BinarySearch(const std::vector<T>& data) : data_(data) {}

    /**
     * If element found, return index of the element; else, return -1 for not found
     */
    int search(const T& target) {
        int left = 0;
        int right = data_.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (data_[mid] == target) {
                return mid;
            } else if (data_[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }

private:
    std::vector<T> data_;
};

#endif
