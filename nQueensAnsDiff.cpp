// For N-Queens cuz too lazy to determine difference one by one
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
   vector<vector<string> > myAnswer, correctAnswer;
   vector<string> myAnswerVect, correctAnswerVect;
   string myAnswerStr, correctAnswerStr;
   int n;
   cout << "Input n: ";
   cin >> n;
   cout << "Input my answer: " << endl;
   int i = 0;
   while (cin >> myAnswerStr && myAnswerStr != "end") {
	  if (i == n) {
		 myAnswer.push_back(myAnswerVect);
		 myAnswerVect.clear();
		 i = 0;
	  }
	  myAnswerVect.push_back(myAnswerStr);
	  i++;
   }
   cout << "Input correct answer: " << endl;
   i = 0;
   while (cin >> correctAnswerStr && correctAnswerStr != "end") {
	  if (i == n) {
		 correctAnswer.push_back(correctAnswerVect);
		 correctAnswerVect.clear();
		 i = 0;
	  }
	  correctAnswerVect.push_back(correctAnswerStr);
	  i++;
   }
}
