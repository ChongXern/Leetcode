#include <stdio.h>
#include <string.h>

int romanToInt(char * s){
    int answer = 0;
    int len = strlen(s);
    int i = 0;
    while (i < len) {
        if(s[i] == 'I') {
            if (s[i + 1] == 'V') {
                answer += 4;
                i += 2;
            } else if (s[i+1] == 'X') {
                answer += 9;
                i += 2;
            } else {
                answer += 1;
                i += 1;
            }
        }
        else if (s[i] == 'X') {
            if (s[i+1] == 'L') {
                answer += 40;
                i += 2;
            } else if (s[i+1] == 'C') {
                answer += 90;
                i += 2;
            } else {
                answer += 10;
                i += 1;
            }
        }
        else if (s[i] == 'C') {
            if (s[i+1] == 'D') {
                answer += 400;
                i += 2;
            } else if (s[i+1] == 'M') {
                answer += 900;
                i += 2;
            } else {
                answer += 100;
                i += 1;
            }
        }
        else if (s[i] == 'V') {
            answer += 5;
            i++;
        }
        else if (s[i] == 'L') {
            answer += 50;
            i++;
        }
        else if (s[i] == 'D') {
            answer += 500;
            i++;
        } else {
            answer += 1000;
            i++;
        }
    }
    return answer;
}

int main() {
	char s[15];
	printf("Insert Roman numeral:\n");
	scanf("%s", s);
	printf("\nRoman: %s\n", s);
	int i = romanToInt(s);
	printf("Integer: %i\n", i);
}
