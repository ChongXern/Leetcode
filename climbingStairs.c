/**
 * https://leetcode.com/problems/climbing-stairs/description/
 * Math, Dynamic Programming, Memoization
 * Easy
 */
#include <stdio.h>

int climbStairs(int n){
    int first = 1;
    int second = 2;
    int next = 3;
    if (n < 4) {
        return n;
    } else {
    for (int i = 3; i < n; i++) {
        first = second;
        second = next;
        next = first + second;
    }
    return next;
    }
}

int main() {
	int n;
	printf("Input n:\n");
	scanf("%i", &n);
	printf("\n%i\n", climbStairs(n));
}
