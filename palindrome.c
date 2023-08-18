/**
 * https://leetcode.com/problems/palindrome-number/description/
 * Math
 * Easy
 */

#include <stdio.h>
#include <stdbool.h>

long length_of_num(long x) {
  if (x < 10) {
    return 1;
  }
  return 1 + length_of_num(x / 10);
}

long power_ten(long x) {
  if (x == 0) {
    return 1;
  }
  return 10 * power_ten(x - 1);
}

long isolate_number(int x, long pos) {
  x %= power_ten(pos+1);
  x /= power_ten(pos);
  return x;
}

bool isPalindrome(int x){
    if (x < 0) {
        return false;
    }
  bool flag = true;
  long length = length_of_num((long)x);
  long half = length / 2;
  for (long i = 0; flag && i <= half - 1; i++) {
    if(isolate_number(x, i) != isolate_number(x, length - 1 - i)) {
      flag = false;
    }
  }
  return flag;
}

int main() {
	int n;
	printf("Enter integer:\n");
	scanf("%i", &n);
	if (isPalindrome(n)) {
		printf("%i is a palindrome\n", n);
	} else {
		printf("%i is not a palindrome\n", n);
	}
}
