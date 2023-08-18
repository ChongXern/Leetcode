#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_letter_present_in_word(char letter, char *word) {
	int word_len = (int)strlen(word);
	int i = 0;
	while (i < word_len) {
		if(word[i] == letter) {
			return true;
		}
		i++;
	}
	return false;
}

bool are_two_words_similar(char *word1, char *word2) {
	int len1 = (int)strlen(word1);
	for (int i = 0; i < len1; i++) {
		if(!is_letter_present_in_word(word1[i], word2)) {
			return false;
		}
	}
	return true;
}

bool are_both_similar(char *word1, char *word2) {
	return (are_two_words_similar(word1, word2) && are_two_words_similar(word2, word1));
}

int similarPairs(char ** words, int wordsSize) {
	int counter = 0;
	for (int i = 0; i < wordsSize; i++) {
		for (int j = i + 1; j < wordsSize; j++) {
			if (are_both_similar(words[i], words[j])) {
				counter++;
			}
		}
	}
	return counter;
}

int main() {
	int wordsSize;
	printf("Input words size:\n");
	scanf("%i", &wordsSize);
	char words[wordsSize][100];
	printf("Input words:\n");
	for (int i = 0; i < wordsSize; i++) {
		scanf("%s", words[i]);
		getchar();
	}
	int countPairs = similarPairs((char**)words, wordsSize);
	printf("Number of similar pairs: %i\n", countPairs);
}
