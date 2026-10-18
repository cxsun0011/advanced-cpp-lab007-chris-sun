#include "project/recursive_algorithms.h"

#include <stdexcept>
#include <utility>
#include <vector>

// TODO: Implement factorial recursively.
// Base case: n == 0 or n == 1.
// Recursive case: n * factorial(n - 1).
int factorial(int n) {
    if (n < 0)
        throw std::logic_error("Student implementation required: factorial");
    if (n==0||n==1)
        return 1;
    else 
        return n * factorial (n-1);
}

// TODO: Implement an iterative factorial comparison.
int factorialIterative(int n) {
   if (n < 0)
        throw std::logic_error("Student implementation required: factorial");
    int product = 1;
    while (n > 1) {
        product *= n;
        n--;
    }
    return product;

}

// TODO: Implement fibonacci recursively.
// Base case: fib(0) = 0, fib(1) = 1.
// Recursive case: fib(n) = fib(n - 1) + fib(n - 2).
int fibonacci(int n) {
   if (n < 0)
        throw std::logic_error("Student implementation required: fibonacci");
    if(n == 0)
        return 0;
    else if (n==1)
        return 1;
    else 
        return fibonacci(n-1) + fibonacci(n-2);
}

// TODO: Implement iterative fibonacci comparison.
int fibonacciIterative(int n) {
   if (n < 0)
        throw std::logic_error("Student implementation required: fibonacci");
    int prev2 = 0;
    int prev1 = 1;
    int current = 0;
    if(n==0)
        return 0;
    if (n==1)
        return 1;
    for (int i=1; i<n;i++) {
        current = prev2 + prev1;
        prev2 = prev1;
        prev1 = current;
    }
    return current;
}

// TODO: Implement recursive binary search on a sorted array.
// Base case: target not found or left > right.
// Recursive case: compare middle element and recurse on the appropriate half.
namespace {
int binarySearchRange(const std::vector<int>& array, int target,
                      std::size_t left, std::size_t right) {
    if (left >= right) {
        return -1;
    }

    const std::size_t middle = left + (right - left) / 2;
    if (array[middle] == target) {
        return static_cast<int>(middle);
    }
    if (target < array[middle]) {
        return binarySearchRange(array, target, left, middle);
    }
    return binarySearchRange(array, target, middle + 1, right);
}
}

int binarySearch(const std::vector<int>& array, int target) {
    return binarySearchRange(array, target, 0, array.size());
}

// TODO: Implement iterative binary search comparison.
int binarySearchIterative(const std::vector<int>& array, int target) {
    
    int left = 0;
    int right = array.size() - 1;
    while (left <= right) {
        int mid = (right + left)/2;
        if (array[mid] == target)
            return mid;
        else if (target > array[mid])
            left = mid + 1;
        else if (target < array[mid])
            right = mid - 1;
    }
    return -1;

}

namespace {
int arraySumFrom(const std::vector<int>& array, std::size_t index) {
    if (index == array.size()) {
        return 0;
    }

    return array[index] + arraySumFrom(array, index + 1);
}
}

// TODO: Implement recursive array sum.
// Base case: empty array.
// Recursive case: first element + arraySum(rest-of-array).
int arraySum(const std::vector<int>& array) {
    return arraySumFrom(array, 0);
}

// TODO: Implement iterative array sum comparison.
int arraySumIterative(const std::vector<int>& array) {
   
    int sum = 0;
    int size = array.size();
    for (int i=0; i < size; i++) {
        sum += array[i];
    }
    return sum;
}

void reverseArrayRange(std::vector<int>& array, std::size_t left, std::size_t right) {
    if (left >= right) {
        return;
    }

    std::swap(array[left], array[right]);
    reverseArrayRange(array, left + 1, right - 1);
}

// TODO: Implement recursive in-place reversal.
// Base case: size <= 1.
// Recursive case: swap first and last elements, then recurse on the remaining middle.
void reverseArray(std::vector<int>& array) {
    if (array.empty()) {
        return;
    }

    reverseArrayRange(array, 0, array.size() - 1);
}

// TODO: Implement iterative reverse comparison.
void reverseArrayIterative(std::vector<int>& array) {
    for (std::size_t left = 0; left < array.size() / 2; ++left) {
        std::swap(array[left], array[array.size() - 1 - left]);
    }
}
