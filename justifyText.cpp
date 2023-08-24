/** 
 * https://leetcode.com/problems/text-justification/
 * Array, String, Simulation
 * Hard
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> output;
        vector<string> currWords;
        int currLetterCount = 0;
        int countSpace;
        for (int i = 0; i < words.size(); i++) {
            if (2 * currLetterCount + words[i].size() > maxWidth) {
                countSpace = (maxWidth - currLetterCount) / currWords.size();
				string space = "";
				for (int i = 0; i < countSpace; i++) {
					space += ' ';
				}
				string line = "";
				for (int i = 0; i < currWords.size() - 1; i++) {
					line += currWords[i];
					line += space;
				}
				line += currWords[currWords.size() - 1];
				output.push_back(line);
				currLetterCount = 0;
				currWords.clear();
				countSpace = 0;
            }
            currLetterCount += words[i].size();
            currWords.push_back(words[i]);
        }
		return output;
    }
};

vector<string> vectorFromArray(string* array, int size) {
	vector<string> vector;
	for (int i = 0; i < size; i++) {
		vector.push_back(array[i]);
	}
	return vector;
}

int main() {
	int size, maxWidth;
	cout << "Input size: ";
	cin >> size;
	string* wordsArr = new string[size];
	cout << "Input words:" << endl;
	string word;
	for (int i = 0; i < size; i++) {
		cin >> word;
		wordsArr[i] = word;
	}
	vector<string> words = vectorFromArray(wordsArr, size);
	cout << "Input max width: ";
	cin >> maxWidth;
	Solution solution;
	vector<string> justified = solution.fullJustify(words, maxWidth);
	for (string line : justified) {
		cout << line << endl;
	}
}
