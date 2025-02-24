#include <stdio.h>
#include <stdbool.h>
#include "bn.h" 

#define MAX 101  

struct bn fib_cache[MAX];
bool cached[MAX] = {0};

void memofib(int n, struct bn* result) {
    if (n == 0) {
        bignum_from_int(result, 0);
        bignum_assign(&fib_cache[0], result);
        cached[n] = true;
        return;
    }
    if (n == 1 || n == 2) {
        bignum_from_int(result, 1);
        bignum_assign(&fib_cache[n], result);
        cached[n] = true;
        return;
    }

    // If value is cached return it
    if (cached[n]) {
        bignum_assign(result, &fib_cache[n]);
        return;
    }

    // Compute Fibonacci(n-1) + Fibonacci(n-2)
    struct bn fib_n1, fib_n2;
    memofib(n - 1, &fib_n1);
    memofib(n - 2, &fib_n2);
    bignum_add(&fib_n1, &fib_n2, result);

    // Cache the computed value
    bignum_assign(&fib_cache[n], result);
    cached[n] = true;
}

void tests() {
    printf("Run test\n");
    struct bn result;
    for (int i = 1; i <= 100; i++) {
        memofib(i, &result);
        char str[512];
        bignum_to_string(&result, str, sizeof(str));
        printf("Fibonacci %d = %s\n", i, str);
    }
}

int main() { 
    tests();
    return 0;
}