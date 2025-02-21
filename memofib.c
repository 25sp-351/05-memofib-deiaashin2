#include <stdio.h>

#define MAX 1000  // Define the maximum size for memoization

long long fib_cache[MAX] = {0};

long long memofib(int n) {
    if (n == 0) {
        return 0;
    }

    // If value is in cache return it
    if (fib_cache[n] != 0) {
        return fib_cache[n];
    }

    // Compute n
    long long value;
    if (n == 1 || n == 2) {
        value = 1;
    } else {
        value = memofib(n - 1) + memofib(n - 2);
    }

    // Cache value and return
    fib_cache[n] = value;
    return value;
}

// Test cases
void run_tests() {
    printf("Running tests...\n");

    long long expected_fibs[MAX] = {
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34,
        55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
        6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229,
        832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986,
        102334155, 165580141, 267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049, 12586269025
    };

    // Run tests 0 to 50
    for (int i = 0; i <= 50; i++) {
        long long result = memofib(i);
        if (result == expected_fibs[i]) {
            printf("Test %d passed: %lld\n", i, result);
        } else {
            printf("Test %d FAILED: %lld (expected %lld)\n", i, result, expected_fibs[i]);
        }
    }
}

int main() {
    run_tests();
    return 0;
}