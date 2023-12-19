#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> haveVowelsStartEnd;
        for (string word : words) {
            haveVowelsStartEnd.push_back(isVowel(word[0]) && isVowel(word[word.size() - 1]));
        }
        for (int i = 1; i < words.size(); i++) {
            haveVowelsStartEnd[i] += haveVowelsStartEnd[i - 1];
        }
        for (auto query : queries) 
            ans.push_back(haveVowelsStartEnd[query[1]] - haveVowelsStartEnd[query[0] - 1]);
        return ans;
    }
};

int main() {
	vector<string> words;
	vector<vector<int>> queries;
	int wordsCount, queriesCount;
	cout << "Words count: ";
	cin >> wordsCount;
	cout << "Input words:" << endl;
	string word;
	for (int i = 0; i < wordsCount; i++) {
		cin >> word;
		words.push_back(word);
	}
	cout << "Queries count: ";
	cin >> queriesCount;
	cout << "Input queries:" << endl;
	int q1, q2;
	for (int i = 0; i < queriesCount; i++) {
		cin >> q1 >> q2;
		vector<int> query(2);
		query[0] = q1;
		query[1] = q2;
		queries.push_back(query);
	}
	Solution solution;
	vector<int> vowelsCount = solution.vowelStrings(words, queries);
	for (int v : vowelsCount) cout << v << ' ';
	cout << endl;
}
