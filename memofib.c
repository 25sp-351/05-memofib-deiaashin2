#include <stdio.h>
#include <stdbool.h>

#define MAX 100  // Define the maximum size for memoization

long long fib_cache[MAX] = {0};
bool cached[MAX];

long long memofib(int n) {
    if (n == 0) {
        return 0;
    }

    // If value is in cache return it
    if (cached[n]) {
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
    cached[n] = true;
    return value;
}

// Test cases
void run_tests() {
    printf("Running tests...\n");

    long long expected_fibs[] = {
        0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181,
        6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269,
        2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986, 102334155, 165580141,
        267914296, 433494437, 701408733, 1134903170, 1836311903, 2971215073, 4807526976, 7778742049, 12586269025,
        20365011074, 32951280099, 53316291173, 86267571272, 139583862445, 225851433717, 365435296162, 591286729879,
        956722026041, 1548008755920, 2504730781961, 4053041472111, 6557772254072, 10670803756183, 17228576010255,
        27899379766438, 45127955776793, 73027335543231, 118555991520024, 191583327063255, 310139318583279,
        501722645646534, 811861964229813, 1312585602879347, 2124447567109160, 3437033169988507, 5561480737097667,
        8998513907086174, 14549944634173841, 23548458541260015, 38098303175433856, 61646761716693871, 99745064892127727,
        161391126208321598, 261136191100449325, 422527317308770923, 683663508409220248, 1108197827712997171, 1791861336122217420,
        2897799163835214591
    };

    // Run tests 0 to 60
    for (int i = 0; i <= 60; i++) {
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