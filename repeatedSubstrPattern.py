class Solution:
    def divideString(self, s: str, num: int, size: int) -> bool:
        first_pivot = int(size / num)
        substring = s[0 : first_pivot]
        # print(substring)
        new_pivot = first_pivot
        while new_pivot + first_pivot <= size:
            new_substring = s[new_pivot : new_pivot + first_pivot]
            # print(new_substring)
            if new_substring != substring:
                return False
            new_pivot += first_pivot
        return True

    def repeatedSubstringPattern(self, s: str) -> bool:
        size = len(s)
        for i in range(2, size + 1):
            if size % i == 0 and self.divideString(s, i, size):
                return True
        return False

s = input("Input string: ")
solution = Solution()

if (solution.repeatedSubstringPattern(s)):
    print(f'{s} has a repeated substring pattern')
else:
    print(f'{s} does not have a repeated substring pattern')
