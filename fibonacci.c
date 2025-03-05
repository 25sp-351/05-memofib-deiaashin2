#include "fibonacci.h"
#include <stdbool.h>

// Memoization storage
long long fibonacci_cache[MAX_CACHE_SIZE] = {0};
bool is_cached[MAX_CACHE_SIZE] = {false};

long long compute_fibonacci(int index) {
    if (index == 0) {
        return 0;
    }

    // Return cached value if already computed
    if (is_cached[index]) {
        return fibonacci_cache[index];
    }

    long long computed_value;
    if (index == 1 || index == 2) {
        computed_value = 1;
    } else {
        computed_value = compute_fibonacci(index - 1) + compute_fibonacci(index - 2);
    }

    // Cache the computed value
    fibonacci_cache[index] = computed_value;
    is_cached[index] = true;
    return computed_value;
}
