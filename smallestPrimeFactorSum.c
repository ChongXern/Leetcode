/**
 * https://leetcode.com/problems/smallest-value-after-replacing-with-sum-of-prime-factors/
 * Math, Number Theory
 * Medium
 */
#include <stdio.h>
#include <stdbool.h>

bool is_prime(int x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

// Assume isn't prime
int sum_of_factors(int x) {
    int total = 0;
    int i = 2;
    while (!is_prime(x) && i * i <= x) {
        if (x % i == 0) {
            total += i;
            x /= i;
            i = 2;
        } else {
            i++;
        }
    }
    total += x;
    return total;
}

int smallestValue(int n){
    while (!is_prime(n) && n != sum_of_factors(n)) {
        n = sum_of_factors(n);
    }
    return n;
}

int main() {
	int n;
	printf("Input n:\n");
	scanf("%i", &n);
	printf("Smallest Value After Replacing With Sum of Prime Factors: %i\n", smallestValue(n));
}
